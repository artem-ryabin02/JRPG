#include "character.h"

#include <QDebug>
#include <QString>
#include <QRandomGenerator>

Character::Character(QString name, int vitality, int strength, int wisdom, int intelligence, int agility, int perception){

    this->name = name;
    this->vitality = vitality;
    this->strength = strength;
    this->wisdom = wisdom;
    this->intelligence = intelligence;
    this->agility = agility;
    this->perception = perception;

    calculationOfSecondaryParametrs(vitality, strength, wisdom, intelligence, agility, perception);

}

void Character::calculationOfSecondaryParametrs(int vitality, int strength, int wisdom, int intelligence, int agility, int perception) {
    this->maxHealth = vitality * 20;
    this->health = maxHealth;
    this->maxMana = (int) ((intelligence + wisdom) * 15);
    this->mana = maxMana;
    this->manaRegen = (int) (wisdom * 0.3);
    this->attack = (int) (strength + agility * 0.25);
    this->protection = (int) (vitality * 1.25);
    this->critChance = (int) ((agility * 0.05 + perception * 0.07) * 10);
    this->dodge = (int) ((agility * 2 + perception * 0.2));
}

void Character::displayStatus(){
    qDebug() << "name: " + name << "\n";
    qDebug() << "vitality: " << vitality << "\n";
    qDebug() << "strength: " << strength << "\n";
    qDebug() << "wisdom: " << wisdom << "\n";
    qDebug() << "intelligence: " << intelligence << "\n";
    qDebug() << "agility: " << agility << "\n";
    qDebug() << "perception: " << perception;
    qDebug() << "health/maxHealth:" << health << "/" << maxHealth << "\n";
    qDebug() << "mana/maxMana: " << mana << "/" << maxMana << "\n";
    qDebug() << "manaRegen: " << manaRegen << "\n";
    qDebug() << "attack: " << attack << "\n";
    qDebug() << "protection: " << protection << "\n";
    qDebug() << "critChance: " << critChance << "\n";
    qDebug() << "dodge: " << dodge << "\n";
}

void Character::displayShortStatus(){
    qDebug() << "name: " + name;
    qDebug() << "health/maxHealth:" << health << "/" << maxHealth << "\n";
    qDebug() << "mana/maxMana: " << mana << "/" << maxMana << "\n";
}

QString Character::getName() {
    return this->name;
}

void Character::receivedDamage(int damage){

        if (damage >= health) {
            health = 0;
            alive = false;
        } else {
            health -= damage;
            if (health <= 0) {
                alive = false;
            }
        }
        qDebug() << name << " получил урон " << " health/maxHealth:" <<
                    health << "/" << maxHealth << "\n";
    }

int Character::causedDamage(int enemyProtection, int enemyDodge){
        int hit = QRandomGenerator::global()->bounded(100);

        if (hit <= enemyDodge){
            return 0;
        } else if (hit >= 100 - critChance){
            qDebug() << "oh my God! Crit";

            return  (5 + attack + (hit % 10)) * 2;
        } else {
            int damage = 5 + attack - enemyProtection + (hit % 10);

            if (damage < 0 ){
                return 0;
            } else return damage;
        }
}

void Character::defence(){
        protection += tempDefence;
        defenceFlag = true;
}

void Character::removeDefence(){
        if (defenceFlag) {
            protection -= tempDefence;
            defenceFlag = false;
        }
}

void Character::Heal (int heal) {
        if ( maxHealth - health <= heal) {
            health = maxHealth;
        } else {
            health += heal;
        }
}
bool Character::wastingMana(int amountOfMana){
        if (amountOfMana <= mana){
            mana -= amountOfMana;
            return true;
        } else return false;
}
void Character::manaRegeneration(){
        if (mana + manaRegen >= maxMana){
            mana = maxMana;
        } else {
            mana+=manaRegen;
        }
}
bool Character::getAlive () const{
        return alive;
}

int Character::getProtection() const {
        return protection;
}

void Character::setProtection(int newProtection)
{
        protection = newProtection;
}
int Character::getDodge() const {
        return dodge;
}

void Character::setDodge(int newDodge)
{
        dodge = newDodge;
}

void Character::setAlive(bool newAlive)
{
        alive = newAlive;
}
int Character::getVitality() const
{
        return vitality;
}

void Character::setVitality(int newVitality)
{
        vitality = newVitality;
}

int Character::getStrength() const
{
        return strength;
}

void Character::setStrength(int newStrength)
{
        strength = newStrength;
}

int Character::getWisdom() const
{
        return wisdom;
}

void Character::setWisdom(int newWisdom)
{
        wisdom = newWisdom;
}

int Character::getIntelligence() const
{
        return intelligence;
}

void Character::setIntelligence(int newIntelligence)
{
        intelligence = newIntelligence;
}

int Character::getAgility() const
{
        return agility;
}

void Character::setAgility(int newAgility)
{
        agility = newAgility;
}

int Character::getPerception() const
{
        return perception;
}

void Character::setPerception(int newPerception)
{
        perception = newPerception;
}

int Character::getMaxHealth() const
{
        return maxHealth;
}

void Character::setMaxHealth(int newMaxHealth)
{
        maxHealth = newMaxHealth;
}

int Character::getHealth() const
{
        return health;
}

void Character::setHealth(int newHealth)
{
        health = newHealth;
}

int Character::getMaxMana() const
{
        return maxMana;
}

void Character::setMaxMana(int newMaxMana)
{
        maxMana = newMaxMana;
}

int Character::getMana() const
{
        return mana;
}

void Character::setMana(int newMana)
{
        mana = newMana;
}

int Character::getManaRegen() const
{
        return manaRegen;
}

void Character::setManaRegen(int newManaRegen)
{
        manaRegen = newManaRegen;
}

int Character::getAttack() const
{
        return attack;
}

void Character::setAttack(int newAttack)
{
        attack = newAttack;
}

int Character::getCritChance() const
{
        return critChance;
}

void Character::setCritChance(int newCritChance)
{
        critChance = newCritChance;
}




