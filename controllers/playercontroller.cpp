#include "playercontroller.h"
#include "player.h"


void PlayerController::index()
{
    auto playerList = Player::getAll();
    texport(playerList);
    render();
}

void PlayerController::show(const QString &id)
{
    auto player = Player::get(id.toInt());
    texport(player);
    render();
}

void PlayerController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto player = httpRequest().formItems("player");
        auto model = Player::create(player);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(player);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void PlayerController::save(const QString &id)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = Player::get(id.toInt());
        if (!model.isNull()) {
            session().insert("player_lockRevision", model.lockRevision());
            auto player = model.toVariantMap();
            texport(player);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        int rev = session().value("player_lockRevision").toInt();
        auto model = Player::get(id.toInt(), rev);
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", id));
            break;
        }

        auto player = httpRequest().formItems("player");
        model.setProperties(player);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(player);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void PlayerController::remove(const QString &id)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto player = Player::get(id.toInt());
    player.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_DEFINE_CONTROLLER(PlayerController)
