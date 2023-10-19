

import ru.morecode.JRPG.location.LabyrinthLocation;
import ru.morecode.JRPG.location.VillageLocation;

import java.util.Scanner;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {

        VillageLocation v = new VillageLocation(7, 7);
        v.printLocation();
        Scanner in = new Scanner(System.in);
        String action = in.next();
        switch (action){
            case "L":{
                LabyrinthLocation f = new LabyrinthLocation(5, 5);
                while(!f.qualityControl()){
                    f.labyrinthCleaner();
                    f.generateLabyrinth();
                }
                f.printLocation();
                break;
            }
            case "N":{
                System.out.println("Привет герой!");
            }
        }






    }
}