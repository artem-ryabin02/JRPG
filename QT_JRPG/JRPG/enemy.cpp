#include "enemy.h"

Enemy::Enemy(QString name, int vitality, int strength, int wisdom, int intelligence, int agility, int perception, QString pathName)
    :Character(name, vitality, strength, wisdom, intelligence, agility, perception)
{
    this->pathName = pathName;
}

int Enemy::randAction()
{
    //    int action = QRandomGenerator::global()->bounded(100);

    //    if (health <= maxHealth && health > maxHealth / 2) {
    //        if (action <= 60) {
    //            return actionAttack;
    //        } else if (action > 60 && action <= 70) {
//            return actionDefence;
//        } else return actionSkill;
//    }
//    else  if (health <= maxHealth / 2 && health > maxHealth/4) {
//        if (action <= 40 ){
//            return actionAttack;
//        } else if (action > 40 && action <= 65){
//            return actionDefence;
//        } else return actionSkill;
//    }
//    else {
//        if (action <= 20 ){
//            return actionAttack;
//        } else if (action > 20 && action <= 60){
//            return actionDefence;
//        } else return actionSkill;
//    }
    return 0;
}
