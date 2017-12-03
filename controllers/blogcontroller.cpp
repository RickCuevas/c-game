#include "blogcontroller.h"
#include "blog.h"
#include "monster.h"
#include "weapon.h"
#include "player.h"
#include "../models/sqlobjects/playerobject.h"
#include "../models/sqlobjects/monsterobject.h"
#include "../models/sqlobjects/weaponobject.h"



void BlogController::index()
{
    // auto blogList = Blog::getAll();
    // texport(blogList);
    render();
}

void BlogController::show(const QString &id)
{
    auto blog = Blog::get(id.toInt());
    texport(blog);
    render();
}

void BlogController::welcome()
{
    render("welcome", "hello");
}

void BlogController::start()
{
    // make player
    PlayerObject player1;
    player1.space = 0;
    player1.create();



    //make monsters
    MonsterObject DragonSpawn;
    DragonSpawn.name = "DragonSpawn";
    DragonSpawn.space = 2;
    DragonSpawn.hp = 2 ;
    DragonSpawn.create();
    MonsterObject SeaMonster;
    SeaMonster.name = "SeaMonster";
    SeaMonster.space = 3 ;
    SeaMonster.hp = 2 ;
    SeaMonster.hp = 2 ;
    SeaMonster.create();
    MonsterObject Alien;
    Alien.name = "Alien";
    Alien.space = 4 ;
    Alien.hp = 2 ;
    Alien.create();
    MonsterObject Burro;
    Burro.name = "Burro";
    Burro.space = 5 ;
    Burro.hp = 2 ;
    Burro.create();
    MonsterObject KillerMouse;
    KillerMouse.name =  "KillerMouse";
    KillerMouse.space = 6 ;
    KillerMouse.hp = 2 ;
    KillerMouse.create();
    MonsterObject Gnome;
    Gnome.name = "Gnome";
    Gnome.space = 7 ;
    Gnome.hp = 2 ;
    Gnome.create();
    MonsterObject EvilAstronaut;
    EvilAstronaut.name =  "EvilAstronaut";
    EvilAstronaut.space = 8 ;
    EvilAstronaut.hp = 2 ;
    EvilAstronaut.create();
    MonsterObject Crocasaurouse;
    Crocasaurouse.name = "Crocasaurouse";
    Crocasaurouse.space = 9 ;
    Crocasaurouse.hp = 2 ;
    Crocasaurouse.create();
    MonsterObject Harpy;
    Harpy.name = "Harpy" ;
    Harpy.space = 10 ;
    Harpy.hp = 2 ;
    Harpy.create();
    MonsterObject Wolf;
    Wolf.name = "Wolf";
    Wolf.space = 11 ;
    Wolf.hp = 2 ;
    Wolf.create();
    MonsterObject DarkTinkerbell;
    DarkTinkerbell.name = "DarkTinkerbell";
    DarkTinkerbell.space = 12 ;
    DarkTinkerbell.hp = 2 ;
    DarkTinkerbell.create();
    MonsterObject Bear;
    Bear.name = "Bear" ;
    Bear.space = 13 ;
    Bear.hp = 2 ;
    Bear.create();
    MonsterObject Ghost;
    Ghost.name = "Ghost";
    Ghost.space = 14 ;
    Ghost.hp = 2 ;
    Ghost.create();
    MonsterObject Cyclopse;
    Cyclopse.name = "Cyclopse";
    Cyclopse.space = 15 ;
    Cyclopse.hp = 2 ;
    Cyclopse.create();
    MonsterObject Dragon;
    Dragon.name = "Dragon";
    Dragon.space = 16 ;
    Dragon.hp = 2 ;
    Dragon.create();
    //
    //make weapons
    WeaponObject BroadSword;
    BroadSword.name = "BroadSword";
    BroadSword.space = 17 ;
    BroadSword.attack = 2 ;
    BroadSword.create();
	WeaponObject DragonSlayer;
    DragonSlayer.name = "DragonSlayer";
    DragonSlayer.space = 18 ;
    DragonSlayer.attack = 2 ;
    DragonSlayer.create();
	WeaponObject Crossbow;
    Crossbow.name = "Crossbow";
    Crossbow.space = 19 ;
    Crossbow.attack = 2 ;
    Crossbow.create();
	WeaponObject Flail;
    Flail.name = "Flail";
    Flail.space = 20 ;
    Flail.attack = 2 ;
    Flail.create();
    WeaponObject SpellOfTheGods;
    SpellOfTheGods.name = "SpellOfTheGods";
    SpellOfTheGods.space = 21 ;
    SpellOfTheGods.attack = 2 ;
    SpellOfTheGods.create();


    // QString bar = DragonSpawn.name;
    //
    //   texport(bar);

    // int bar = Monster::count();
    // // cout << bar ;
    // texport(bar);
 redirect( urla("loop") );







    // redirect_to *******
}


void BlogController::loop()
{
 int dice = rand() % 6 + 1;
Player current_player = Player::get(1);
int current_player_space = current_player.space();
current_player.setSpace(current_player_space += dice);

int monster_length = Monster::count();
int weapon_length = Weapon::count();
QList<Monster> monsters =  Monster::getAll();
QList<Weapon> weapons = Weapon::getAll();

bool mfound = false;
bool wfound = false;
QString nothing_found = "Nothing...found";

for (int i=0; i < monster_length -1; i++) {
    if (monsters[i].space() == current_player.space()) {
        render("battle");
    }
}
for (int i=0; i < weapon_length -1; i++) {
    if (weapons[i].space() == current_player.space()) {
        render("equip");
    }
}

if (mfound == false && wfound == false) {
    nothing_found = "Nothing...found";

}
texport(nothing_found);
render();
}
void BlogController::battle()
{
    render();
}
void BlogController::equip()
{
    render();
}
void BlogController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto blog = httpRequest().formItems("blog");
        auto model = Blog::create(blog);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(blog);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void BlogController::save(const QString &id)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = Blog::get(id.toInt());
        if (!model.isNull()) {
            session().insert("blog_lockRevision", model.lockRevision());
            auto blog = model.toVariantMap();
            texport(blog);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        int rev = session().value("blog_lockRevision").toInt();
        auto model = Blog::get(id.toInt(), rev);

        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", id));
            break;
        }

        auto blog = httpRequest().formItems("blog");
        model.setProperties(blog);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(blog);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void BlogController::remove(const QString &id)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto blog = Blog::get(id.toInt());
    blog.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_DEFINE_CONTROLLER(BlogController)
