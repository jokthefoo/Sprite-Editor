/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata0[292];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "sendMouseInput"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 12), // "QMouseEvent*"
QT_MOC_LITERAL(4, 40, 15), // "sendButtonInput"
QT_MOC_LITERAL(5, 56, 8), // "QWidget*"
QT_MOC_LITERAL(6, 65, 18), // "sendPropertyChange"
QT_MOC_LITERAL(7, 84, 8), // "Property"
QT_MOC_LITERAL(8, 93, 10), // "sendSaveAs"
QT_MOC_LITERAL(9, 104, 12), // "sendOpenProj"
QT_MOC_LITERAL(10, 117, 9), // "scaleView"
QT_MOC_LITERAL(11, 127, 14), // "saveAsSelected"
QT_MOC_LITERAL(12, 142, 22), // "sendConfigurationInput"
QT_MOC_LITERAL(13, 165, 25), // "openConfigurationSelected"
QT_MOC_LITERAL(14, 191, 14), // "spinnerChanged"
QT_MOC_LITERAL(15, 206, 12), // "updateScreen"
QT_MOC_LITERAL(16, 219, 7), // "QImage*"
QT_MOC_LITERAL(17, 227, 6), // "toShow"
QT_MOC_LITERAL(18, 234, 11), // "updateColor"
QT_MOC_LITERAL(19, 246, 22), // "on_play_button_pressed"
QT_MOC_LITERAL(20, 269, 13), // "sendSaveAsSig"
QT_MOC_LITERAL(21, 283, 8) // "openProj"

    },
    "MainWindow\0sendMouseInput\0\0QMouseEvent*\0"
    "sendButtonInput\0QWidget*\0sendPropertyChange\0"
    "Property\0sendSaveAs\0sendOpenProj\0"
    "scaleView\0saveAsSelected\0"
    "sendConfigurationInput\0openConfigurationSelected\0"
    "spinnerChanged\0updateScreen\0QImage*\0"
    "toShow\0updateColor\0on_play_button_pressed\0"
    "sendSaveAsSig\0openProj"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   89,    2, 0x06 /* Public */,
       4,    1,   94,    2, 0x06 /* Public */,
       6,    1,   97,    2, 0x06 /* Public */,
       8,    0,  100,    2, 0x06 /* Public */,
       9,    3,  101,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,  108,    2, 0x0a /* Public */,
      11,    1,  111,    2, 0x0a /* Public */,
      12,    0,  114,    2, 0x0a /* Public */,
      13,    0,  115,    2, 0x0a /* Public */,
      14,    1,  116,    2, 0x0a /* Public */,
      15,    1,  119,    2, 0x0a /* Public */,
      18,    1,  122,    2, 0x0a /* Public */,
      19,    0,  125,    2, 0x08 /* Private */,
      20,    0,  126,    2, 0x08 /* Private */,
      21,    0,  127,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPointF, 0x80000000 | 3,    2,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendMouseInput((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QMouseEvent*(*)>(_a[2]))); break;
        case 1: _t->sendButtonInput((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 2: _t->sendPropertyChange((*reinterpret_cast< Property(*)>(_a[1]))); break;
        case 3: _t->sendSaveAs(); break;
        case 4: _t->sendOpenProj((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 5: _t->scaleView((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->saveAsSelected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->sendConfigurationInput(); break;
        case 8: _t->openConfigurationSelected(); break;
        case 9: _t->spinnerChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->updateScreen((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        case 11: _t->updateColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 12: _t->on_play_button_pressed(); break;
        case 13: _t->sendSaveAsSig(); break;
        case 14: _t->openProj(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(QPointF , QMouseEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sendMouseInput)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QWidget * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sendButtonInput)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(Property );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sendPropertyChange)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sendSaveAs)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::sendOpenProj)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sendMouseInput(QPointF _t1, QMouseEvent * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::sendButtonInput(QWidget * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::sendPropertyChange(Property _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::sendSaveAs()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MainWindow::sendOpenProj(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
