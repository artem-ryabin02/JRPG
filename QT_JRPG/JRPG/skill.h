#ifndef SKILL_H
#define SKILL_H

#include "effect.h"

#include <QString>

class Skill
{
public:

    Skill(QString name, int cost);
private:

    QString name;
    int cost;
    //Effect eff;
};

#endif // SKILL_H
