#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

#include <QRandomGenerator>

class Enemy : public Character
{
public:

    Enemy(QString name,
          int vitality,
          int strength,
          int wisdom,
          int intelligence,
          int agility,
          int perception,
          QString enemy_skill_id,
          QString pathName);
    int randAction();
    QString getEnemy_skill_id() const;

    QString getPathName() const;

private:
    QString pathName;
    QString enemy_skill_id;

};

#endif // ENEMY_H
