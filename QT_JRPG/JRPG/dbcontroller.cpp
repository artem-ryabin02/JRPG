#include "dbcontroller.h"
#include "skill.h"

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

Skill DBcontroller::randEnemySkill(QString enemy_skill)
{
    dbOpener();
    QString name = "";
    int cost = 0;
    QString type = "";
    int tier = 0;

    QSqlQuery query2;
    query2.prepare("SELECT name, cost, type, tier FROM skill WHERE ? = pool_id ORDER BY RANDOM() LIMIT 1");
    query2.addBindValue(enemy_skill);
    if (!query2.exec()) {
        qDebug() << "Error: Unable to execute query";
        qDebug() << query2.lastError().text();
    }
    else{
        while (query2.next()) {
            name = query2.value(0).toString();
            cost = query2.value(1).toInt();
            type = query2.value(2).toString();
            tier = query2.value(3).toInt();
        }
    }
    return Skill(name, cost, type, tier);
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
