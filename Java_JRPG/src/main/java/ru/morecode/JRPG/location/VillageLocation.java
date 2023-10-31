package ru.morecode.JRPG.location;

import ru.morecode.JRPG.field.VillageField;

import java.io.*;

public class VillageLocation extends Location {

    VillageField[][] village;
    public VillageLocation(int row, int col) {
        super(row, col);
        village = new VillageField[row][col];
        String line;
        int i = 0;
        try {
            BufferedReader br = new BufferedReader(new FileReader("src\\ru\\morecode\\JRPG\\VillageFile.txt"));
            while((line = br.readLine()) != null){
                String[] nameMas = line.split("\\|");
                for (int j = 0; j < nameMas.length; j++){

                    String grass = "H";
                    if (nameMas[j].equals(grass)){
                        village[i][j] = new VillageField(10, true, false, false, grass);

                    }
                    String NPC = "N";
                    if (nameMas[j].equals(NPC)){
                        village[i][j] = new VillageField(10, false, true, false, NPC);

                    }
                    String labyrinth = "L";
                    if (nameMas[j].equals(labyrinth)){
                        village[i][j] = new VillageField(10, false, false, true, labyrinth);
                        //village[i][j].printField();
                    }
                    String water = "W";
                    if (nameMas[j].equals(water)) {
                        village[i][j] = new VillageField(10, false, false, false, water);
                        //village[i][j].printField();
                    }
                }
                System.out.println();
                i++;
            }
            br.close();
        } catch (IOException e){
            throw new RuntimeException(e);
        }

    }

    @Override
    public void printLocation(){
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                village[i][j].printField();
            }
            System.out.println();
        }
    }
}
