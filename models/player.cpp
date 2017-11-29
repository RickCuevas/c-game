#include <TreeFrogModel>
#include "player.h"
#include "playerobject.h"

Player::Player()
    : TAbstractModel(), d(new PlayerObject())
{
    d->id = 0;
    d->space = 0;
    d->xp = 0;
    d->lock_revision = 0;
}

Player::Player(const Player &other)
    : TAbstractModel(), d(new PlayerObject(*other.d))
{ }

Player::Player(const PlayerObject &object)
    : TAbstractModel(), d(new PlayerObject(object))
{ }

Player::~Player()
{
    // If the reference count becomes 0,
    // the shared data object 'PlayerObject' is deleted.
}

int Player::id() const
{
    return d->id;
}

QString Player::name() const
{
    return d->name;
}

void Player::setName(const QString &name)
{
    d->name = name;
}

int Player::space() const
{
    return d->space;
}

void Player::setSpace(int space)
{
    d->space = space;
}

int Player::xp() const
{
    return d->xp;
}

void Player::setXp(int xp)
{
    d->xp = xp;
}

QString Player::createdAt() const
{
    return d->created_at;
}

QString Player::updatedAt() const
{
    return d->updated_at;
}

int Player::lockRevision() const
{
    return d->lock_revision;
}

Player &Player::operator=(const Player &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Player Player::create(const QString &name, int space, int xp)
{
    PlayerObject obj;
    obj.name = name;
    obj.space = space;
    obj.xp = xp;
    if (!obj.create()) {
        return Player();
    }
    return Player(obj);
}

Player Player::create(const QVariantMap &values)
{
    Player model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Player Player::get(int id)
{
    TSqlORMapper<PlayerObject> mapper;
    return Player(mapper.findByPrimaryKey(id));
}

Player Player::get(int id, int lockRevision)
{
    TSqlORMapper<PlayerObject> mapper;
    TCriteria cri;
    cri.add(PlayerObject::Id, id);
    cri.add(PlayerObject::LockRevision, lockRevision);
    return Player(mapper.findFirst(cri));
}

int Player::count()
{
    TSqlORMapper<PlayerObject> mapper;
    return mapper.findCount();
}

QList<Player> Player::getAll()
{
    return tfGetModelListByCriteria<Player, PlayerObject>(TCriteria());
}

QJsonArray Player::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<PlayerObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<PlayerObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Player(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Player::modelData()
{
    return d.data();
}

const TModelObject *Player::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Player &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Player &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Player)
