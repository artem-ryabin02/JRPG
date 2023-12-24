#ifndef CHARACTER_H
#define CHARACTER_H

#include <QString>

class Character
{
public:

    Character(QString name, int vitality, int strength, int wisdom, int intelligence, int agility, int perception);
    //Character(){};

    void calculationOfSecondaryParametrs(int vitality, int strength, int wisdom, int intelligence, int agility, int perception);

    void displayStatus();

    void displayShortStatus();

    QString getName();

    void receivedDamage(int damage);

    int causedDamage(int enemyProtection, int enemyDodge);

    void defence();

    void removeDefence();

    void Heal (int heal);

    bool wastingMana(int amountOfMana);

    void manaRegeneration();

    bool getAlive() const;

    int getProtection() const;
    void setProtection(int newProtection);
    int getDodge() const;

    int getVitality() const;
    void setVitality(int newVitality);

    int getStrength() const;
    void setStrength(int newStrength);

    int getWisdom() const;
    void setWisdom(int newWisdom);

    int getIntelligence() const;
    void setIntelligence(int newIntelligence);

    int getAgility() const;
    void setAgility(int newAgility);

    int getPerception() const;
    void setPerception(int newPerception);

    int getMaxHealth() const;
    void setMaxHealth(int newMaxHealth);

    int getHealth() const;
    void setHealth(int newHealth);

    int getMaxMana() const;
    void setMaxMana(int newMaxMana);

    int getMana() const;
    void setMana(int newMana);

    int getManaRegen() const;
    void setManaRegen(int newManaRegen);

    int getAttack() const;
    void setAttack(int newAttack);

    int getCritChance() const;
    void setCritChance(int newCritChance);

    void setDodge(int newDodge);
    void setAlive(bool newAlive);

protected:
    int vitality, strength, wisdom, intelligence, agility, perception, maxHealth, health, maxMana,
        mana, manaRegen, attack, protection, critChance, dodge;
private:
    QString name;
    int tempDefence = 10;
    bool defenceFlag = false;
    bool alive = true;
};

#endif // CHARACTER_H
