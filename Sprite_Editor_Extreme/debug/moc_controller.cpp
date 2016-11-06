/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Controller_t {
    QByteArrayData data[23];
    char stringdata0[310];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Controller_t qt_meta_stringdata_Controller = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Controller"
QT_MOC_LITERAL(1, 11, 9), // "sendImage"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 7), // "QImage*"
QT_MOC_LITERAL(4, 30, 16), // "sendPreviewImage"
QT_MOC_LITERAL(5, 47, 9), // "sendColor"
QT_MOC_LITERAL(6, 57, 10), // "sendFrames"
QT_MOC_LITERAL(7, 68, 19), // "std::vector<QImage>"
QT_MOC_LITERAL(8, 88, 19), // "sendFramesForExport"
QT_MOC_LITERAL(9, 108, 6), // "saveAs"
QT_MOC_LITERAL(10, 115, 12), // "sendNewFrame"
QT_MOC_LITERAL(11, 128, 14), // "sendActiveTool"
QT_MOC_LITERAL(12, 143, 15), // "sendDeleteFrame"
QT_MOC_LITERAL(13, 159, 13), // "receiveExport"
QT_MOC_LITERAL(14, 173, 18), // "receiveButtonInput"
QT_MOC_LITERAL(15, 192, 8), // "QWidget*"
QT_MOC_LITERAL(16, 201, 17), // "receiveMouseInput"
QT_MOC_LITERAL(17, 219, 12), // "QMouseEvent*"
QT_MOC_LITERAL(18, 232, 21), // "receivePropertyChange"
QT_MOC_LITERAL(19, 254, 8), // "Property"
QT_MOC_LITERAL(20, 263, 16), // "timeoutSendImage"
QT_MOC_LITERAL(21, 280, 13), // "receiveSaveAs"
QT_MOC_LITERAL(22, 294, 15) // "receiveOpenProj"

    },
    "Controller\0sendImage\0\0QImage*\0"
    "sendPreviewImage\0sendColor\0sendFrames\0"
    "std::vector<QImage>\0sendFramesForExport\0"
    "saveAs\0sendNewFrame\0sendActiveTool\0"
    "sendDeleteFrame\0receiveExport\0"
    "receiveButtonInput\0QWidget*\0"
    "receiveMouseInput\0QMouseEvent*\0"
    "receivePropertyChange\0Property\0"
    "timeoutSendImage\0receiveSaveAs\0"
    "receiveOpenProj"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controller[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       4,    1,   97,    2, 0x06 /* Public */,
       5,    1,  100,    2, 0x06 /* Public */,
       6,    2,  103,    2, 0x06 /* Public */,
       8,    1,  108,    2, 0x06 /* Public */,
       9,    1,  111,    2, 0x06 /* Public */,
      10,    1,  114,    2, 0x06 /* Public */,
      11,    1,  117,    2, 0x06 /* Public */,
      12,    1,  120,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,  123,    2, 0x0a /* Public */,
      14,    1,  124,    2, 0x0a /* Public */,
      16,    2,  127,    2, 0x0a /* Public */,
      18,    1,  132,    2, 0x0a /* Public */,
      20,    0,  135,    2, 0x0a /* Public */,
      21,    0,  136,    2, 0x0a /* Public */,
      22,    3,  137,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QColor,    2,
    QMetaType::Void, 0x80000000 | 7, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void, QMetaType::QPointF, 0x80000000 | 17,    2,    2,
    QMetaType::Void, 0x80000000 | 19,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,

       0        // eod
};

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Controller *_t = static_cast<Controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendImage((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        case 1: _t->sendPreviewImage((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        case 2: _t->sendColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 3: _t->sendFrames((*reinterpret_cast< std::vector<QImage>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->sendFramesForExport((*reinterpret_cast< std::vector<QImage>(*)>(_a[1]))); break;
        case 5: _t->saveAs((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->sendNewFrame((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        case 7: _t->sendActiveTool((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->sendDeleteFrame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->receiveExport(); break;
        case 10: _t->receiveButtonInput((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 11: _t->receiveMouseInput((*reinterpret_cast< QPointF(*)>(_a[1])),(*reinterpret_cast< QMouseEvent*(*)>(_a[2]))); break;
        case 12: _t->receivePropertyChange((*reinterpret_cast< Property(*)>(_a[1]))); break;
        case 13: _t->timeoutSendImage(); break;
        case 14: _t->receiveSaveAs(); break;
        case 15: _t->receiveOpenProj((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
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
            typedef void (Controller::*_t)(QImage * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::sendImage)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Controller::*_t)(QImage * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::sendPreviewImage)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Controller::*_t)(QColor );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::sendColor)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Controller::*_t)(std::vector<QImage> , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::sendFrames)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Controller::*_t)(std::vector<QImage> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::sendFramesForExport)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Controller::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::saveAs)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Controller::*_t)(QImage * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::sendNewFrame)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Controller::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::sendActiveTool)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (Controller::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Controller::sendDeleteFrame)) {
                *result = 8;
                return;
            }
        }
    }
}

const QMetaObject Controller::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Controller.data,
      qt_meta_data_Controller,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Controller.stringdata0))
        return static_cast<void*>(const_cast< Controller*>(this));
    return QObject::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void Controller::sendImage(QImage * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Controller::sendPreviewImage(QImage * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Controller::sendColor(QColor _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Controller::sendFrames(std::vector<QImage> _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Controller::sendFramesForExport(std::vector<QImage> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Controller::saveAs(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Controller::sendNewFrame(QImage * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Controller::sendActiveTool(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Controller::sendDeleteFrame(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
