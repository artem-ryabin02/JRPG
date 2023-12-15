#include "enemy.h"

Enemy::Enemy(QString name, int vitality, int strength, int wisdom, int intelligence, int agility, int perception, QString enemy_skill_id, QString pathName)
    :Character(name, vitality, strength, wisdom, intelligence, agility, perception)
{
    this->pathName = pathName;
    this->enemy_skill_id = enemy_skill_id;
}

int Enemy::randAction()
{
    int action = QRandomGenerator::global()->bounded(100);

    if (health <= maxHealth && health > maxHealth / 2) {
        if (action <= 60) {
            return 1;
        } else if (action > 60 && action <= 70) {
            return 2;
        } else return 3;
    }
    else  if (health <= maxHealth / 2 && health > maxHealth/4) {
        if (action <= 40 ){
            return 1;
        } else if (action > 40 && action <= 65){
            return 2;
        } else return 3;
    }
    else {
        if (action <= 20 ){
            return 1;
        } else if (action > 20 && action <= 60){
            return 2;
        } else return 3;
    }
}

QString Enemy::getEnemy_skill_id() const
{
    return enemy_skill_id;
}

//void Enemy::setSk(const Skill &newSk)
//{
//    sk = newSk;
//}
