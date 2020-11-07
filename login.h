#ifndef LOGIN_H
#define LOGIN_H
#include <QWidget>
#include "mywidget.h"

namespace Ui {
class login;
}


class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();



private slots:
    void on_loginBt_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
