package ru.morecode.JRPG.character;

public class Effect {
    String type;
    int tier;
    public Effect(String type, int tier){
        this.type = type;
        this.tier = tier;
    }
    public void doEffect(Character target){
        switch (type){
            case "лечение":{
                Heal(target,tier);
                break;
            }
        }
    }
    public void Heal(Character target, int tier){
        int heal = 10 * tier;
        if ( target.maxHealth - target.health <= heal) {
            target.health = target.maxHealth;
        } else {
            target.health += heal;
        }
    }
}
