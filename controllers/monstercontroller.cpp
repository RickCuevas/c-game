#include "monstercontroller.h"
#include "monster.h"


void MonsterController::index()
{
    auto monsterList = Monster::getAll();
    texport(monsterList);
    render();
}

void MonsterController::show(const QString &id)
{
    auto monster = Monster::get(id.toInt());
    texport(monster);
    render();
}

void MonsterController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto monster = httpRequest().formItems("monster");
        auto model = Monster::create(monster);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(monster);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void MonsterController::save(const QString &id)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = Monster::get(id.toInt());
        if (!model.isNull()) {
            session().insert("monster_lockRevision", model.lockRevision());
            auto monster = model.toVariantMap();
            texport(monster);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        int rev = session().value("monster_lockRevision").toInt();
        auto model = Monster::get(id.toInt(), rev);
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", id));
            break;
        }

        auto monster = httpRequest().formItems("monster");
        model.setProperties(monster);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(monster);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void MonsterController::remove(const QString &id)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto monster = Monster::get(id.toInt());
    monster.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_DEFINE_CONTROLLER(MonsterController)
