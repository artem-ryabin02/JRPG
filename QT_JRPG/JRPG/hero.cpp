#include "hero.h"

Hero::Hero(QString name, int vitality, int strength, int wisdom, int intelligence, int agility, int perception)
    :Character(name, vitality, strength, wisdom, intelligence, agility, perception){
    loadCapacity = (vitality + strength) * 10;
}
