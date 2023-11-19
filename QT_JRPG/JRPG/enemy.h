#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

#include <QRandomGenerator>

class Enemy : public Character
{
public:    
    const int actionAttack = 1;
    const int actionDefence = 2;
    const int actionSkill = 3;

    //Skill skl;

    Enemy(QString name, int vitality, int strength, int wisdom, int intelligence, int agility, int perception)
        :Character(name, vitality, strength, wisdom, intelligence, agility, perception){};

    int randAction();
};

#endif // ENEMY_H
