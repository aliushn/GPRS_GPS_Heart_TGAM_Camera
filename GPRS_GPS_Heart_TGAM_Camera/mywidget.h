#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QWidget>
#include <QTimer>
#include <QTime>
#include <vector>
#include <QListWidgetItem>
//#include <QtBluetooth/qtbluetoothglobal.h>
//#include <QtBluetooth/qbluetoothlocaldevice.h> //本地设备驱动头文件
//#include <qbluetoothaddress.h>
//#include <qbluetoothdevicediscoveryagent.h>   //发现附件蓝牙类
//#include <qbluetoothlocaldevice.h>
//#include "qbluetoothsocket.h"
#include "login.h"
#include <stdlib.h>
#include <windows.h>
#include <QFile>
#include <iostream>
#include <QCoreApplication>
#include <QQueue>
//#include <string>
using namespace std;
struct Drive_INFO{
             QString Drive;//drive
             QString Did;      //驾驶员编号
             QString Vid;      //汽车编号
             qint64 Tim;   //时间戳
             int Action;  //上车（0）
             QString State;   //疲劳状态，null
        };
extern Drive_INFO Drive;

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();
    void sendAT(QSerialPort * NewCom, int iOrder,QString Data);   //发送指令
    struct date_time{
        int year;
        int month;
        int day;
        int hour;
        int minute;
        int second;
    };
/*-------------------北斗位置信息-----------------------*/
    struct GPS_INFO{
         date_time D;//时间
         char status;       //接收状态
         double latituded;   //纬度度
         double latitudef;   //纬度分
         double latitude;   //纬度
         double longituded;  //经度度
         double longitudef;  //经度分
         double longitude;  //经度
         char NS;           //南北极
         char EW;           //东西
         double speed;      //速度
         double high;       //高度
         QString Position;//physical
         int Vid;      //汽车编号
         qint64 Tim;   //时间戳
    };


/*-------------------生理信息-----------------------*/
struct Physical_INFO{
         QString Physical;//physical
         int HeartCurrent;      //心率变异性
         int Attention; //脑电专注度
         double Eye;      //眼部疲劳
         QString EyeLevel;
         int Yawn;     //打哈欠疲劳状态
         QString YawnLevel;
         qint64 Tim;   //时间戳
         QString HRV;    //计算的心电变异性
    };


signals:
//    void setSendSignal(bool MsO);   //自定义一个含有bool的信息槽，一单数据接收完整，发送数据给相关槽
//    void deviceDiscovered(QBluetoothDeviceInfo);

private slots:
//    void setSendSlot(bool MsO);       //fasong
    void on_openMyCom1_clicked();      //打开串口1,定位
    void on_openMyCom2_clicked();      //打开串口2，脑电
    void on_openMyCom3_clicked();      //打开串口3，摄像头
    void on_openGPRS_clicked();      //上传登陆数据
    void on_openMyCom5_clicked();

//    void on_openMyBlue_clicked();      //打开蓝牙，心率
    void on_closeMyCom1_clicked();      //关闭串口1，定位
    void on_closeMyCom2_clicked();      //关闭串口2，脑电
    void on_closeMyCom3_clicked();      //关闭串口3，摄像头
    void on_closeGPRS_clicked();      //关闭串口4，Grps
    void on_closeMyCom5_clicked();
//    void on_closeMyBlue_clicked();      //关闭蓝牙，心率
    void readMyCom1();           //读取串口1，定位数据分析
    void readMyCom2();           //读取串口2，脑电数据分析
    void ReadGPRS();           //读取串口4，gprs数据分析
    void readMyCom5();

 //   void readBluetoothDataEvent();          //读取蓝牙数据，心率
    void sleep1(unsigned int msec); //延时方法
    void ReadCamera();      //调用摄像头
    void CloseCamera();     //关闭摄像头
    void ReadText();       //读取文件

    void show_gps(GPS_INFO *GPS);
    void clear_gps();
    int GetComma(int num,char *str);
    int GetCommaFirst(int num,char *str);
    double get_double_number(char *s);
    int get_int_number(char *s);
    QString get_char_number(char *s);
    QByteArray GetCommaCameraData(int num,char *str);
    void gps_parse(char *line,GPS_INFO *GPS); //将得到的数据解析到GPS中
    void Physical_parse(char *line); //将得到的数据解析到physical中
    void DBSend(QByteArray temp3);   //北斗发送函数
    QByteArray checkData(QByteArray temp1,const QByteArray &s1,const QByteArray &s2,bool ComisOpen);
    //temp1接收的数据，s1头标志，s2尾标志，ComisOpen串口是否打开
    QString ByteArrayToHexString(QByteArray data);//转16进制
    QString logDataIn(QString State1);       //上下车数据整合
    QString GPSDataIn(GPS_INFO *GPS);       //位置信息整合
    QString PhysicalDataIn();                 //生理信息融合
    void WriteHeartText(QQueue<int> heart);   //心跳间隔
    void ReadHeartText();                    //读取心率变异性
    void CloseFile(QString FilePath);//关闭文件
//    void addBlueToothDevicesToList(const QBluetoothDeviceInfo&);   //添加蓝牙设备
//    void bluetoothalarm();
//    void bluetoothConnectedEvent();
//    void bluetoothDisconnectedEvent();
//    void itemActivated(QListWidgetItem *item);

    void connectYun();    //连接到云端初始化
    void Com1Init();    //定位信息串口初始化
    void Com2Init();    //脑电串口初始化
    void Com5Init();    //心率串口初始化




private:
    Ui::MyWidget *ui;
    QSerialPort  *myCom1,*myCom2,*myCom4,*myCom5;    //定义串口对象
//    QTimer *readTimer,*readTimer1,*readTimer3;
    QTimer *readTimer3;
    bool flagDB=true;  //判断北斗数据解析是否正确
    bool flagcamera=true;
    bool isOpen1=false,isOpen2=false;//1生理，2位置
    bool connectcar=false;
    bool isComOpen1=false,isComOpen2=false,isComOpen4=false,isComOpen5=false;  //检测端口是否打开
    QString SendGPSData;//北斗位置数据
    QString SendloginData;//发生登陆数据
    QString SendlogoutData;//发生登陆数据
    QString SendPhysicalData;//发送生理信息
    Physical_INFO physicalData; //存放生理信息
//    QBluetoothLocalDevice *localDevice;    //本地蓝牙配置
//    QBluetoothDeviceDiscoveryAgent *discoveryAgent;   //发现蓝牙设备
//    QBluetoothSocket *socket;
    unsigned char comBuffer[15];
    unsigned int  comCount;
    QString comStr;
    QByteArray temp2;   //存放GPS缓冲数据
    QQueue<int> heartque;//心跳间隔队列
    QQueue<int> sumyawn;//哈欠队列
    int timeheart=0;     //心跳间隔数据数目
    int sumheart=0;    //心跳总和
    int sumtextheart=0;  //心跳数据
    int timemenditain=0;   //专注度
    int summenditain=0;    //专注度总和
    int sumHRVlinenum=0;    //HRV的行数
    QString CameraTextPath=QString(QCoreApplication::applicationDirPath()+"%1").arg("/biyanhaqianshuju.txt");
    QString HRVTextPath=QString(QCoreApplication::applicationDirPath()+"%1").arg("/HRV.txt");
    QString HeartTextPath=QString(QCoreApplication::applicationDirPath()+"%1").arg("/Heart.txt");
};
#endif // MYWIDGET_H
