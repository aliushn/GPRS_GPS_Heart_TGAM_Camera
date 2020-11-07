#include "mywidget.h"
#include "ui_mywidget.h"
#include "QMessageBox"
#include <QDebug>
#include <QTextCodec>

/*-------------------------------打开蓝牙设备---------------------------------------*/
void  MyWidget::on_openMyBlue_clicked()
{
    ui->openMyBlue->setEnabled(false);          // 打开蓝牙不可用
    ui->closeMyBlue->setEnabled(true);          //关闭蓝牙可用
    localDevice->powerOn();     // 将设备返回hostMode()状态后，如果关闭电源，则为设备供电
    discoveryAgent->start();    //开始搜索附近蓝牙设备
}

/*-------------------关闭蓝牙----------------------------------*/
void  MyWidget::on_closeMyBlue_clicked()
{
    ui->openMyBlue->setEnabled(true);          // 打开蓝牙不可用
    ui->closeMyBlue->setEnabled(false);          //关闭蓝牙可用
    socket->disconnectFromService();            //停止接收数据
    localDevice->setHostMode(QBluetoothLocalDevice::HostPoweredOff);//将此本地蓝牙设备的主机模式设置为关闭模式
}

/* ----------------------------在List上显示查找到的蓝牙设备-------------------------------- */
void MyWidget::addBlueToothDevicesToList(const QBluetoothDeviceInfo &info)
{
    QString label = QString("%1 %2").arg(info.address().toString()).arg(info.name());
    //%1为蓝牙设备的地址，%2为蓝牙设备的名字
    QList<QListWidgetItem *> items = ui->list->findItems(label, Qt::MatchExactly);

    if (items.empty()) {
        QListWidgetItem *item = new QListWidgetItem(label);
        QBluetoothLocalDevice::Pairing pairingStatus = localDevice->pairingStatus(info.address());

 /* 蓝牙状态pairingStatus，Pairing枚举类型 0:Unpaired没配对 1:Paired配对但没授权 2:AuthorizedPaired配对且授权 */
        if (pairingStatus == QBluetoothLocalDevice::Paired || pairingStatus == QBluetoothLocalDevice::AuthorizedPaired )
            item->setTextColor(QColor(Qt::green));
        else
           item->setTextColor(QColor(Qt::black));

 //输出显示
        ui->list->addItem(item);
    }
}

/* -----------------------------------------一旦发现蓝牙，即蓝牙连接---------------------------------- */
void MyWidget::itemActivated(QListWidgetItem *item)
{
    QString text = item->text();
   static const QLatin1String serviceUuid("00001101-0000-1000-8000-00805F9B34FB");
//     static const QLatin1String serviceUuid("00001101-0000-1000-8000-00805F9B34FB");
    int index = text.indexOf(' ');//到空格之前的字节大小
    if (index == -1)
        return;
    QBluetoothAddress address(text.left(index));//返回一个子字符串，该子字符串包含字符串最左边的n个字符。
    QString name(text.mid(index + 1));   //返回一个字符串，该字符串包含从指定的位置索引开始的n个字符。右边
    qDebug() << "You has choice the bluetooth address is " << address;
       qDebug() << "The device is connneting.... ";
       socket->connectToService(address, QBluetoothUuid(serviceUuid) ,QIODevice::ReadWrite);//建立连接

    QMessageBox::information(this,tr("Info"),tr("The device is connecting..."));  //弹出提示框

}

/*---------------------------蓝牙连接成功槽函数----------------------------------*/
void MyWidget::bluetoothConnectedEvent()
{
    qDebug() << "The android device has been connected successfully!";
    QMessageBox::information(this,tr("Info"),tr("successful connection!"));
}
/*---------------------------蓝牙不连接成功槽函数----------------------------------*/
void MyWidget::bluetoothDisconnectedEvent()
{
    qDebug() << "The android device has been disconnected successfully!";
    QMessageBox::information(this,tr("Info"),tr("successful disconnection!"));
}

/*-------------------------手环预警振动槽函数------------------------*/
void MyWidget::bluetoothalarm()
{
    QByteArray arrayData;
    QString s("Hello Windows!!!\nThis message is sended via bluetooth of android device!\n");
    arrayData = s.toUtf8();
    socket->write(arrayData);
}

/*---------------------读取蓝牙数据，心率------------------------------*/
void  MyWidget::readBluetoothDataEvent()
{
    QByteArray line = socket->readAll();
    QString strData = line.toHex();
    comStr.append(strData);
    qDebug() <<"rec data is: "<< comStr;
    qDebug() <<"The comStr length is: " << comStr.length();
    if(comStr.length() >= 30) {
        ui->textBrowser_info->append(comStr + "\n");
        comStr.clear();
    }
}
