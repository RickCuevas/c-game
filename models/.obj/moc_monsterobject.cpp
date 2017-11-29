/****************************************************************************
** Meta object code from reading C++ file 'monsterobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sqlobjects/monsterobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'monsterobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MonsterObject_t {
    QByteArrayData data[8];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MonsterObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MonsterObject_t qt_meta_stringdata_MonsterObject = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MonsterObject"
QT_MOC_LITERAL(1, 14, 2), // "id"
QT_MOC_LITERAL(2, 17, 4), // "name"
QT_MOC_LITERAL(3, 22, 5), // "space"
QT_MOC_LITERAL(4, 28, 2), // "hp"
QT_MOC_LITERAL(5, 31, 10), // "created_at"
QT_MOC_LITERAL(6, 42, 10), // "updated_at"
QT_MOC_LITERAL(7, 53, 13) // "lock_revision"

    },
    "MonsterObject\0id\0name\0space\0hp\0"
    "created_at\0updated_at\0lock_revision"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MonsterObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       7,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Int, 0x00095003,
       2, QMetaType::QString, 0x00095003,
       3, QMetaType::Int, 0x00095003,
       4, QMetaType::Int, 0x00095003,
       5, QMetaType::QString, 0x00095003,
       6, QMetaType::QString, 0x00095003,
       7, QMetaType::Int, 0x00095003,

       0        // eod
};

void MonsterObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        MonsterObject *_t = static_cast<MonsterObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getid(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getname(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->getspace(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->gethp(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->getcreated_at(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->getupdated_at(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->getlock_revision(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        MonsterObject *_t = static_cast<MonsterObject *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setid(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setname(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setspace(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->sethp(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setcreated_at(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setupdated_at(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->setlock_revision(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject MonsterObject::staticMetaObject = {
    { &TSqlObject::staticMetaObject, qt_meta_stringdata_MonsterObject.data,
      qt_meta_data_MonsterObject,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MonsterObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MonsterObject::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MonsterObject.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QSharedData"))
        return static_cast< QSharedData*>(this);
    return TSqlObject::qt_metacast(_clname);
}

int MonsterObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TSqlObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
   if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
