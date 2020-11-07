/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QPushButton *openMyCom3;
    QPushButton *closeMyCom3;
    QPushButton *openMyCom5;
    QPushButton *closeMyCom5;
    QPushButton *openMyCom1;
    QPushButton *closeMyCom1;
    QPushButton *openMyCom2;
    QPushButton *closeMyCom2;
    QLabel *label;
    QPushButton *openGPRS;
    QPushButton *closeGPRS;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser1;
    QLabel *label_4;
    QLabel *label_5;
    QTextBrowser *textBrowser_2;
    QTextBrowser *textBrowser_3;
    QTextBrowser *textBrowser_4;
    QTextBrowser *textBrowser_5;
    QTextBrowser *textBrowser_6;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QListWidget *list;
    QLabel *label_11;
    QTextBrowser *textBrowser_info;
    QTextBrowser *textBrowser_7;
    QLabel *label_12;
    QTextBrowser *textBrowser_heart;
    QLabel *label_2;
    QTextBrowser *textBrowser_tgam;
    QLabel *label_3;
    QLabel *label_13;
    QTextBrowser *textBrowser_eye;
    QTextBrowser *textBrowser_eyelevel;
    QTextBrowser *textBrowser_yawnlevel;
    QTextBrowser *textBrowser_yawn;
    QLabel *label_14;
    QLabel *label_15;
    QTextBrowser *textBrowser_heart_change;
    QLabel *label_16;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName(QStringLiteral("MyWidget"));
        MyWidget->resize(829, 503);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MyWidget->sizePolicy().hasHeightForWidth());
        MyWidget->setSizePolicy(sizePolicy);
        MyWidget->setAutoFillBackground(false);
        openMyCom3 = new QPushButton(MyWidget);
        openMyCom3->setObjectName(QStringLiteral("openMyCom3"));
        openMyCom3->setGeometry(QRect(30, 160, 91, 41));
        closeMyCom3 = new QPushButton(MyWidget);
        closeMyCom3->setObjectName(QStringLiteral("closeMyCom3"));
        closeMyCom3->setGeometry(QRect(140, 160, 91, 41));
        openMyCom5 = new QPushButton(MyWidget);
        openMyCom5->setObjectName(QStringLiteral("openMyCom5"));
        openMyCom5->setGeometry(QRect(30, 110, 91, 41));
        closeMyCom5 = new QPushButton(MyWidget);
        closeMyCom5->setObjectName(QStringLiteral("closeMyCom5"));
        closeMyCom5->setGeometry(QRect(140, 110, 91, 41));
        openMyCom1 = new QPushButton(MyWidget);
        openMyCom1->setObjectName(QStringLiteral("openMyCom1"));
        openMyCom1->setGeometry(QRect(30, 60, 91, 41));
        closeMyCom1 = new QPushButton(MyWidget);
        closeMyCom1->setObjectName(QStringLiteral("closeMyCom1"));
        closeMyCom1->setGeometry(QRect(140, 60, 91, 41));
        openMyCom2 = new QPushButton(MyWidget);
        openMyCom2->setObjectName(QStringLiteral("openMyCom2"));
        openMyCom2->setGeometry(QRect(30, 210, 91, 41));
        closeMyCom2 = new QPushButton(MyWidget);
        closeMyCom2->setObjectName(QStringLiteral("closeMyCom2"));
        closeMyCom2->setGeometry(QRect(140, 210, 91, 41));
        label = new QLabel(MyWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(560, 20, 51, 31));
        openGPRS = new QPushButton(MyWidget);
        openGPRS->setObjectName(QStringLiteral("openGPRS"));
        openGPRS->setGeometry(QRect(30, 12, 91, 41));
        closeGPRS = new QPushButton(MyWidget);
        closeGPRS->setObjectName(QStringLiteral("closeGPRS"));
        closeGPRS->setGeometry(QRect(140, 12, 91, 41));
        textBrowser = new QTextBrowser(MyWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(260, 60, 281, 151));
        textBrowser1 = new QTextBrowser(MyWidget);
        textBrowser1->setObjectName(QStringLiteral("textBrowser1"));
        textBrowser1->setGeometry(QRect(260, 295, 281, 181));
        label_4 = new QLabel(MyWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(260, 20, 71, 31));
        label_5 = new QLabel(MyWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(260, 250, 81, 31));
        textBrowser_2 = new QTextBrowser(MyWidget);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(80, 260, 121, 31));
        textBrowser_3 = new QTextBrowser(MyWidget);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(80, 300, 121, 31));
        textBrowser_4 = new QTextBrowser(MyWidget);
        textBrowser_4->setObjectName(QStringLiteral("textBrowser_4"));
        textBrowser_4->setGeometry(QRect(80, 340, 121, 31));
        textBrowser_5 = new QTextBrowser(MyWidget);
        textBrowser_5->setObjectName(QStringLiteral("textBrowser_5"));
        textBrowser_5->setGeometry(QRect(80, 380, 121, 31));
        textBrowser_6 = new QTextBrowser(MyWidget);
        textBrowser_6->setObjectName(QStringLiteral("textBrowser_6"));
        textBrowser_6->setGeometry(QRect(80, 420, 121, 31));
        label_6 = new QLabel(MyWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 260, 41, 31));
        label_7 = new QLabel(MyWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 300, 41, 31));
        label_8 = new QLabel(MyWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 340, 41, 31));
        label_9 = new QLabel(MyWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 380, 41, 31));
        label_10 = new QLabel(MyWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 420, 41, 31));
        list = new QListWidget(MyWidget);
        list->setObjectName(QStringLiteral("list"));
        list->setGeometry(QRect(680, 390, 141, 41));
        label_11 = new QLabel(MyWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(560, 400, 91, 61));
        textBrowser_info = new QTextBrowser(MyWidget);
        textBrowser_info->setObjectName(QStringLiteral("textBrowser_info"));
        textBrowser_info->setGeometry(QRect(680, 440, 141, 51));
        textBrowser_7 = new QTextBrowser(MyWidget);
        textBrowser_7->setObjectName(QStringLiteral("textBrowser_7"));
        textBrowser_7->setGeometry(QRect(80, 460, 121, 31));
        label_12 = new QLabel(MyWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(30, 460, 41, 31));
        textBrowser_heart = new QTextBrowser(MyWidget);
        textBrowser_heart->setObjectName(QStringLiteral("textBrowser_heart"));
        textBrowser_heart->setGeometry(QRect(690, 10, 131, 41));
        label_2 = new QLabel(MyWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(560, 120, 71, 31));
        textBrowser_tgam = new QTextBrowser(MyWidget);
        textBrowser_tgam->setObjectName(QStringLiteral("textBrowser_tgam"));
        textBrowser_tgam->setGeometry(QRect(690, 120, 131, 41));
        label_3 = new QLabel(MyWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(560, 170, 81, 41));
        label_13 = new QLabel(MyWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(560, 230, 81, 41));
        textBrowser_eye = new QTextBrowser(MyWidget);
        textBrowser_eye->setObjectName(QStringLiteral("textBrowser_eye"));
        textBrowser_eye->setGeometry(QRect(690, 170, 131, 41));
        textBrowser_eyelevel = new QTextBrowser(MyWidget);
        textBrowser_eyelevel->setObjectName(QStringLiteral("textBrowser_eyelevel"));
        textBrowser_eyelevel->setGeometry(QRect(690, 220, 131, 41));
        textBrowser_yawnlevel = new QTextBrowser(MyWidget);
        textBrowser_yawnlevel->setObjectName(QStringLiteral("textBrowser_yawnlevel"));
        textBrowser_yawnlevel->setGeometry(QRect(690, 320, 131, 41));
        textBrowser_yawn = new QTextBrowser(MyWidget);
        textBrowser_yawn->setObjectName(QStringLiteral("textBrowser_yawn"));
        textBrowser_yawn->setGeometry(QRect(690, 270, 131, 41));
        label_14 = new QLabel(MyWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(560, 280, 121, 41));
        label_15 = new QLabel(MyWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(560, 330, 121, 41));
        textBrowser_heart_change = new QTextBrowser(MyWidget);
        textBrowser_heart_change->setObjectName(QStringLiteral("textBrowser_heart_change"));
        textBrowser_heart_change->setGeometry(QRect(690, 70, 131, 41));
        label_16 = new QLabel(MyWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(560, 70, 51, 41));

        retranslateUi(MyWidget);

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QApplication::translate("MyWidget", "\347\226\262\345\212\263\351\251\276\351\251\266\347\233\221\346\265\213\347\263\273\347\273\237", nullptr));
        openMyCom3->setText(QApplication::translate("MyWidget", "\344\272\272\350\204\270\346\243\200\346\265\213", nullptr));
        closeMyCom3->setText(QApplication::translate("MyWidget", "\345\205\263\351\227\255\346\243\200\346\265\213", nullptr));
        openMyCom5->setText(QApplication::translate("MyWidget", "\347\233\221\346\216\247\345\277\203\347\216\207", nullptr));
        closeMyCom5->setText(QApplication::translate("MyWidget", "\345\205\263\351\227\255\345\277\203\347\216\207", nullptr));
        openMyCom1->setText(QApplication::translate("MyWidget", "\347\233\221\346\216\247\345\256\232\344\275\215", nullptr));
        closeMyCom1->setText(QApplication::translate("MyWidget", "\345\205\263\351\227\255\345\256\232\344\275\215", nullptr));
        openMyCom2->setText(QApplication::translate("MyWidget", "\350\204\221\347\224\265\346\243\200\346\265\213", nullptr));
        closeMyCom2->setText(QApplication::translate("MyWidget", "\345\205\263\351\227\255\350\204\221\347\224\265", nullptr));
        label->setText(QApplication::translate("MyWidget", "\345\277\203\350\267\263\351\227\264\351\232\224", nullptr));
        openGPRS->setText(QApplication::translate("MyWidget", "\345\274\200\350\275\246", nullptr));
        closeGPRS->setText(QApplication::translate("MyWidget", "\351\200\200\345\207\272\347\231\273\351\231\206", nullptr));
        label_4->setText(QApplication::translate("MyWidget", "GPRS\347\225\214\351\235\242", nullptr));
        label_5->setText(QApplication::translate("MyWidget", "\345\214\227\346\226\227\346\225\260\346\215\256", nullptr));
        label_6->setText(QApplication::translate("MyWidget", "\346\227\245\346\234\237", nullptr));
        label_7->setText(QApplication::translate("MyWidget", "\346\227\266\351\227\264", nullptr));
        label_8->setText(QApplication::translate("MyWidget", "\347\273\217\345\272\246", nullptr));
        label_9->setText(QApplication::translate("MyWidget", "\347\272\254\345\272\246", nullptr));
        label_10->setText(QApplication::translate("MyWidget", "\351\252\214\350\257\201", nullptr));
        label_11->setText(QApplication::translate("MyWidget", "\345\217\257\350\277\236\350\223\235\347\211\231", nullptr));
        label_12->setText(QApplication::translate("MyWidget", "\351\200\237\345\272\246", nullptr));
        label_2->setText(QApplication::translate("MyWidget", "\350\204\221\347\224\265\344\270\223\346\263\250\345\272\246", nullptr));
        label_3->setText(QApplication::translate("MyWidget", "perclos\345\200\274", nullptr));
        label_13->setText(QApplication::translate("MyWidget", "\347\234\274\351\203\250\347\226\262\345\212\263\347\255\211\347\272\247", nullptr));
        label_14->setText(QApplication::translate("MyWidget", "60s\345\223\210\346\254\240\346\254\241\346\225\260", nullptr));
        label_15->setText(QApplication::translate("MyWidget", "\345\223\210\346\254\240\347\226\262\345\212\263\347\255\211\347\272\247", nullptr));
        label_16->setText(QApplication::translate("MyWidget", "HRV", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
