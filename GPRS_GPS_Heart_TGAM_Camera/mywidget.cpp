#include "mywidget.h"
#include "ui_mywidget.h"
#include "QMessageBox"
#include <QDebug>
#include <QTextCodec>
#include "login.h"
MyWidget::MyWidget(QWidget *parent) :    //构造方法
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    ui->closeMyCom1->setEnabled(false);  //关闭定位按钮
    ui->closeMyCom2->setEnabled(false);  //关闭脑电按钮
    ui->closeMyCom3->setEnabled(false);  //关闭摄像头按钮
    ui->closeGPRS->setEnabled(false);  //关闭GPPS按钮,云连接
    ui->closeMyCom5->setEnabled(false);  //关闭心率
    connectYun();
//    connect(this,SIGNAL(setSendSignal(bool)),this,SLOT(setSendSlot(bool)));
//    数据收集好即触发发送函数

//    localDevice = new QBluetoothLocalDevice();   //本地ip设置
//    discoveryAgent= new QBluetoothDeviceDiscoveryAgent();     //发现附近蓝牙
//    socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);

//  //当发现info描述的蓝牙设备时发出此信号来进行动作
//    connect(discoveryAgent,
//            SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),
//            this,
//            SLOT(addBlueToothDevicesToList(QBluetoothDeviceInfo))
//            );

//    //双击蓝牙信息产生信号，进行蓝牙连接
//    connect(ui->list,
//            SIGNAL(itemActivated(QListWidgetItem*)),
//            this,
//            SLOT(itemActivated(QListWidgetItem*))
//            );

//读取蓝牙传来的数据

//    connect(socket,
//            SIGNAL(readyRead()),
//            this,
//            SLOT(readBluetoothDataEvent())
//            );

// //蓝牙连接成功
//    connect(socket,
//            SIGNAL(connected()),
//            this,
//            SLOT(bluetoothConnectedEvent())
//            );
//    connect(socket,
//            SIGNAL(disconnected()),
//            this,
//            SLOT(bluetoothDisconnectedEvent())
//            );

//    if( localDevice->hostMode() == QBluetoothLocalDevice::HostPoweredOff ) {
//        ui->openMyBlue->setEnabled(true);
//        ui->closeMyBlue->setEnabled(false);
//    }else {
//        ui->openMyBlue->setEnabled(false);
//        ui->closeMyBlue->setEnabled(true);
//    }


}

MyWidget::~MyWidget()       //析构方法
{
    delete ui;
}


/*-------------------------------延时函数-----------------------------*/
void  MyWidget::sleep1(unsigned int msec)
{
    QTime dieTime=QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
}

void MyWidget::CloseFile(QString FilePath){
    QFile file(FilePath);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug()<<"Can't close the file!"<<endl;
        return;
    }
    file.resize(0);
    file.close();
}






