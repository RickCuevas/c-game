/****************************************************************************
** Meta object code from reading C++ file 'blogcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../blogcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'blogcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BlogController_t {
    QByteArrayData data[9];
    char stringdata0[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BlogController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BlogController_t qt_meta_stringdata_BlogController = {
    {
QT_MOC_LITERAL(0, 0, 14), // "BlogController"
QT_MOC_LITERAL(1, 15, 5), // "index"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 7), // "welcome"
QT_MOC_LITERAL(4, 30, 4), // "show"
QT_MOC_LITERAL(5, 35, 2), // "id"
QT_MOC_LITERAL(6, 38, 6), // "create"
QT_MOC_LITERAL(7, 45, 4), // "save"
QT_MOC_LITERAL(8, 50, 6) // "remove"

    },
    "BlogController\0index\0\0welcome\0show\0"
    "id\0create\0save\0remove"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BlogController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       1,   57, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x0a /* Public */,
       4,    1,   46,    2, 0x0a /* Public */,
       6,    0,   49,    2, 0x0a /* Public */,
       7,    1,   50,    2, 0x0a /* Public */,
       8,    1,   53,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,

 // constructors: parameters
    0x80000000 | 2,

 // constructors: name, argc, parameters, tag, flags
       0,    0,   56,    2, 0x0e /* Public */,

       0        // eod
};

void BlogController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::CreateInstance) {
        switch (_id) {
        case 0: { BlogController *_r = new BlogController();
            if (_a[0]) *reinterpret_cast<QObject**>(_a[0]) = _r; } break;
        default: break;
        }
    } else if (_c == QMetaObject::InvokeMetaMethod) {
        BlogController *_t = static_cast<BlogController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->index(); break;
        case 1: _t->welcome(); break;
        case 2: _t->show((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->create(); break;
        case 4: _t->save((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->remove((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject BlogController::staticMetaObject = {
    { &ApplicationController::staticMetaObject, qt_meta_stringdata_BlogController.data,
      qt_meta_data_BlogController,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BlogController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BlogController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BlogController.stringdata0))
        return static_cast<void*>(this);
    return ApplicationController::qt_metacast(_clname);
}

int BlogController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ApplicationController::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
