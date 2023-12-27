#ifndef SKILL_H
#define SKILL_H



#include "character.h"
#include <QString>

class Skill
{
public:
    Skill();
    Skill(QString name, int cost, QString type, int tier);
    void useSkill(Character &user, Character &target);
    void heal(Character &user);
    void damage(Character &target);

    QString getName() const;

    int getCost() const;

    void setCost(int newCost);

private:
    int causedDamage(int dodge);
    QString name;
    int cost;
    QString type;
    int tier;
};

#endif // SKILL_H
