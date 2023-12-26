#ifndef HERO_H
#define HERO_H

#include "character.h"

class Hero : public Character
{
public:
    Hero(QString name, int vitality, int strength, int wisdom, int intelligence, int agility, int perception);
    //Hero(){};
    bool getIsQuest() const;
    void setIsQuest(bool newIsQuest);

    bool getReadyQuest() const;
    void setReadyQuest(bool newReadyQuest);

    int getCounterQuest() const;
    void setCounterQuest(int newCounterQuest);

    int getMission() const;
    void setMission(int newMission);

    void checkReady();
private:
    int loadCapacity;

    bool isQuest;
    bool readyQuest;
    int mission = 1;
    int counterQuest = 0;

    //Skill skl;
};

#endif // HERO_H
