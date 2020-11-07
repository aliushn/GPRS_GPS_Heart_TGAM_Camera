#include "mywidget.h"
#include "ui_mywidget.h"

/*------------北斗的数据读取--------------------*/
void MyWidget::on_openMyCom1_clicked()
{
    //设置信息槽，100ms达到进行北斗数据的读取
    ui->openMyCom1->setEnabled(false);          // 打开串口1不可用
    ui->closeMyCom1->setEnabled(true);          //关闭串口1可用
   Com1Init();
   if(isComOpen1){
   connect(myCom1,SIGNAL(readyRead()),this,SLOT(readMyCom1()));
   }
}

/*------------------------------关闭------------------------------------*/
void  MyWidget::on_closeMyCom1_clicked()
{
    myCom1->close();
    isComOpen1=false;
    clear_gps();
    ui->openMyCom1->setEnabled(true);          // 打开串口1可用
    ui->closeMyCom1->setEnabled(false);          //关闭串口1不可用
}

/*----------------------------------北斗解析--------------------------------------*/
int MyWidget::GetComma(int num,char *str)
{
    int i,j=0;
    int len=strlen(str);
    for(i=0;i<len;i++)
    {
        if(str[i]==',')j++;
        if(j==num)return i+1;   //返回当前找到的逗号位置的下一个位置
    }
    return 0;
}

/*---------------------------------GPS北斗数据的解析--------------------------*/
void MyWidget::gps_parse(char *line,GPS_INFO *GPS)//将得到的数据解析到GPS中
{
    int tmp,tmp1,tmp2;
   int t;
   char* buf=line;
    flagDB=false;
    t=GetComma(12,buf);//返回第12个逗号的最后位置
//    printf("t=%d",t);
//    printf("c=%c",c);
    if(t){//包含12个，(12)不为“N”
        //t&&c!='N'
        flagDB=true;
        GPS->D.hour=(buf[7]-'0')*10+(buf[8]-'0');
        GPS->D.minute=(buf[9]-'0')*10+(buf[10]-'0');
        GPS->D.second=(buf[11]-'0')*10+(buf[12]-'0');
        tmp=GetComma(9,buf);      //得到第9个逗号的下一字符序号
        GPS->D.day=(buf[tmp+0]-'0')*10+(buf[tmp+1]-'0');
        GPS->D.month=(buf[tmp+2]-'0')*10+(buf[tmp+3]-'0');
        GPS->D.year=(buf[tmp+4]-'0')*10+(buf[tmp+5]-'0')+2000;

        //------------------------------
        GPS->status=buf[GetComma(2,buf)];     //状态

      tmp1=GetComma(3,buf);
      GPS->latituded=(buf[tmp1+0]-'0')*10+(buf[tmp1+1]-'0');  //纬度度
      GPS->latitudef=get_double_number(&buf[tmp1+2]);  //纬度分
      GPS->latitude=GPS->latituded+(GPS->latitudef)/60;   //纬度

        GPS->NS=buf[GetComma(4,buf)];             //南北纬

        tmp2=GetComma(5,buf);
       GPS->longituded=(buf[tmp2+0]-'0')*100+(buf[tmp2+1]-'0')*10+(buf[tmp2+2]-'0');//经度度
       GPS->longitudef=get_double_number(&(buf[tmp2+3]));//经度分
       GPS->longitude=GPS->longituded+(GPS->longitudef)/60;   //经度

        GPS->EW=buf[GetComma(6,buf)];             //东西经
        GPS->speed=(buf[GetComma(7,buf)]-'0');   //speed
    }
    else{
        ui->textBrowser1->setText("当前GPS信号较弱");
    }
}

double MyWidget::get_double_number(char *s)
{
    char buf[128];
    int i;
    double rev;
    i=GetComma(1,s);    //得到数据长度
    strncpy(buf,s,i);
    buf[i]=0;           //加字符串结束标志
    rev=atof(buf);      //字符串转float
    return rev;
}

/*--------------------------------------显示GPS北斗数据------------------------------*/
void MyWidget::show_gps(GPS_INFO *GPS)
    {
          ui->textBrowser_2->setText(QString("%1-%2-%3\n").arg(GPS->D.year).arg(GPS->D.month).arg(GPS->D.day));
          ui->textBrowser_3->setText(QString("%1:%2:%3\n").arg(GPS->D.hour).arg(GPS->D.minute).arg(GPS->D.second));
          ui->textBrowser_4->setText(QString("%1 %2\n").arg(GPS->latitude).arg(GPS->NS));
          ui->textBrowser_5->setText(QString("%1 %2\n").arg(GPS->longitude).arg(GPS->EW));
          ui->textBrowser_6->setText(QString("%1\n").arg(GPS->status));
          ui->textBrowser_7->setText(QString("%1\n").arg(GPS->speed));
    }

/*--------------------------------------显示GPS北斗数据------------------------------*/
void MyWidget::clear_gps()
    {
        ui->textBrowser_2->setPlainText("");
        ui->textBrowser_3->setPlainText("");
        ui->textBrowser_3->setPlainText("");
        ui->textBrowser_4->setPlainText("");
        ui->textBrowser_5->setPlainText("");
        ui->textBrowser_6->setPlainText("");
        ui->textBrowser_7->setPlainText("");
        ui->textBrowser1->setPlainText("");
    }

void MyWidget::Com1Init(){
    QString portName1="COM12";  //获取串口名Com1
    myCom1=new QSerialPort(portName1);
    //定义串口对象，传递参数，在构造函数中初始化
    isComOpen1=myCom1->open(QIODevice::ReadOnly);    //打开串口
    if(isComOpen1){
        myCom1->setBaudRate(QSerialPort::Baud9600,QSerialPort::AllDirections);     //波特率9600
        myCom1->setDataBits(QSerialPort::Data8);        //数据位8
        myCom1->setParity(QSerialPort::NoParity);       //无校验位
        myCom1->setStopBits(QSerialPort::OneStop);         //停止位1
        myCom1->setFlowControl(QSerialPort::NoFlowControl);    //无线流
      //  myCom1->setTimeout(200);          //200ms停顿
    }
}


/*----------------------北斗，myCom1读取串口数据，加解析------------------------------*/
void  MyWidget::readMyCom1() //当串口1缓冲区有数据时，读数据,定位
{
//    sleep1(100);
    myCom1->flush();
    QByteArray temp1=myCom1->readAll();//存放接收到的数据
    QByteArray temp3;    //存放GPS最终数据
    temp3=checkData(temp1,"$","*",isComOpen1);    //连接北斗数据，“$”开始，“*”结束，打开串口1
    if(!temp3.isNull()){    //发送北斗数据
        DBSend(temp3);
    }
}

void  MyWidget::DBSend(QByteArray temp3) {
    struct GPS_INFO *GPS=new GPS_INFO;
    char* ch=temp3.data();
    gps_parse(ch,GPS);          //解析数据，接续到数据存入GPS内
    QString GPSData=QString(temp3);            //GPSData，接收到的数据用于调试
    printf("5");
    if(flagDB){                               //表示数据解析正确，进行显示
         ui->textBrowser1->setText(GPSData);    //调试北斗数据显示
         show_gps(GPS);          //界面显示
         printf("6");
         SendGPSData=GPSDataIn(GPS);
         if(!isOpen1  && isComOpen4 && connectcar){    //判断心理信息是否在发送，是否测到数据，进行传到云&& GPS->status=='V'
             printf("7");
             isOpen2=true;    //位置发送
             sendAT(myCom4,2,SendGPSData);//发送数据
             isOpen2=false;
                 }
            }
    delete GPS;
}

QByteArray MyWidget::checkData(QByteArray temp1,const QByteArray &s1,const QByteArray &s2,bool ComisOpen) {
    QByteArray temp3;    //存放GPS最终数据
    //异常类：无头且变量为空，已丢失头部，数据不可靠，直接返回
    if ((!temp1.contains(s1)) & (temp2.isNull()) & ComisOpen)
    {
    printf("0");
    return 0;
    }
    //第一种：有头无尾，先清空原有内容，再附加
    if ((temp1.contains(s1))&(!temp1.contains(s2)& ComisOpen))
    {
    temp2.clear();
    temp2.append(temp1);
    printf("1");
    sleep1(5);
    }
    //第二种：无头无尾且变量已有内容，数据中段部分，继续附加即可
    if ((!temp1.contains(s1))&(!temp1.contains(s2))&(!temp2.isNull())& ComisOpen)
    {
    temp2.append(temp1);
    printf("2");
    }
    //第三种：无头有尾且变量已有内容，已完整读取，附加后输出数据，并清空变量
    if ((!temp1.contains(s1))&(temp1.contains(s2))&(!temp2.isNull())& ComisOpen)
    {
    temp2.append(temp1);
    temp3 = temp2;
    temp2.clear();
    printf("3");
    return temp3;
    }
    //第四种：有头有尾（一段完整的内容），先清空原有内容，再附加，然后输出，最后清空变量
    if ((temp1.contains(s1))&(temp1.contains(s2))& ComisOpen)
    {
    temp2.clear();
    temp2.append(temp1);
    temp3 = temp2;
    temp2.clear();
    printf("4");
    return temp3;
    }
    return 0;
}




