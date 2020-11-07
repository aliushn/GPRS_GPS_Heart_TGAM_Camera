#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <stdlib.h>
#include <windows.h>
#include <QFile>
#include <iostream>
#include <QCoreApplication>

//心率打开
void  MyWidget::on_openMyCom5_clicked()
{
    Com5Init();
    if(isComOpen5){
    connect(myCom5,SIGNAL(readyRead()),this,SLOT(readMyCom5()));
    }
    ui->openMyCom5->setEnabled(false);          // 打开串口5可用
    ui->closeMyCom5->setEnabled(true);          //关闭串口5不可用
}

//心率关闭
void  MyWidget::on_closeMyCom5_clicked()
{
   myCom5->close();
   isComOpen5=false;
   ui->openMyCom5->setEnabled(true);          // 打开串口5不可用
   ui->closeMyCom5->setEnabled(false);          //关闭串口5可用
   ui->textBrowser_heart->clear();
   ui->textBrowser_heart_change->clear();
   sumHRVlinenum=0;
   heartque.clear();//心跳间隔队列
   timeheart=0;     //心跳间隔数据数目
   sumheart=0;    //心跳总和
   sumtextheart=0;  //心跳数据
   CloseFile(HRVTextPath);
   CloseFile(HeartTextPath);
}

//心率初始化
void MyWidget::Com5Init(){
    QString portName1="COM4";  //获取串口名Com1
    myCom5=new QSerialPort(portName1);
    //定义串口对象，传递参数，在构造函数中初始化
    isComOpen5=myCom5->open(QIODevice::ReadOnly);    //打开串口
    if(isComOpen5){
        myCom5->setBaudRate(115200);     //波特率9600
        myCom5->setDataBits(QSerialPort::Data8);        //数据位8
        myCom5->setParity(QSerialPort::NoParity);       //无校验位
        myCom5->setStopBits(QSerialPort::OneStop);         //停止位1
        myCom5->setFlowControl(QSerialPort::NoFlowControl);    //无线流
     //   myCom5->setTimeout(200);          //200ms停顿
    }
}


/*----------------------心率，myCom5读取串口数据------------------------------*/
void  MyWidget::readMyCom5() //当串口1缓冲区有数据时，读数据,定位
{
    bool ok;
    int heart;
    myCom5->flush();
    QByteArray temp1=myCom5->readAll();//存放接收到的数据
    if(!temp1.isNull())
    {
        ui->textBrowser_heart->clear();
        ui->textBrowser_heart->setPlainText(temp1);
        //显示
        heart=temp1.toInt(&ok, 10);
        sumheart+=heart;  //心率和
        timeheart++;        //取均值        
        sumtextheart++;   //文本数据长度
        heartque.push_back(heart);
        qDebug()<<QString("%1").arg(timeheart);
         //达到35数据存到文本
         if(sumtextheart>34){
             sumtextheart--;
             sumtextheart--;
             WriteHeartText(heartque);//保证35个数据
             heartque.pop_front();
             heartque.pop_front();
         }
//        ui->textBrowser_2->setText(QString("%1").arg(timeheart));
//        ui->textBrowser_3->setText(QString("%1").arg(sumheart));
    }
}

/*--------------------------------载文件写程序--------------------------------------------------*/
void MyWidget::WriteHeartText(QQueue<int> heart){
    QFile Heartfile(HeartTextPath);
 //   QString QStHeart=QString("%1").arg(heart);
    if(!Heartfile.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        qDebug()<<"Can't open the Heartfile!"<<endl;
        return;
    }
     QTextStream in(&Heartfile);
     for(int i=0;i<heart.size();i++){//写文件
           in<<heart.at(i)<<"\r\n";
     }
     WinExec("python C:/Users/Administrator/Desktop/5.8/debug/WatchTestUnionQT.py",SW_HIDE);
     Heartfile.resize(0);
     Heartfile.close();
  //读取心率变异性
     ReadHeartText();
}

/*-----------------------------------读取心率数据--------------------------------*/
void MyWidget::ReadHeartText(){
    QFile HeartReadfile(HRVTextPath);
    if(!HeartReadfile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"Can't open the HeartReadfile!"<<endl;
        return;
    }
    QString line;
    int sumHRVline=0;
    while(!HeartReadfile.atEnd()){ //读取最后一行数据
        sumHRVline++;
        line =HeartReadfile.readLine();
    }
    if(line.isNull())return;
    qDebug()<<"读取了一次";
    if(sumHRVline==sumHRVlinenum+1){
         physicalData.HRV=line;
         ui->textBrowser_heart_change->clear();
         ui->textBrowser_heart_change->setText(line);
         qDebug()<<"执行了一次";
     }
    sumHRVlinenum=sumHRVline;
    HeartReadfile.close();
}


