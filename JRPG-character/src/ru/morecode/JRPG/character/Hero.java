package ru.morecode.JRPG.character;

public class Hero extends Character {

    private int loadCapacity;

    public Hero(String name, int vitality, int strength, int wisdom, int intelligence, int agility, int perception) {
        super(name, vitality, strength, wisdom, intelligence, agility, perception);
        loadCapacity = (vitality + strength) * 10;
    }



}
