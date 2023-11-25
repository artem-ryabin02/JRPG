#ifndef HERO_H
#define HERO_H

#include "character.h"

class Hero : public Character
{
public:
    Hero(QString name, int vitality, int strength, int wisdom, int intelligence, int agility, int perception);
private:
    int loadCapacity;
    //Skill skl;
};

#endif // HERO_H
