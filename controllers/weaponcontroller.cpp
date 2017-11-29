#include "weaponcontroller.h"
#include "weapon.h"


void WeaponController::index()
{
    auto weaponList = Weapon::getAll();
    texport(weaponList);
    render();
}

void WeaponController::show(const QString &id)
{
    auto weapon = Weapon::get(id.toInt());
    texport(weapon);
    render();
}

void WeaponController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto weapon = httpRequest().formItems("weapon");
        auto model = Weapon::create(weapon);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(weapon);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void WeaponController::save(const QString &id)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = Weapon::get(id.toInt());
        if (!model.isNull()) {
            session().insert("weapon_lockRevision", model.lockRevision());
            auto weapon = model.toVariantMap();
            texport(weapon);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        int rev = session().value("weapon_lockRevision").toInt();
        auto model = Weapon::get(id.toInt(), rev);
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", id));
            break;
        }

        auto weapon = httpRequest().formItems("weapon");
        model.setProperties(weapon);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(weapon);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void WeaponController::remove(const QString &id)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto weapon = Weapon::get(id.toInt());
    weapon.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_DEFINE_CONTROLLER(WeaponController)
