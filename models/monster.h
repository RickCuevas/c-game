#ifndef MONSTER_H
#define MONSTER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class MonsterObject;
class QJsonArray;


class T_MODEL_EXPORT Monster : public TAbstractModel
{
public:
    Monster();
    Monster(const Monster &other);
    Monster(const MonsterObject &object);
    ~Monster();

    int id() const;
    QString name() const;
    void setName(const QString &name);
    int space() const;
    void setSpace(int space);
    int hp() const;
    void setHp(int hp);
    QString createdAt() const;
    QString updatedAt() const;
    int lockRevision() const;
    Monster &operator=(const Monster &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Monster create(const QString &name, int space, int hp);
    static Monster create(const QVariantMap &values);
    static Monster get(int id);
    static Monster get(int id, int lockRevision);
    static int count();
    static QList<Monster> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<MonsterObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Monster &model);
    friend QDataStream &operator>>(QDataStream &ds, Monster &model);
};

Q_DECLARE_METATYPE(Monster)
Q_DECLARE_METATYPE(QList<Monster>)

#endif // MONSTER_H
