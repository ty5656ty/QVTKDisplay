/****************************************************************************
** Meta object code from reading C++ file 'QVTKDisplay.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QVTKDisplay.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QVTKDisplay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QVTKDisplay_t {
    QByteArrayData data[10];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QVTKDisplay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QVTKDisplay_t qt_meta_stringdata_QVTKDisplay = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QVTKDisplay"
QT_MOC_LITERAL(1, 12, 13), // "sendXYReslice"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 13), // "sendXZReslice"
QT_MOC_LITERAL(4, 41, 13), // "sendYZReslice"
QT_MOC_LITERAL(5, 55, 9), // "XYReslice"
QT_MOC_LITERAL(6, 65, 5), // "index"
QT_MOC_LITERAL(7, 71, 3), // "ptr"
QT_MOC_LITERAL(8, 75, 9), // "XZReslice"
QT_MOC_LITERAL(9, 85, 9) // "YZReslice"

    },
    "QVTKDisplay\0sendXYReslice\0\0sendXZReslice\0"
    "sendYZReslice\0XYReslice\0index\0ptr\0"
    "XZReslice\0YZReslice"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QVTKDisplay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   47,    2, 0x09 /* Protected */,
       8,    2,   52,    2, 0x09 /* Protected */,
       9,    2,   57,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::VoidStar,    6,    7,
    QMetaType::Void, QMetaType::Double, QMetaType::VoidStar,    6,    7,
    QMetaType::Void, QMetaType::Double, QMetaType::VoidStar,    6,    7,

       0        // eod
};

void QVTKDisplay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QVTKDisplay *_t = static_cast<QVTKDisplay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendXYReslice(); break;
        case 1: _t->sendXZReslice(); break;
        case 2: _t->sendYZReslice(); break;
        case 3: _t->XYReslice((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< void*(*)>(_a[2]))); break;
        case 4: _t->XZReslice((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< void*(*)>(_a[2]))); break;
        case 5: _t->YZReslice((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< void*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QVTKDisplay::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QVTKDisplay::sendXYReslice)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QVTKDisplay::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QVTKDisplay::sendXZReslice)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QVTKDisplay::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QVTKDisplay::sendYZReslice)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject QVTKDisplay::staticMetaObject = {
    { &QVTKOpenGLWidget::staticMetaObject, qt_meta_stringdata_QVTKDisplay.data,
      qt_meta_data_QVTKDisplay,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QVTKDisplay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QVTKDisplay::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QVTKDisplay.stringdata0))
        return static_cast<void*>(const_cast< QVTKDisplay*>(this));
    return QVTKOpenGLWidget::qt_metacast(_clname);
}

int QVTKDisplay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QVTKOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void QVTKDisplay::sendXYReslice()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void QVTKDisplay::sendXZReslice()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void QVTKDisplay::sendYZReslice()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
