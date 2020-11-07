#include "mywidget.h"
#include "ui_mywidget.h"
#include "python.h"
#include <QDebug>
#include <stdlib.h>
#include <windows.h>
#include <QFile>
#include <iostream>
#include <QCoreApplication>
using namespace std;

/*------------摄像头摄像--------------------*/
void  MyWidget::on_openMyCom3_clicked()
{
    ui->openMyCom3->setEnabled(false);          // 打开串口3不可用
    ui->closeMyCom3->setEnabled(true);          //关闭串口3可用
 //   ReadCamera();
    WinExec("python C:/Users/Administrator/Desktop/5.8/debug/camera.py",SW_HIDE);
 //   system("python C:/Users/Administrator/Desktop/build-project-unknown-Debug/debug/call.py");
    readTimer3 = new QTimer(this);      //设置读取计时器
    readTimer3->start(2000);     //设置延时为100ms
    connect(readTimer3,SIGNAL(timeout()),this,SLOT(ReadText()));
}

/*------------关闭摄像头摄像--------------------*/
void  MyWidget::on_closeMyCom3_clicked()
{
   readTimer3->stop();
    WinExec("taskkill /IM python.exe /F",SW_HIDE);
 //  CloseCamera();
   ui->openMyCom3->setEnabled(true);
   ui->closeMyCom3->setEnabled(false);
   ui->textBrowser_eye->clear();
   ui->textBrowser_eyelevel->clear();
   ui->textBrowser_yawn->clear();
   ui->textBrowser_yawnlevel->clear();
   CloseFile(CameraTextPath);
}

/*--------------------------------读取摄像头-----------------------------------*/
void MyWidget::ReadCamera()
{
    Py_Initialize();    //初始化python模块
    if (!Py_IsInitialized()) {
        return;
    }
    PyRun_SimpleString("import sys");
    QString setSysPath = QString("sys.path.append('%1')").arg(QCoreApplication::applicationDirPath());
    PyRun_SimpleString(setSysPath.toStdString().c_str());
    ui->textBrowser1->setText(setSysPath.toStdString().c_str());
    PyObject* pModule = PyImport_ImportModule("call");  //导入call_camera.py模块
    if (!pModule) {
        PyErr_Print();
        qDebug()<<"bb";
        ui->textBrowser->setText(QString("can not open python file\n"));
        return;
    }

    PyObject* pFunCamrea = PyObject_GetAttrString(pModule,"main");
    //获取导入call_camera模块中的main函数
    if (!pFunCamrea || !PyCallable_Check(pFunCamrea)) {
        ui->textBrowser->setText(QString("get function call camera failed\n"));
//        qDebug("get function call camera failed");
        return;
    }
    PyObject_CallFunction(pFunCamrea,NULL);  //执行python
    Py_Finalize();
}


/*----------------------------------关闭摄像头------------------------------*/
void MyWidget::CloseCamera()
{
    Py_Initialize();    //初始化python模块
    if (!Py_IsInitialized()) {
        return;
    }
    PyRun_SimpleString("import sys");
    QString setSysPath = QString("sys.path.append('%1')").arg(QCoreApplication::applicationDirPath());
    PyRun_SimpleString(setSysPath.toStdString().c_str());
   // qDebug()<<setSysPath.toStdString().c_str();
    PyObject* pModule = PyImport_ImportModule("call");  //导入call_camera.py模块
    ui->textBrowser->clear();
    if (!pModule) {
      ui->textBrowser->setText(QString("cant open python file\n"));
PyErr_Print();
        return;
    }

    PyObject* pFunCamrea = PyObject_GetAttrString(pModule,"shutdown");
    //获取导入call_camera模块中的main函数
    if (!pFunCamrea || !PyCallable_Check(pFunCamrea)) {
        ui->textBrowser->setText(QString("get function call camera failed\n"));
//        qDebug("get function call camera failed");
        return;
    }
    PyObject_CallFunction(pFunCamrea,NULL);  //结束，释放python
    Py_Finalize();
}


/*--------------------------------读取摄像头数据-----------------------------------*/
void MyWidget::ReadText()
{
//    qDebug()<<"no camera data";
    QFile file(CameraTextPath);
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        qDebug()<<"Can't open the camera file!"<<endl;
        return;
    }
     QTextStream in(&file);
     QString line = in.readLine();
     if (!line.isNull())
     {
         file.resize(0);
         file.close();
         QByteArray a=line.toLatin1();
         qDebug()<<a;
         char* ch=a.data();
         Physical_parse(ch);    //解析摄像头数据
         if(isComOpen4&&flagcamera&&connectcar){    //判断位置信息是否在发送，进行传到云;摄像数据正确
             SendPhysicalData=PhysicalDataIn();//整合发送数据
             while(isOpen2);  //等待位置发完
             isOpen1=true;    //生理发送
             sendAT(myCom4,2,SendPhysicalData);//发送数据
             isOpen1=false;
                 }
     }
     else {
         file.close();
     }
}


/*--------------------------------------------解析摄像头数据----------------------------*/
//*1,Green,  0,Green,;   10s发送一次
//*2,Green,  2,Green,;
void MyWidget::Physical_parse(char *line)//将得到的数据解析到GPS中
{
    int tmp,tmp1;
    QByteArray CameraData;
    char *buf=line;
    tmp=GetCommaFirst(1,buf);   //数据头所在的位置，即不为0
    CameraData=GetCommaCameraData(1,&buf[tmp]);   //获取数据
    tmp1=GetComma(4,CameraData.data());      //是否有四个个逗号
    qDebug()<<"Data:"+CameraData;
    flagcamera=false;
    if(tmp&&tmp1&&!CameraData.isNull()){//开头*,结尾;中间三个,
        char* buf1=CameraData.data();
        flagcamera=true;
        physicalData.Eye=get_double_number(&buf1[0]);  //眼睛闭眼次数
        physicalData.EyeLevel=get_char_number(&buf1[GetComma(1,buf1)]);
        physicalData.YawnLevel=get_char_number(&buf1[GetComma(3,buf1)]);//哈欠等级
        if(sumyawn.size()>=6){                  //保证前1分钟的哈欠次数
            sumyawn.pop_front();
        }
        sumyawn.push_back(get_int_number(&buf1[GetComma(2,buf1)]));//哈欠次数
        for(int i=0;i<sumyawn.size();i++){
            physicalData.Yawn+=sumyawn.at(i);      //当前一分钟的哈欠次数
        }
        ui->textBrowser_eye->clear();
        ui->textBrowser_eye->setPlainText(QString("%1").arg(physicalData.Eye));
        ui->textBrowser_eyelevel->clear();
        ui->textBrowser_eyelevel->setPlainText(physicalData.EyeLevel);
        ui->textBrowser_yawn->clear();
        ui->textBrowser_yawn->setPlainText(QString("%1").arg(physicalData.Yawn));
        ui->textBrowser_yawnlevel->clear();
        ui->textBrowser_yawnlevel->setPlainText(physicalData.YawnLevel);

        qDebug()<<physicalData.Eye;
        qDebug()<<physicalData.EyeLevel;
        qDebug()<<physicalData.Yawn;
        qDebug()<<physicalData.YawnLevel;
   }
}



int MyWidget::get_int_number(char *s)
{
    char buf[128];
    int i;
    int rev;
    i=GetComma(1,s);    //得到数据长度
    strncpy(buf,s,i);
    buf[i]=0;           //加字符串结束标志
    rev=atoi(buf);      //字符串转int
    return rev;
}

QString MyWidget::get_char_number(char *s)
{
    char buf[6];
    int i;
    i=GetComma(1,s);    //得到数据长度
    strncpy(buf,s,i-1);
    buf[i-1]=0;           //加字符串结束标志
    QString st=QString(QLatin1String(buf));
    return st;
}


/*--------------------------解析数据头所在的位置--------------------------------*/
int MyWidget::GetCommaFirst(int num,char *str)
{
    int i,j=0;
    int len=strlen(str);
    for(i=0;i<len;i++)
    {
        if(str[i]=='*')j++;
        if(j==num)return i+1;   //返回当前找到的逗号位置的下一个位置
    }
    return 0;
}

/*---------------------------截取数据---------------------------------*/
QByteArray MyWidget::GetCommaCameraData(int num,char *str)
{
    char buf[128];
    int i,j=0;
    int len=strlen(str);
    for(i=0;i<len;i++)
    {
        if(str[i]==';')j++;
        if(j==num){
   //返回当前找到的分号位置的当前位置，数据长度
            break;
            }
    }
    if(i==len)return 0; //未找到数据
    strncpy(buf,str,i);
    buf[i]=0;           //加字符串结束标志
    QByteArray str1=QByteArray(buf,i);
    return str1;
}

