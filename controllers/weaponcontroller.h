#ifndef WEAPONCONTROLLER_H
#define WEAPONCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT WeaponController : public ApplicationController
{
    Q_OBJECT
public:
    Q_INVOKABLE
    WeaponController() : ApplicationController() {}

public slots:
    void index();
    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);
};

#endif // WEAPONCONTROLLER_H
