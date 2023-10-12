package ru.morecode.JRPG.character;

public class Enemy extends Character {
    final int actionAttack = 1;
    final int actionDefence = 2;
    final int actionSkill = 3;

    public Enemy(String name, int vitality, int strength, int wisdom, int intelligence, int agility, int perception) {
        super(name, vitality, strength, wisdom, intelligence, agility, perception);
    }


    public int randAction() {
        int action = (int) (Math.random() * (100 - 1 + 1)) + 1;

        if (health <= maxHealth && health > maxHealth / 2) {
            if (action <= 60) {
                return actionAttack;
            } else if (action > 60 && action <= 70) {
                return actionDefence;
            } else return actionSkill;
        }
        else  if (health <= maxHealth / 2 && health > maxHealth/4) {
            if (action <= 40 ){
                return actionAttack;
            } else if (action > 40 && action <= 65){
                return actionDefence;
            } else return actionSkill;
        }
        else {
            if (action <= 20 ){
                return actionAttack;
            } else if (action > 20 && action <= 60){
                return actionDefence;
            } else return actionSkill;
        }
    }
}
