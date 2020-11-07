/****************************************************************************
** Meta object code from reading C++ file 'mywidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mywidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QQueue>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mywidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyWidget_t {
    QByteArrayData data[61];
    char stringdata0[704];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyWidget_t qt_meta_stringdata_MyWidget = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MyWidget"
QT_MOC_LITERAL(1, 9, 21), // "on_openMyCom1_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 21), // "on_openMyCom2_clicked"
QT_MOC_LITERAL(4, 54, 21), // "on_openMyCom3_clicked"
QT_MOC_LITERAL(5, 76, 19), // "on_openGPRS_clicked"
QT_MOC_LITERAL(6, 96, 21), // "on_openMyCom5_clicked"
QT_MOC_LITERAL(7, 118, 22), // "on_closeMyCom1_clicked"
QT_MOC_LITERAL(8, 141, 22), // "on_closeMyCom2_clicked"
QT_MOC_LITERAL(9, 164, 22), // "on_closeMyCom3_clicked"
QT_MOC_LITERAL(10, 187, 20), // "on_closeGPRS_clicked"
QT_MOC_LITERAL(11, 208, 22), // "on_closeMyCom5_clicked"
QT_MOC_LITERAL(12, 231, 10), // "readMyCom1"
QT_MOC_LITERAL(13, 242, 10), // "readMyCom2"
QT_MOC_LITERAL(14, 253, 8), // "ReadGPRS"
QT_MOC_LITERAL(15, 262, 10), // "readMyCom5"
QT_MOC_LITERAL(16, 273, 6), // "sleep1"
QT_MOC_LITERAL(17, 280, 4), // "msec"
QT_MOC_LITERAL(18, 285, 10), // "ReadCamera"
QT_MOC_LITERAL(19, 296, 11), // "CloseCamera"
QT_MOC_LITERAL(20, 308, 8), // "ReadText"
QT_MOC_LITERAL(21, 317, 8), // "show_gps"
QT_MOC_LITERAL(22, 326, 9), // "GPS_INFO*"
QT_MOC_LITERAL(23, 336, 3), // "GPS"
QT_MOC_LITERAL(24, 340, 9), // "clear_gps"
QT_MOC_LITERAL(25, 350, 8), // "GetComma"
QT_MOC_LITERAL(26, 359, 3), // "num"
QT_MOC_LITERAL(27, 363, 5), // "char*"
QT_MOC_LITERAL(28, 369, 3), // "str"
QT_MOC_LITERAL(29, 373, 13), // "GetCommaFirst"
QT_MOC_LITERAL(30, 387, 17), // "get_double_number"
QT_MOC_LITERAL(31, 405, 1), // "s"
QT_MOC_LITERAL(32, 407, 14), // "get_int_number"
QT_MOC_LITERAL(33, 422, 15), // "get_char_number"
QT_MOC_LITERAL(34, 438, 18), // "GetCommaCameraData"
QT_MOC_LITERAL(35, 457, 9), // "gps_parse"
QT_MOC_LITERAL(36, 467, 4), // "line"
QT_MOC_LITERAL(37, 472, 14), // "Physical_parse"
QT_MOC_LITERAL(38, 487, 6), // "DBSend"
QT_MOC_LITERAL(39, 494, 5), // "temp3"
QT_MOC_LITERAL(40, 500, 9), // "checkData"
QT_MOC_LITERAL(41, 510, 5), // "temp1"
QT_MOC_LITERAL(42, 516, 2), // "s1"
QT_MOC_LITERAL(43, 519, 2), // "s2"
QT_MOC_LITERAL(44, 522, 9), // "ComisOpen"
QT_MOC_LITERAL(45, 532, 20), // "ByteArrayToHexString"
QT_MOC_LITERAL(46, 553, 4), // "data"
QT_MOC_LITERAL(47, 558, 9), // "logDataIn"
QT_MOC_LITERAL(48, 568, 6), // "State1"
QT_MOC_LITERAL(49, 575, 9), // "GPSDataIn"
QT_MOC_LITERAL(50, 585, 14), // "PhysicalDataIn"
QT_MOC_LITERAL(51, 600, 14), // "WriteHeartText"
QT_MOC_LITERAL(52, 615, 11), // "QQueue<int>"
QT_MOC_LITERAL(53, 627, 5), // "heart"
QT_MOC_LITERAL(54, 633, 13), // "ReadHeartText"
QT_MOC_LITERAL(55, 647, 9), // "CloseFile"
QT_MOC_LITERAL(56, 657, 8), // "FilePath"
QT_MOC_LITERAL(57, 666, 10), // "connectYun"
QT_MOC_LITERAL(58, 677, 8), // "Com1Init"
QT_MOC_LITERAL(59, 686, 8), // "Com2Init"
QT_MOC_LITERAL(60, 695, 8) // "Com5Init"

    },
    "MyWidget\0on_openMyCom1_clicked\0\0"
    "on_openMyCom2_clicked\0on_openMyCom3_clicked\0"
    "on_openGPRS_clicked\0on_openMyCom5_clicked\0"
    "on_closeMyCom1_clicked\0on_closeMyCom2_clicked\0"
    "on_closeMyCom3_clicked\0on_closeGPRS_clicked\0"
    "on_closeMyCom5_clicked\0readMyCom1\0"
    "readMyCom2\0ReadGPRS\0readMyCom5\0sleep1\0"
    "msec\0ReadCamera\0CloseCamera\0ReadText\0"
    "show_gps\0GPS_INFO*\0GPS\0clear_gps\0"
    "GetComma\0num\0char*\0str\0GetCommaFirst\0"
    "get_double_number\0s\0get_int_number\0"
    "get_char_number\0GetCommaCameraData\0"
    "gps_parse\0line\0Physical_parse\0DBSend\0"
    "temp3\0checkData\0temp1\0s1\0s2\0ComisOpen\0"
    "ByteArrayToHexString\0data\0logDataIn\0"
    "State1\0GPSDataIn\0PhysicalDataIn\0"
    "WriteHeartText\0QQueue<int>\0heart\0"
    "ReadHeartText\0CloseFile\0FilePath\0"
    "connectYun\0Com1Init\0Com2Init\0Com5Init"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      41,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  219,    2, 0x08 /* Private */,
       3,    0,  220,    2, 0x08 /* Private */,
       4,    0,  221,    2, 0x08 /* Private */,
       5,    0,  222,    2, 0x08 /* Private */,
       6,    0,  223,    2, 0x08 /* Private */,
       7,    0,  224,    2, 0x08 /* Private */,
       8,    0,  225,    2, 0x08 /* Private */,
       9,    0,  226,    2, 0x08 /* Private */,
      10,    0,  227,    2, 0x08 /* Private */,
      11,    0,  228,    2, 0x08 /* Private */,
      12,    0,  229,    2, 0x08 /* Private */,
      13,    0,  230,    2, 0x08 /* Private */,
      14,    0,  231,    2, 0x08 /* Private */,
      15,    0,  232,    2, 0x08 /* Private */,
      16,    1,  233,    2, 0x08 /* Private */,
      18,    0,  236,    2, 0x08 /* Private */,
      19,    0,  237,    2, 0x08 /* Private */,
      20,    0,  238,    2, 0x08 /* Private */,
      21,    1,  239,    2, 0x08 /* Private */,
      24,    0,  242,    2, 0x08 /* Private */,
      25,    2,  243,    2, 0x08 /* Private */,
      29,    2,  248,    2, 0x08 /* Private */,
      30,    1,  253,    2, 0x08 /* Private */,
      32,    1,  256,    2, 0x08 /* Private */,
      33,    1,  259,    2, 0x08 /* Private */,
      34,    2,  262,    2, 0x08 /* Private */,
      35,    2,  267,    2, 0x08 /* Private */,
      37,    1,  272,    2, 0x08 /* Private */,
      38,    1,  275,    2, 0x08 /* Private */,
      40,    4,  278,    2, 0x08 /* Private */,
      45,    1,  287,    2, 0x08 /* Private */,
      47,    1,  290,    2, 0x08 /* Private */,
      49,    1,  293,    2, 0x08 /* Private */,
      50,    0,  296,    2, 0x08 /* Private */,
      51,    1,  297,    2, 0x08 /* Private */,
      54,    0,  300,    2, 0x08 /* Private */,
      55,    1,  301,    2, 0x08 /* Private */,
      57,    0,  304,    2, 0x08 /* Private */,
      58,    0,  305,    2, 0x08 /* Private */,
      59,    0,  306,    2, 0x08 /* Private */,
      60,    0,  307,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void,
    QMetaType::Int, QMetaType::Int, 0x80000000 | 27,   26,   28,
    QMetaType::Int, QMetaType::Int, 0x80000000 | 27,   26,   28,
    QMetaType::Double, 0x80000000 | 27,   31,
    QMetaType::Int, 0x80000000 | 27,   31,
    QMetaType::QString, 0x80000000 | 27,   31,
    QMetaType::QByteArray, QMetaType::Int, 0x80000000 | 27,   26,   28,
    QMetaType::Void, 0x80000000 | 27, 0x80000000 | 22,   36,   23,
    QMetaType::Void, 0x80000000 | 27,   36,
    QMetaType::Void, QMetaType::QByteArray,   39,
    QMetaType::QByteArray, QMetaType::QByteArray, QMetaType::QByteArray, QMetaType::QByteArray, QMetaType::Bool,   41,   42,   43,   44,
    QMetaType::QString, QMetaType::QByteArray,   46,
    QMetaType::QString, QMetaType::QString,   48,
    QMetaType::QString, 0x80000000 | 22,   23,
    QMetaType::QString,
    QMetaType::Void, 0x80000000 | 52,   53,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   56,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyWidget *_t = static_cast<MyWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_openMyCom1_clicked(); break;
        case 1: _t->on_openMyCom2_clicked(); break;
        case 2: _t->on_openMyCom3_clicked(); break;
        case 3: _t->on_openGPRS_clicked(); break;
        case 4: _t->on_openMyCom5_clicked(); break;
        case 5: _t->on_closeMyCom1_clicked(); break;
        case 6: _t->on_closeMyCom2_clicked(); break;
        case 7: _t->on_closeMyCom3_clicked(); break;
        case 8: _t->on_closeGPRS_clicked(); break;
        case 9: _t->on_closeMyCom5_clicked(); break;
        case 10: _t->readMyCom1(); break;
        case 11: _t->readMyCom2(); break;
        case 12: _t->ReadGPRS(); break;
        case 13: _t->readMyCom5(); break;
        case 14: _t->sleep1((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 15: _t->ReadCamera(); break;
        case 16: _t->CloseCamera(); break;
        case 17: _t->ReadText(); break;
        case 18: _t->show_gps((*reinterpret_cast< GPS_INFO*(*)>(_a[1]))); break;
        case 19: _t->clear_gps(); break;
        case 20: { int _r = _t->GetComma((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 21: { int _r = _t->GetCommaFirst((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 22: { double _r = _t->get_double_number((*reinterpret_cast< char*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 23: { int _r = _t->get_int_number((*reinterpret_cast< char*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 24: { QString _r = _t->get_char_number((*reinterpret_cast< char*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 25: { QByteArray _r = _t->GetCommaCameraData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = std::move(_r); }  break;
        case 26: _t->gps_parse((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< GPS_INFO*(*)>(_a[2]))); break;
        case 27: _t->Physical_parse((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 28: _t->DBSend((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 29: { QByteArray _r = _t->checkData((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])),(*reinterpret_cast< const QByteArray(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QByteArray*>(_a[0]) = std::move(_r); }  break;
        case 30: { QString _r = _t->ByteArrayToHexString((*reinterpret_cast< QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 31: { QString _r = _t->logDataIn((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 32: { QString _r = _t->GPSDataIn((*reinterpret_cast< GPS_INFO*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 33: { QString _r = _t->PhysicalDataIn();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 34: _t->WriteHeartText((*reinterpret_cast< QQueue<int>(*)>(_a[1]))); break;
        case 35: _t->ReadHeartText(); break;
        case 36: _t->CloseFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 37: _t->connectYun(); break;
        case 38: _t->Com1Init(); break;
        case 39: _t->Com2Init(); break;
        case 40: _t->Com5Init(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 34:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QQueue<int> >(); break;
            }
            break;
        }
    }
}

const QMetaObject MyWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyWidget.data,
      qt_meta_data_MyWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MyWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
