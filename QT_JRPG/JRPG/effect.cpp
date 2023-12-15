#include "effect.h"

Effect::Effect(int id, QString type, int tier)
{
    this->id;
    this->type = type;
    this->tier = tier;
}

void Effect::doEffect(Character* user, Character* target){
    if(target == nullptr){
    switch (toIntType(type)){
    case HEAL:{
        Heal(user,tier);
        break;
    }
    }
    }
}
void Effect::Heal(Character* target, int tier){
    int vitality = target->getVitality();
    int wisdom = target->getWisdom();

    int heal = (vitality + wisdom / 2) * tier;

    int health = target->getHealth();
    int maxHealth = target->getMaxHealth();

    if ( maxHealth - health <= heal) {
        target->setHealth(maxHealth);
    } else {
        target->setHealth(health + heal);
    }
}

int Effect::toIntType(QString type)
{
    if(type == "лечение"){
        return HEAL;
    }
    return -1;
}
