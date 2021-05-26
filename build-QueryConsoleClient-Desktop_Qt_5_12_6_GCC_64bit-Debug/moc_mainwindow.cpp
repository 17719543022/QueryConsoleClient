/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QueryConsoleClient/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyListen_t {
    QByteArrayData data[4];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyListen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyListen_t qt_meta_stringdata_MyListen = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MyListen"
QT_MOC_LITERAL(1, 9, 13), // "newSerialData"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 10) // "strRequest"

    },
    "MyListen\0newSerialData\0\0strRequest"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyListen[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void MyListen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyListen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newSerialData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyListen::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyListen::newSerialData)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyListen::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_MyListen.data,
    qt_meta_data_MyListen,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyListen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyListen::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyListen.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "RequstListener"))
        return static_cast< RequstListener*>(this);
    return QObject::qt_metacast(_clname);
}

int MyListen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void MyListen::newSerialData(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_OptionButtonWidget_t {
    QByteArrayData data[1];
    char stringdata0[19];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OptionButtonWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OptionButtonWidget_t qt_meta_stringdata_OptionButtonWidget = {
    {
QT_MOC_LITERAL(0, 0, 18) // "OptionButtonWidget"

    },
    "OptionButtonWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OptionButtonWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void OptionButtonWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject OptionButtonWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_OptionButtonWidget.data,
    qt_meta_data_OptionButtonWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *OptionButtonWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OptionButtonWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OptionButtonWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int OptionButtonWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[29];
    char stringdata0[588];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 24), // "on_Button_return_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 30), // "on_flowQueryPushButton_clicked"
QT_MOC_LITERAL(4, 68, 23), // "on_msgButton_X2_clicked"
QT_MOC_LITERAL(5, 92, 23), // "on_msgButton_X1_clicked"
QT_MOC_LITERAL(6, 116, 27), // "on_msgButton_Accept_clicked"
QT_MOC_LITERAL(7, 144, 27), // "on_msgButton_Reject_clicked"
QT_MOC_LITERAL(8, 172, 26), // "updateTime_regularyRestart"
QT_MOC_LITERAL(9, 199, 15), // "updateNetStatus"
QT_MOC_LITERAL(10, 215, 7), // "onReply"
QT_MOC_LITERAL(11, 223, 14), // "QNetworkReply*"
QT_MOC_LITERAL(12, 238, 5), // "reply"
QT_MOC_LITERAL(13, 244, 11), // "onNewTicket"
QT_MOC_LITERAL(14, 256, 18), // "BoardingTicketInfo"
QT_MOC_LITERAL(15, 275, 6), // "btInfo"
QT_MOC_LITERAL(16, 282, 9), // "onNewCard"
QT_MOC_LITERAL(17, 292, 12), // "CardDataInfo"
QT_MOC_LITERAL(18, 305, 8), // "cardData"
QT_MOC_LITERAL(19, 314, 7), // "clicked"
QT_MOC_LITERAL(20, 322, 11), // "widgetIndex"
QT_MOC_LITERAL(21, 334, 26), // "on_pushButton_bind_clicked"
QT_MOC_LITERAL(22, 361, 31), // "on_pushButton_location1_clicked"
QT_MOC_LITERAL(23, 393, 31), // "on_pushButton_location2_clicked"
QT_MOC_LITERAL(24, 425, 31), // "on_pushButton_location3_clicked"
QT_MOC_LITERAL(25, 457, 31), // "on_pushButton_intercept_clicked"
QT_MOC_LITERAL(26, 489, 32), // "on_pushButton_intercept1_clicked"
QT_MOC_LITERAL(27, 522, 32), // "on_pushButton_intercept2_clicked"
QT_MOC_LITERAL(28, 555, 32) // "on_pushButton_intercept3_clicked"

    },
    "MainWindow\0on_Button_return_clicked\0"
    "\0on_flowQueryPushButton_clicked\0"
    "on_msgButton_X2_clicked\0on_msgButton_X1_clicked\0"
    "on_msgButton_Accept_clicked\0"
    "on_msgButton_Reject_clicked\0"
    "updateTime_regularyRestart\0updateNetStatus\0"
    "onReply\0QNetworkReply*\0reply\0onNewTicket\0"
    "BoardingTicketInfo\0btInfo\0onNewCard\0"
    "CardDataInfo\0cardData\0clicked\0widgetIndex\0"
    "on_pushButton_bind_clicked\0"
    "on_pushButton_location1_clicked\0"
    "on_pushButton_location2_clicked\0"
    "on_pushButton_location3_clicked\0"
    "on_pushButton_intercept_clicked\0"
    "on_pushButton_intercept1_clicked\0"
    "on_pushButton_intercept2_clicked\0"
    "on_pushButton_intercept3_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x08 /* Private */,
       3,    0,  115,    2, 0x08 /* Private */,
       4,    0,  116,    2, 0x08 /* Private */,
       5,    0,  117,    2, 0x08 /* Private */,
       6,    0,  118,    2, 0x08 /* Private */,
       7,    0,  119,    2, 0x08 /* Private */,
       8,    0,  120,    2, 0x08 /* Private */,
       9,    0,  121,    2, 0x08 /* Private */,
      10,    1,  122,    2, 0x08 /* Private */,
      13,    1,  125,    2, 0x08 /* Private */,
      16,    1,  128,    2, 0x08 /* Private */,
      19,    1,  131,    2, 0x08 /* Private */,
      21,    0,  134,    2, 0x08 /* Private */,
      22,    0,  135,    2, 0x08 /* Private */,
      23,    0,  136,    2, 0x08 /* Private */,
      24,    0,  137,    2, 0x08 /* Private */,
      25,    0,  138,    2, 0x08 /* Private */,
      26,    0,  139,    2, 0x08 /* Private */,
      27,    0,  140,    2, 0x08 /* Private */,
      28,    0,  141,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Button_return_clicked(); break;
        case 1: _t->on_flowQueryPushButton_clicked(); break;
        case 2: _t->on_msgButton_X2_clicked(); break;
        case 3: _t->on_msgButton_X1_clicked(); break;
        case 4: _t->on_msgButton_Accept_clicked(); break;
        case 5: _t->on_msgButton_Reject_clicked(); break;
        case 6: _t->updateTime_regularyRestart(); break;
        case 7: _t->updateNetStatus(); break;
        case 8: _t->onReply((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 9: _t->onNewTicket((*reinterpret_cast< const BoardingTicketInfo(*)>(_a[1]))); break;
        case 10: _t->onNewCard((*reinterpret_cast< const CardDataInfo(*)>(_a[1]))); break;
        case 11: _t->clicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_pushButton_bind_clicked(); break;
        case 13: _t->on_pushButton_location1_clicked(); break;
        case 14: _t->on_pushButton_location2_clicked(); break;
        case 15: _t->on_pushButton_location3_clicked(); break;
        case 16: _t->on_pushButton_intercept_clicked(); break;
        case 17: _t->on_pushButton_intercept1_clicked(); break;
        case 18: _t->on_pushButton_intercept2_clicked(); break;
        case 19: _t->on_pushButton_intercept3_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< BoardingTicketInfo >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CardDataInfo >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
