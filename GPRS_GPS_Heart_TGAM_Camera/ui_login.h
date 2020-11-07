/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *loginBt;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(877, 474);
        login->setStyleSheet(QLatin1String("QWidget{\n"
"	background-color: rgb(255, 254, 240);\n"
"	border-image: url(:/images1/1.jpg);\n"
"}\n"
"\n"
"QLineEdit{\n"
"\n"
"	border:2px solid#7b7b7b;\n"
"	border-radius:15px;\n"
"	background-color:#fffef0\n"
"}\n"
"\n"
"QPushButton{\n"
"	border:2px solid#7b7b7b;\n"
"	border-radius:15px;\n"
"	background-color:#6a92ff;\n"
"	font: 75 26pt \"Arial\";\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color:#aa92ff\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color:#FF90ff\n"
"}\n"
""));
        label_3 = new QLabel(login);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 0, 801, 141));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(36);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("font: 75 36pt \"Arial\";"));
        label_3->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(login);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(320, 160, 261, 61));
        lineEdit_2 = new QLineEdit(login);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(320, 240, 261, 61));
        loginBt = new QPushButton(login);
        loginBt->setObjectName(QStringLiteral("loginBt"));
        loginBt->setGeometry(QRect(370, 330, 160, 60));
        label = new QLabel(login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 160, 111, 51));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(190, 240, 111, 51));
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QApplication::translate("login", "\347\231\273\351\231\206", nullptr));
        label_3->setText(QApplication::translate("login", "\346\254\242\350\277\216\344\275\277\347\224\250\347\226\262\345\212\263\346\243\200\346\265\213\347\263\273\347\273\237", nullptr));
        lineEdit->setText(QApplication::translate("login", "10020191", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("login", "\351\251\276\351\251\266\345\221\230\347\274\226\345\217\267\357\274\232", nullptr));
        lineEdit_2->setText(QApplication::translate("login", "20020191", nullptr));
        lineEdit_2->setPlaceholderText(QApplication::translate("login", "\346\261\275\350\275\246\347\274\226\345\217\267\357\274\232", nullptr));
        loginBt->setText(QApplication::translate("login", "\347\231\273\345\275\225", nullptr));
        label->setText(QApplication::translate("login", "\351\251\276\351\251\266\345\221\230\347\274\226\345\217\267", nullptr));
        label_2->setText(QApplication::translate("login", "\346\261\275\350\275\246\347\274\226\345\217\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
