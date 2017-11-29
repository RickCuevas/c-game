#include <TreeFrogModel>
#include "monster.h"
#include "monsterobject.h"

Monster::Monster()
    : TAbstractModel(), d(new MonsterObject())
{
    d->id = 0;
    d->space = 0;
    d->hp = 0;
    d->lock_revision = 0;
}

Monster::Monster(const Monster &other)
    : TAbstractModel(), d(new MonsterObject(*other.d))
{ }

Monster::Monster(const MonsterObject &object)
    : TAbstractModel(), d(new MonsterObject(object))
{ }

Monster::~Monster()
{
    // If the reference count becomes 0,
    // the shared data object 'MonsterObject' is deleted.
}

int Monster::id() const
{
    return d->id;
}

QString Monster::name() const
{
    return d->name;
}

void Monster::setName(const QString &name)
{
    d->name = name;
}

int Monster::space() const
{
    return d->space;
}

void Monster::setSpace(int space)
{
    d->space = space;
}

int Monster::hp() const
{
    return d->hp;
}

void Monster::setHp(int hp)
{
    d->hp = hp;
}

QString Monster::createdAt() const
{
    return d->created_at;
}

QString Monster::updatedAt() const
{
    return d->updated_at;
}

int Monster::lockRevision() const
{
    return d->lock_revision;
}

Monster &Monster::operator=(const Monster &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Monster Monster::create(const QString &name, int space, int hp)
{
    MonsterObject obj;
    obj.name = name;
    obj.space = space;
    obj.hp = hp;
    if (!obj.create()) {
        return Monster();
    }
    return Monster(obj);
}

Monster Monster::create(const QVariantMap &values)
{
    Monster model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Monster Monster::get(int id)
{
    TSqlORMapper<MonsterObject> mapper;
    return Monster(mapper.findByPrimaryKey(id));
}

Monster Monster::get(int id, int lockRevision)
{
    TSqlORMapper<MonsterObject> mapper;
    TCriteria cri;
    cri.add(MonsterObject::Id, id);
    cri.add(MonsterObject::LockRevision, lockRevision);
    return Monster(mapper.findFirst(cri));
}

int Monster::count()
{
    TSqlORMapper<MonsterObject> mapper;
    return mapper.findCount();
}

QList<Monster> Monster::getAll()
{
    return tfGetModelListByCriteria<Monster, MonsterObject>(TCriteria());
}

QJsonArray Monster::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<MonsterObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<MonsterObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Monster(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Monster::modelData()
{
    return d.data();
}

const TModelObject *Monster::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Monster &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Monster &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Monster)
