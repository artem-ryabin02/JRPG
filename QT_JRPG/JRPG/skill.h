#ifndef SKILL_H
#define SKILL_H

#include "effect.h"

#include <QString>

class Skill
{
public:

    QString name;

    int cost;

    //Effect eff;

    Skill(QString name, int cost){};
};

#endif // SKILL_H
