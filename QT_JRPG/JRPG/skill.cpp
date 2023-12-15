#include "skill.h"


Skill::Skill(QString name, int cost, int effect_id, Effect _eff) : eff(-1,"",-1)
{
    this->name = name;
    this->cost = cost;
    this->effect_id = effect_id;
    this->eff = _eff;
}
