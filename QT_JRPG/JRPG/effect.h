#ifndef EFFECT_H
#define EFFECT_H

#include "character.h"

#include <QString>

class Effect
{
public: 
    QString type;
    int tier;

    Effect(QString type, int tier);

    void doEffect(Character target);

    void Heal(Character target, int tier);

private:
    int toIntType(QString type);

    enum Constants{
        HEAL = 0,

    };
};

#endif // EFFECT_H
