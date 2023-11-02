package ru.morecode.JRPG.character;

import java.util.Scanner;

public class BattleArena {
    public static void main(String[] args) {
        Hero her = new Hero("герой",5,3,7,9,6,7);
        Enemy RAT = new Enemy("крыс",1,7,1,8,3,6);
        her.displayStatus();
        System.out.println("-----------------------------------------------------------");
        RAT.displayStatus();
        System.out.println("BATTLE BEGINS!!!!");
        boolean flag = true;
        while(her.getAlive() && RAT.getAlive() ){
            if (flag) {
                RAT.removeDefence();
                RAT.manaRegeneration();
                RAT.displayShortStatus();
                int action = RAT.randAction();
                if (action == 1) {
                    System.out.println("крыса атакует");
                    her.receivedDamage(RAT.causedDamage(her.getProtection(), her.getDodge()));
                }
                if (action == 2) {
                    System.out.println("крыса защищается");
                    RAT.Defence();
                }
                if (action == 3) {
                    if (RAT.wastingMana(3)){
                        System.out.println("крыса лечится");
                        RAT.Heal(5);
                    }else{
                        System.out.println("крыса не смогла вылечится, из-за не хватки маны");
                    }
                }
                flag = false;
            }
            else {
                her.removeDefence();
                her.manaRegeneration();
                her.displayShortStatus();
                Scanner in = new Scanner(System.in);
                System.out.println("что делаем?");
                System.out.println("атака");
                System.out.println("защита");
                System.out.println("лечение");
                System.out.println("пропуск");
                System.out.println("выбранное действие:");
                String action = in.next();
                switch (action) {
                    case "атака" -> {
                        RAT.receivedDamage(her.causedDamage(RAT.getProtection(), RAT.getDodge()));
                        break;
                    }
                    case "защита" -> {
                        her.Defence();
                        break;
                    }
                    case "лечение" -> {
                        if (her.wastingMana(5)){
                            her.Heal(10);
                        }else {
                            System.out.println("Маны не хватило, а ход потрачен");
                        }
                        break;
                    }
                    case "пропуск" -> {
                        break;
                    }
                }
                flag = true;
            }
        }
        System.out.println("battle is over");
        if(her.getAlive())
            System.out.println(her.getName()+" is winner");
        else {
            System.out.println(RAT.getName()+" is winner");
        }
    }
}

