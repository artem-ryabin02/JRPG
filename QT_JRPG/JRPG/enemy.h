#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

#include "skill.h"

#include <QRandomGenerator>

class Enemy : public Character
{
public:
//    enum class CONSTANS{
//        actionAttack = 1,
//        actionDefence = 2,
//        actionSkill = 3
//    };
    //Skill skl;

    Enemy(QString name, int vitality, int strength, int wisdom, int intelligence, int agility, int perception)
        :Character(name, vitality, strength, wisdom, intelligence, agility, perception){};
    //Enemy(){};

    int randAction();
};

#endif // ENEMY_H
