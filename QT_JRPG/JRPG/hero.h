#ifndef HERO_H
#define HERO_H

#include "character.h"

class Hero : public Character
{
public:

    int loadCapacity;

    //Skill skl;

    Hero(QString name, int vitality, int strength, int wisdom, int intelligence, int agility, int perception);

};

#endif // HERO_H
