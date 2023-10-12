import ru.morecode.JRPG.character.Enemy;
import ru.morecode.JRPG.character.Hero;
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
                    System.out.println("крыса лечится");
                    RAT.Heal(5);
                }
                flag = false;
            }
            else {
                her.removeDefence();
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
                        her.Heal(10);
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

