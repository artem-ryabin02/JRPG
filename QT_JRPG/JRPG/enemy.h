#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

#include "skill.h"

#include <QRandomGenerator>

class Enemy : public Character
{
public:    
    const int actionAttack = 1;
    const int actionDefence = 2;
    const int actionSkill = 3;

    //Skill skl;
    Enemy(QString name, int vitality, int strength, int wisdom, int intelligence, int agility, int perception, QString pathName);;

    int randAction();
private:
    QString pathName;
};

#endif // ENEMY_H
