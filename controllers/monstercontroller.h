#ifndef MONSTERCONTROLLER_H
#define MONSTERCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT MonsterController : public ApplicationController
{
    Q_OBJECT
public:
    Q_INVOKABLE
    MonsterController() : ApplicationController() {}

public slots:
    void index();
    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);
};

#endif // MONSTERCONTROLLER_H
