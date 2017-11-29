#ifndef WEAPON_H
#define WEAPON_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class WeaponObject;
class QJsonArray;


class T_MODEL_EXPORT Weapon : public TAbstractModel
{
public:
    Weapon();
    Weapon(const Weapon &other);
    Weapon(const WeaponObject &object);
    ~Weapon();

    int id() const;
    QString name() const;
    void setName(const QString &name);
    int space() const;
    void setSpace(int space);
    int attack() const;
    void setAttack(int attack);
    QString createdAt() const;
    QString updatedAt() const;
    int lockRevision() const;
    Weapon &operator=(const Weapon &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Weapon create(const QString &name, int space, int attack);
    static Weapon create(const QVariantMap &values);
    static Weapon get(int id);
    static Weapon get(int id, int lockRevision);
    static int count();
    static QList<Weapon> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<WeaponObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Weapon &model);
    friend QDataStream &operator>>(QDataStream &ds, Weapon &model);
};

Q_DECLARE_METATYPE(Weapon)
Q_DECLARE_METATYPE(QList<Weapon>)

#endif // WEAPON_H
