#include "dbcontroller.h"

Enemy DBcontroller::randEnemy()
{
    dbOpener();
    QString name = "";
    int vitality = 0;
    int strength = 0;
    int wisdom = 0;
    int intelligence = 0;
    int agility = 0;
    int perception = 0;
    QString pathName = "";
    QString enemy_skill;
    QSqlQuery query;
    query.prepare("SELECT "
                  "name, "
                  "vitality, "
                  "strength, "
                  "wisdom, "
                  "intelligence, "
                  "agility, "
                  "perception, "
                  "skill_id, "
                  "image "
                  "FROM enemy ORDER BY RANDOM() LIMIT 1 ");
    if (!query.exec()) {
        qDebug() << "Error: Unable to execute query";
        qDebug() << query.lastError().text();
    }
    else{
        while (query.next()) {
            name = query.value(0).toString();
            vitality = query.value(1).toInt();
            strength = query.value(2).toInt();
            wisdom = query.value(3).toInt();
            intelligence = query.value(4).toInt();
            agility = query.value(5).toInt();
            perception = query.value(6).toInt();
            enemy_skill = query.value(7).toString();
            pathName = query.value(8).toString();
        }
    }
    return Enemy(name, vitality, strength, wisdom, intelligence, agility, perception, enemy_skill, pathName);
}

Skill DBcontroller::randEnemySkill(QString _enemy_skill)
{
    dbOpener();
    QString name = "";
    int cost = 0;
    int effect_id = 0;
    QString enemy_skill_id = _enemy_skill;

    QSqlQuery query;
    query.prepare("SELECT name, cost, effect_id FROM effect WHERE ? = enemy_skill_id ORDER BY RANDOM() LIMIT 1");
    query.addBindValue(enemy_skill_id);
    if (!query.exec()) {
        qDebug() << "Error: Unable to execute query";
        qDebug() << query.lastError().text();
    }
    else{
        while (query.next()) {
            name = query.value(0).toString();
            cost = query.value(1).toInt();
            effect_id = query.value(2).toInt();
            qDebug() << name <<" "<< cost<<" "<<effect_id;
        }
    }
    return Skill(name, cost, effect_id, makeEffect(effect_id));
}

Effect DBcontroller::makeEffect(int _id)
{
    dbOpener();
    int id = 0;
    QString type = "";
    int tier = 0;
    QSqlQuery query;
    query.prepare("SELECT * FROM effect WHERE ? = id ");
    query.addBindValue(_id);
    if (!query.exec()) {
        qDebug() << "Error: Unable to execute query";
        qDebug() << query.lastError().text();
    }
    else{
        while (query.next()) {
            id = query.value(0).toInt();
            type = query.value(1).toString();
            tier = query.value(2).toInt();
        }
    }
    return Effect(id, type, tier);
}

void DBcontroller::dbOpener()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QSqlError err;
    db.setDatabaseName(QDir::currentPath() + "/db/jrpg.sqlite");
    if (!db.open()) {
        qDebug() << "Error: Unable to open database";
        qDebug() << err.databaseText();
    }
    else {
        qDebug() << "Database connection established.";
    }
}
