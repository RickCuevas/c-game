#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT PlayerController : public ApplicationController
{
    Q_OBJECT
public:
    Q_INVOKABLE
    PlayerController() : ApplicationController() {}

public slots:
    void index();
    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);
};

#endif // PLAYERCONTROLLER_H
