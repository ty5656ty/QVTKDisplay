/****************************************************************************
** Meta object code from reading C++ file 'QVTKReslice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QVTKReslice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QVTKReslice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QVTKReslice_t {
    QByteArrayData data[15];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QVTKReslice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QVTKReslice_t qt_meta_stringdata_QVTKReslice = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QVTKReslice"
QT_MOC_LITERAL(1, 12, 12), // "getXYReslice"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 5), // "index"
QT_MOC_LITERAL(4, 32, 3), // "ptr"
QT_MOC_LITERAL(5, 36, 12), // "getXZReslice"
QT_MOC_LITERAL(6, 49, 12), // "getYZReslice"
QT_MOC_LITERAL(7, 62, 9), // "XYReslice"
QT_MOC_LITERAL(8, 72, 9), // "XZReslice"
QT_MOC_LITERAL(9, 82, 9), // "YZReslice"
QT_MOC_LITERAL(10, 92, 13), // "getCurSelectX"
QT_MOC_LITERAL(11, 106, 1), // "p"
QT_MOC_LITERAL(12, 108, 13), // "getCurSelectY"
QT_MOC_LITERAL(13, 122, 14), // "getCurSelectXZ"
QT_MOC_LITERAL(14, 137, 14) // "getCurSelectYZ"

    },
    "QVTKReslice\0getXYReslice\0\0index\0ptr\0"
    "getXZReslice\0getYZReslice\0XYReslice\0"
    "XZReslice\0YZReslice\0getCurSelectX\0p\0"
    "getCurSelectY\0getCurSelectXZ\0"
    "getCurSelectYZ"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QVTKReslice[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,
       5,    2,   69,    2, 0x06 /* Public */,
       6,    2,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   79,    2, 0x0a /* Public */,
       8,    0,   80,    2, 0x0a /* Public */,
       9,    0,   81,    2, 0x0a /* Public */,
      10,    1,   82,    2, 0x0a /* Public */,
      12,    1,   85,    2, 0x0a /* Public */,
      13,    1,   88,    2, 0x0a /* Public */,
      14,    1,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::VoidStar,    3,    4,
    QMetaType::Void, QMetaType::Double, QMetaType::VoidStar,    3,    4,
    QMetaType::Void, QMetaType::Double, QMetaType::VoidStar,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void QVTKReslice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QVTKReslice *_t = static_cast<QVTKReslice *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getXYReslice((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< void*(*)>(_a[2]))); break;
        case 1: _t->getXZReslice((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< void*(*)>(_a[2]))); break;
        case 2: _t->getYZReslice((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< void*(*)>(_a[2]))); break;
        case 3: _t->XYReslice(); break;
        case 4: _t->XZReslice(); break;
        case 5: _t->YZReslice(); break;
        case 6: _t->getCurSelectX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->getCurSelectY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->getCurSelectXZ((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->getCurSelectYZ((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QVTKReslice::*_t)(double , void * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QVTKReslice::getXYReslice)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QVTKReslice::*_t)(double , void * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QVTKReslice::getXZReslice)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QVTKReslice::*_t)(double , void * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QVTKReslice::getYZReslice)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject QVTKReslice::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QVTKReslice.data,
      qt_meta_data_QVTKReslice,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QVTKReslice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QVTKReslice::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QVTKReslice.stringdata0))
        return static_cast<void*>(const_cast< QVTKReslice*>(this));
    return QWidget::qt_metacast(_clname);
}

int QVTKReslice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void QVTKReslice::getXYReslice(double _t1, void * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QVTKReslice::getXZReslice(double _t1, void * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QVTKReslice::getYZReslice(double _t1, void * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
