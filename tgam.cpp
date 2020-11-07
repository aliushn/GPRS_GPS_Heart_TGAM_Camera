#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>

//脑电打开
void  MyWidget::on_openMyCom2_clicked()
{
    Com2Init();
    if(isComOpen2){
    connect(myCom2,SIGNAL(readyRead()),this,SLOT(readMyCom2()));
    }
    ui->openMyCom2->setEnabled(false);          // 打开串口5可用
    ui->closeMyCom2->setEnabled(true);          //关闭串口5不可用
}

//脑电关闭
void  MyWidget::on_closeMyCom2_clicked()
{
   myCom2->close();
   isComOpen2=false;
   ui->textBrowser_tgam->clear();
   ui->openMyCom2->setEnabled(true);          // 打开串口5不可用
   ui->closeMyCom2->setEnabled(false);          //关闭串口5可用
   timemenditain=0;   //专注度
   summenditain=0;    //专注度总和
}

//脑电初始化
void MyWidget::Com2Init(){
//    QString portName1="\\\\.\\COM16";  //获取串口名Com16
    QString portName1="COM10";  //获取串口名Com16
    myCom2=new QSerialPort(portName1);
    //定义串口对象，传递参数，在构造函数中初始化
    isComOpen2=myCom2->open(QIODevice::ReadOnly);    //打开串口
    if(isComOpen2){
        myCom2->setBaudRate(QSerialPort::Baud115200,QSerialPort::AllDirections);     //波特率115200
        myCom2->setDataBits(QSerialPort::Data8);        //数据位8
        myCom2->setParity(QSerialPort::NoParity);       //无校验位
        myCom2->setStopBits(QSerialPort::OneStop);         //停止位1
        myCom2->setFlowControl(QSerialPort::NoFlowControl);    //无线流
    }
}


/*----------------------脑电，myCom2读取串口数据------------------------------*/
void  MyWidget::readMyCom2() //当串口1缓冲区有数据时，读数据,定位
{
    bool ok;
    bool signalok=false;
    QString signal,attention,meditation;
    QByteArray temp=myCom2->readAll();//存放接收到的数据
    QString ret=temp.toHex().toUpper();
    if(!ret.isNull()){
//        qDebug()<<ret.length();

        QString m[ret.length()/2];
        for(int i=0;i<ret.length()/2;i++)
        {
            m[i]=ret.mid(2*i,2);
  //           qDebug()<<m[i];
        }
 //       ui->textBrowser1->setText(ret);
        for(int i=0;i<ret.length()/2-34;i++)
        {
            if(m[i]=="AA"&&m[i+1]=="AA"&&m[i+2]=="20"){
                if(m[i+3]=="02"){
                    signal=m[i+4];//信号
                    int s=signal.toInt(&ok,16);
                    if(s<100) signalok=true;
 //                   qDebug()<<"Received Tgam";
                }
                if(m[i+31]=="04"&&signalok){
                    attention=m[i+32];   //专注度
                    int s1=attention.toInt(&ok,16);
                    ui->textBrowser_tgam->clear();
                    ui->textBrowser_tgam->setText(QString("%1").arg(s1));
                    summenditain+=s1;  //专注度和
                    timemenditain++;        //取均值
 //                   ui->textBrowser_2->setText(QString("%1").arg(timemenditain));
  //                  ui->textBrowser_3->setText(QString("%1").arg(summenditain));
                }
                if(m[i+33]=="05"&&signalok){
                    meditation=m[i+34];  //放松
                    int s2=meditation.toInt(&ok,16);
                }
                i=i+34;

//                ui->textBrowser_info->setText(QString("signal:%1,attention:%2,meditation:%3")
//                                           .arg(s).arg(s1).arg(s2));
//                qDebug()<<"signal:"+QString("%1").arg(s);
//                qDebug()<<"attention:"+QString("%1").arg(s1);
//                qDebug()<<"meditation:"+QString("%1").arg(s2);
//                qDebug()<<temp.count();
                break;
            }
        }
    }
}


QString MyWidget::ByteArrayToHexString(QByteArray data){
    QString ret(data.toHex().toUpper());//转为16进制大写
    int len = ret.length()/2;
//    qDebug()<<len;
    ret.insert(0,"0x");
    for(int i=1;i<len;i++)
    {
//        qDebug()<<i;
        ret.insert(4*i+i-1,",0x");//编写格式
    }
    return ret;
}
