#include "login.h"
#include "ui_login.h"
#include "mywidget.h"
Drive_INFO Drive;

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void  login::on_loginBt_clicked(){

    Drive.Did= ui->lineEdit->text();
    Drive.Vid= ui->lineEdit_2->text();
    MyWidget *q = new MyWidget;
    q->show();
    this->close();
}
