#ifndef EFFECT_H
#define EFFECT_H

#include "character.h"
#include <QString>

class Effect
{
public:
    Effect(QString type, int tier);

    void doEffect(Character* user, Character* target = nullptr);

    void Heal(Character* target, int tier);
private:
    QString type;
    int tier;
    int toIntType(QString type);

    enum Constants{
        HEAL = 0,

    };
};

#endif // EFFECT_H
