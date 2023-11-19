#ifndef CHARACTER_H
#define CHARACTER_H

#include <QString>

class Character
{
public:

    QString name;

    Character(QString name, int vitality, int strength, int wisdom, int intelligence, int agility, int perception);

    int vitality, strength, wisdom, intelligence, agility, perception, maxHealth, health, maxMana,
        mana, manaRegen, attack, protection, critChance, dodge, tempDefence = 10;

    bool defenceFlag = false;

    bool alive = true;

    void calculationOfSecondaryParametrs(int vitality, int strength, int wisdom, int intelligence, int agility, int perception);

    void displayStatus();

    void displayShortStatus();

    QString getName();

    void receivedDamage(int damage);

    int causedDamage(int enemyProtection, int enemyDodge);

    void Defence();

    void removeDefence();

    void Heal (int heal);

    bool wastingMana(int amountOfMana);

    void manaRegeneration();

    bool getAlive ();

    int getProtection();

    int getDodge();
};

#endif // CHARACTER_H
