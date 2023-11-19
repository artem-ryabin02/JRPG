#include "effect.h"

Effect::Effect(QString type, int tier)
{
    this->type = type;
    this->tier = tier;
}

void Effect::doEffect(Character target){
    switch (toIntType(type)){
    case HEAL:{
        Heal(target,tier);
        break;
    }
    }
}
void Effect::Heal(Character target, int tier){
    int heal = 10 * tier;
    if ( target.maxHealth - target.health <= heal) {
        target.health = target.maxHealth;
    } else {
        target.health += heal;
    }
}

int Effect::toIntType(QString type)
{
    if(type == "лечение"){
        return HEAL;
    }
}
