/****************************************************************************
** Meta object code from reading C++ file 'OGL.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "src/OGL.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OGL.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OGL_t {
    QByteArrayData data[15];
    char stringdata0[377];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OGL_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OGL_t qt_meta_stringdata_OGL = {
    {
QT_MOC_LITERAL(0, 0, 3), // "OGL"
QT_MOC_LITERAL(1, 4, 32), // "CameraAngleXDoubleSpinBoxChanged"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 5), // "value"
QT_MOC_LITERAL(4, 44, 32), // "CameraAngleYDoubleSpinBoxChanged"
QT_MOC_LITERAL(5, 77, 32), // "CameraAngleZDoubleSpinBoxChanged"
QT_MOC_LITERAL(6, 110, 28), // "CameraTXDoubleSpinBoxChanged"
QT_MOC_LITERAL(7, 139, 28), // "CameraTYDoubleSpinBoxChanged"
QT_MOC_LITERAL(8, 168, 28), // "CameraTZDoubleSpinBoxChanged"
QT_MOC_LITERAL(9, 197, 31), // "ModelAngleXDoubleSpinBoxChanged"
QT_MOC_LITERAL(10, 229, 31), // "ModelAngleYDoubleSpinBoxChanged"
QT_MOC_LITERAL(11, 261, 31), // "ModelAngleZDoubleSpinBoxChanged"
QT_MOC_LITERAL(12, 293, 27), // "ModelTXDoubleSpinBoxChanged"
QT_MOC_LITERAL(13, 321, 27), // "ModelTYDoubleSpinBoxChanged"
QT_MOC_LITERAL(14, 349, 27) // "ModelTZDoubleSpinBoxChanged"

    },
    "OGL\0CameraAngleXDoubleSpinBoxChanged\0"
    "\0value\0CameraAngleYDoubleSpinBoxChanged\0"
    "CameraAngleZDoubleSpinBoxChanged\0"
    "CameraTXDoubleSpinBoxChanged\0"
    "CameraTYDoubleSpinBoxChanged\0"
    "CameraTZDoubleSpinBoxChanged\0"
    "ModelAngleXDoubleSpinBoxChanged\0"
    "ModelAngleYDoubleSpinBoxChanged\0"
    "ModelAngleZDoubleSpinBoxChanged\0"
    "ModelTXDoubleSpinBoxChanged\0"
    "ModelTYDoubleSpinBoxChanged\0"
    "ModelTZDoubleSpinBoxChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OGL[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x0a /* Public */,
       4,    1,   77,    2, 0x0a /* Public */,
       5,    1,   80,    2, 0x0a /* Public */,
       6,    1,   83,    2, 0x0a /* Public */,
       7,    1,   86,    2, 0x0a /* Public */,
       8,    1,   89,    2, 0x0a /* Public */,
       9,    1,   92,    2, 0x0a /* Public */,
      10,    1,   95,    2, 0x0a /* Public */,
      11,    1,   98,    2, 0x0a /* Public */,
      12,    1,  101,    2, 0x0a /* Public */,
      13,    1,  104,    2, 0x0a /* Public */,
      14,    1,  107,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,

       0        // eod
};

void OGL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OGL *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->CameraAngleXDoubleSpinBoxChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->CameraAngleYDoubleSpinBoxChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->CameraAngleZDoubleSpinBoxChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->CameraTXDoubleSpinBoxChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->CameraTYDoubleSpinBoxChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->CameraTZDoubleSpinBoxChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->ModelAngleXDoubleSpinBoxChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->ModelAngleYDoubleSpinBoxChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->ModelAngleZDoubleSpinBoxChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->ModelTXDoubleSpinBoxChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->ModelTYDoubleSpinBoxChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->ModelTZDoubleSpinBoxChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject OGL::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_OGL.data,
    qt_meta_data_OGL,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *OGL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OGL::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OGL.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int OGL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
