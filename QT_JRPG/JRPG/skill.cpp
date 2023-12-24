#include "skill.h"

#include <QRandomGenerator>



Skill::Skill(QString name, int cost, QString type, int tier)
{
    this->name = name;
    this->cost = cost;
    this->type = type;
    this->tier = tier;
}

void Skill::useSkill(Character &user, Character &target)
{
    if(this->type == "лечение"){
        heal(user);
    }
    else if(this->type == "урон"){
        damage(target);
    }
}

void Skill::heal(Character &user)
{
    int maxHealth = user.getMaxHealth();
    int health = user.getHealth();
    int heal = maxHealth * 0.1 * tier;

    if ( maxHealth - health <= heal) {
        user.setHealth(maxHealth);
    } else {
        health += heal;
        user.setHealth(health);
    }
}

void Skill::damage(Character &target)
{
    int dodge = target.getDodge();
    int damage = causedDamage(dodge);
    int health = target.getHealth();
    if (damage >= health) {
        health = 0;
        target.setAlive(false);
    } else {
        health -= damage;
        if (health <= 0) {
            target.setAlive(false);
        }
    }
}

int Skill::causedDamage(int dodge)
{
    int hit = QRandomGenerator::global()->bounded(100);

    if (hit <= dodge * 2){
        return 0;
    } else {
        int damage = tier * ((hit % 10)+5);
        return damage;
    }
}

int Skill::getCost() const
{
    return cost;
}

QString Skill::getName() const
{
    return name;
}

