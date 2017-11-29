#ifndef BLOGCONTROLLER_H
#define BLOGCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT BlogController : public ApplicationController
{
    Q_OBJECT
public:
    Q_INVOKABLE
    BlogController() : ApplicationController() {}

public slots:
    void index();
    void welcome();
    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);
};

#endif // BLOGCONTROLLER_H