#include "mywidget.h"
#include "ui_mywidget.h"


/*-------------云数据上传，ttyUSB1--------------------*/
void  MyWidget::on_openGPRS_clicked()
{
//   connectYun();
   connectcar=true;
   ui->openGPRS->setEnabled(false);          // 打开串口4不可用
   ui->closeGPRS->setEnabled(true);          //关闭串口4可用
   SendloginData=logDataIn("null");
   sendAT(myCom4,2,SendloginData);                //上传登陆信息
}

/*------------关闭GPRS的数据传输--------------------*/
void  MyWidget::on_closeGPRS_clicked()
{
   connectcar=false;
   ui->openGPRS->setEnabled(true);          // 打开串口4可用
   ui->closeGPRS->setEnabled(false);          //关闭串口4不可用
   SendlogoutData=logDataIn("0.6");
   if(myCom4){
       sendAT(myCom4,2,SendlogoutData);                //上传登陆信息
       sendAT(myCom4,3,"");
       myCom4->close();   //GPRS
       isComOpen4=false;
   }
   if(isComOpen1){
   myCom1->close();   //GPS
   isComOpen1=false;}
   if(isComOpen2){
   myCom2->close();  //脑电
   isComOpen2=false;}
   if(isComOpen5){
   myCom5->close();     //心率
   isComOpen5=false;}

   CloseFile(HRVTextPath);
   CloseFile(HeartTextPath);
   CloseFile(CameraTextPath);
   WinExec("taskkill /IM python.exe /F",SW_HIDE);

   login *win = new login;//创建登录界面
   win->show();//显示登录界面
   delete this;//把主界面删除
}

/*----------------------------AT指令发送---------------------------------*/
void  MyWidget::sendAT(QSerialPort*NewCom,int iOrder,QString Data)//1.GPRS初始化 2.数据上传 3.关闭GPRS
{
    QString qStrCmd,SendData;;
    if(isComOpen4){
        switch (iOrder) {
        case 1:     //云端上传设置，进行初始化
        {
            qStrCmd="AT+CGCLASS=\"B\"\r";//设置移动台台类别为 B。
            NewCom->write(qStrCmd.toLatin1());
            sleep1(15);
//            ReadGPRS();
            qStrCmd="AT+CGDCONT=1,\"IP\",\"CMNET\"\r";//设置 PDP 上下文
            NewCom->write(qStrCmd.toLatin1());
            sleep1(15);
 //           ReadGPRS();
            qStrCmd="AT+CGATT=1\r";//设置附着和分离 GPRS 业务
            NewCom->write(qStrCmd.toLatin1());
             sleep1(15);
//            ReadGPRS();
            qStrCmd="AT+CIPCSGP=1,\"CMNET\"\r";//设置为 GPRS 连接，接入点为”CMNET”。
            NewCom->write(qStrCmd.toLatin1());
            sleep1(15);
//            ReadGPRS();
            qStrCmd="AT+CIPSTART=\"TCP\",\"39.98.33.54\",\"8888\"\r";
            NewCom->write(qStrCmd.toLatin1());
            sleep1(800);
//            myCom4->flush();                    //将所有缓冲的数据强制发送到目的地
//            QByteArray temp2=myCom4->readAll();  //调用readl()All函数,读取串口所有数据，可以看到返回值是QByteArry类型
//            QString str2;
//            str2=QString(temp2);
//            ui->textBrowser1->setText(str2);
//            if((str2.contains("CONNECT OK",Qt::CaseSensitive))||(str2.contains("ALREADY CONNECT",Qt::CaseSensitive))){
//                ui->textBrowser->setText("connect ok");
//            }
            break;
        }
        case 2:                 //云端数据上传
        {
            qStrCmd="AT+CIPSEND\r";         //云端发送设置
            NewCom->write(qStrCmd.toLatin1());
            sleep1(30);
            SendData=QString(Data);  //发送云端数据1
            NewCom->write((SendData+"\r\x1a").toStdString().c_str());
            sleep1(50);

            myCom4->flush();                    //将所有缓冲的数据强制发送到目的地
            QByteArray temp2=myCom4->readAll();  //调用readl()All函数,读取串口所有数据，可以看到返回值是QByteArry类型
            QString str2;
            str2=QString(temp2);
            ui->textBrowser->setText(str2);//显示测试
            if(str2.contains("SEND OK")){
 //               ui->textBrowser->setText("send ok");
                break;
            }
 //               ui->textBrowser->setText("send false");
                break;
        }
        case 3:              //关闭移动场景
        {
            isComOpen4=false;   //关闭云，关闭串口
            qStrCmd="AT+CIPCLOSE=1\r";
            NewCom->write(qStrCmd.toLatin1());
            sleep1(30);
  //          ReadGPRS();
            qStrCmd="AT+CIPSHUT\r";
            NewCom->write(qStrCmd.toLatin1());
            sleep1(30);

            myCom4->flush();                    //将所有缓冲的数据强制发送到目的地
            QByteArray temp2=myCom4->readAll();  //调用readl()All函数,读取串口所有数据，可以看到返回值是QByteArry类型
            QString str2;
            str2=QString(temp2);
            ui->textBrowser->setText(str2);
            if(str2.contains("SHUT OK")){
 //               ui->textBrowser->setText("close ok");
            }
            break;
        }
        default:
            break;
        }
    }
}


/*----------------------GPRS，myCom4读取串口数据------------------------------*/
void  MyWidget::ReadGPRS()
{
    myCom4->flush();                    //将所有缓冲的数据强制发送到目的地
    QByteArray temp2=myCom4->readAll();  //调用readl()All函数,读取串口所有数据，可以看到返回值是QByteArry类型
    QString str2;
    str2=QString(temp2);
    if(!str2.isEmpty())
    {
          ui->textBrowser->setText(str2);
    }
}


void  MyWidget::connectYun(){
    QString portName4="COM9";  //获取串口名Com4
    myCom4=new QSerialPort(portName4);
    //定义串口对象，传递参数，在构造函数中初始化
    isComOpen4=myCom4->open(QIODevice::ReadWrite);    //打开串口
    if(isComOpen4){
        myCom4->setBaudRate(QSerialPort::Baud115200,QSerialPort::AllDirections);     //波特率115200
        myCom4->setDataBits(QSerialPort::Data8);        //数据位8
        myCom4->setParity(QSerialPort::NoParity);       //无校验位
        myCom4->setStopBits(QSerialPort::OneStop);         //停止位1
        myCom4->setFlowControl(QSerialPort::NoFlowControl);    //无线流
        sendAT(myCom4,1,"");
    }
}
