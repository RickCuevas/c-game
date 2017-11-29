/****************************************************************************
** Meta object code from reading C++ file 'weaponcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../weaponcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'weaponcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WeaponController_t {
    QByteArrayData data[8];
    char stringdata0[51];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WeaponController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WeaponController_t qt_meta_stringdata_WeaponController = {
    {
QT_MOC_LITERAL(0, 0, 16), // "WeaponController"
QT_MOC_LITERAL(1, 17, 5), // "index"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "show"
QT_MOC_LITERAL(4, 29, 2), // "id"
QT_MOC_LITERAL(5, 32, 6), // "create"
QT_MOC_LITERAL(6, 39, 4), // "save"
QT_MOC_LITERAL(7, 44, 6) // "remove"

    },
    "WeaponController\0index\0\0show\0id\0create\0"
    "save\0remove"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WeaponController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       1,   51, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    1,   40,    2, 0x0a /* Public */,
       5,    0,   43,    2, 0x0a /* Public */,
       6,    1,   44,    2, 0x0a /* Public */,
       7,    1,   47,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,

 // constructors: parameters
    0x80000000 | 2,

 // constructors: name, argc, parameters, tag, flags
       0,    0,   50,    2, 0x0e /* Public */,

       0        // eod
};

void WeaponController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { WeaponController *_r = new WeaponController();
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    } else if (_c == QMetaObject::InvokeMetaMethod) {
        WeaponController *_t = static_cast<WeaponController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->index(); break;
        case 1: _t->show((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->create(); break;
        case 3: _t->save((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->remove((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject WeaponController::staticMetaObject = {
    { &ApplicationController::staticMetaObject, qt_meta_stringdata_WeaponController.data,
      qt_meta_data_WeaponController,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *WeaponController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WeaponController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WeaponController.stringdata0))
        return static_cast<void*>(this);
    return ApplicationController::qt_metacast(_clname);
}

int WeaponController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ApplicationController::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
