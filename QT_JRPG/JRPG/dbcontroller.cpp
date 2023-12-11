#include "dbcontroller.h"

DBcontroller::DBcontroller()
{
    //    this->db = QSqlDatabase::addDatabase("QSQLITE");
    //    db.setDatabaseName(QDir::currentPath() + "/db/jrpg.sqlite");
    //    if (!db.open()) {
    //        qDebug() << "Error: Unable to open database";

    //    }
    //    else {
    //        qDebug() << "Database connection established.";
    //    }
}

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

    QSqlQuery query;
    query.prepare("SELECT "
                  "name, "
                  "vitality, "
                  "strength, "
                  "wisdom, "
                  "intelligence, "
                  "agility, "
                  "perception, "
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
            pathName = query.value(7).toString();

        }
    }
    return Enemy(name, vitality, strength, wisdom, intelligence, agility, perception, pathName);
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
