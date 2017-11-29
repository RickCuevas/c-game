#include <TreeFrogModel>
#include "weapon.h"
#include "weaponobject.h"

Weapon::Weapon()
    : TAbstractModel(), d(new WeaponObject())
{
    d->id = 0;
    d->space = 0;
    d->attack = 0;
    d->lock_revision = 0;
}

Weapon::Weapon(const Weapon &other)
    : TAbstractModel(), d(new WeaponObject(*other.d))
{ }

Weapon::Weapon(const WeaponObject &object)
    : TAbstractModel(), d(new WeaponObject(object))
{ }

Weapon::~Weapon()
{
    // If the reference count becomes 0,
    // the shared data object 'WeaponObject' is deleted.
}

int Weapon::id() const
{
    return d->id;
}

QString Weapon::name() const
{
    return d->name;
}

void Weapon::setName(const QString &name)
{
    d->name = name;
}

int Weapon::space() const
{
    return d->space;
}

void Weapon::setSpace(int space)
{
    d->space = space;
}

int Weapon::attack() const
{
    return d->attack;
}

void Weapon::setAttack(int attack)
{
    d->attack = attack;
}

QString Weapon::createdAt() const
{
    return d->created_at;
}

QString Weapon::updatedAt() const
{
    return d->updated_at;
}

int Weapon::lockRevision() const
{
    return d->lock_revision;
}

Weapon &Weapon::operator=(const Weapon &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Weapon Weapon::create(const QString &name, int space, int attack)
{
    WeaponObject obj;
    obj.name = name;
    obj.space = space;
    obj.attack = attack;
    if (!obj.create()) {
        return Weapon();
    }
    return Weapon(obj);
}

Weapon Weapon::create(const QVariantMap &values)
{
    Weapon model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Weapon Weapon::get(int id)
{
    TSqlORMapper<WeaponObject> mapper;
    return Weapon(mapper.findByPrimaryKey(id));
}

Weapon Weapon::get(int id, int lockRevision)
{
    TSqlORMapper<WeaponObject> mapper;
    TCriteria cri;
    cri.add(WeaponObject::Id, id);
    cri.add(WeaponObject::LockRevision, lockRevision);
    return Weapon(mapper.findFirst(cri));
}

int Weapon::count()
{
    TSqlORMapper<WeaponObject> mapper;
    return mapper.findCount();
}

QList<Weapon> Weapon::getAll()
{
    return tfGetModelListByCriteria<Weapon, WeaponObject>(TCriteria());
}

QJsonArray Weapon::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<WeaponObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<WeaponObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Weapon(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Weapon::modelData()
{
    return d.data();
}

const TModelObject *Weapon::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Weapon &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Weapon &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Weapon)
