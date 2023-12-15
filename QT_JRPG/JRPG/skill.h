#ifndef SKILL_H
#define SKILL_H

#include "effect.h"

#include <QString>

class Skill
{
public:
    Skill();
    explicit Skill(QString name, int cost, int effect_id, Effect eff);
private:
    QString name;
    int cost;
    int effect_id;
    Effect eff;
};

#endif // SKILL_H
