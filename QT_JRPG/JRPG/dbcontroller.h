#ifndef DBCONTROLLER_H
#define DBCONTROLLER_H

#include <QSqlDriver>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDir>
#include "enemy.h"
class DBcontroller
{
public:
    DBcontroller();
    ~DBcontroller(){};
    static Enemy randEnemy();
    static Skill randEnemySkill(QString enemy_skill);
    static Effect makeEffect(int id);
private:
    static void dbOpener();
};

#endif // DBCONTROLLER_H
