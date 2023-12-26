#include "hero.h"

Hero::Hero(QString name, int vitality, int strength, int wisdom, int intelligence, int agility, int perception)
    :Character(name, vitality, strength, wisdom, intelligence, agility, perception){
    loadCapacity = (vitality + strength) * 10;
}

bool Hero::getIsQuest() const
{
    return isQuest;
}

void Hero::setIsQuest(bool newIsQuest)
{
    isQuest = newIsQuest;
    checkReady();
}

bool Hero::getReadyQuest() const
{
    return readyQuest;
}

void Hero::setReadyQuest(bool newReadyQuest)
{
    readyQuest = newReadyQuest;
}

int Hero::getCounterQuest() const
{
    return counterQuest;
}

void Hero::setCounterQuest(int newCounterQuest)
{
    counterQuest = newCounterQuest;
    checkReady();
}

int Hero::getMission() const
{
    return mission;
}

void Hero::setMission(int newMission)
{
    mission = newMission;
}

void Hero::checkReady()
{
    if (counterQuest >= mission){
        readyQuest = true;
    }
    else readyQuest = false;
}
