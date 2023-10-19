package ru.morecode.JRPG.location;

import ru.morecode.JRPG.field.LabirintField;

import java.util.LinkedList;
import java.util.Random;

public class LabyrinthLocation extends Location{
    LinkedList<String> idField = new LinkedList<>();
    LinkedList<String> idNorth = new LinkedList<>();
    LinkedList<String> idSouth = new LinkedList<>();
    LinkedList<String> idEast = new LinkedList<>();
    LinkedList<String> idWest = new LinkedList<>();
    final String idWall = "0000";
    LinkedList<String> events = new LinkedList<>();
    final int SIZE_ID = 4;
    boolean existExit = false;
    LabirintField[][] labyrinth;
    public LabyrinthLocation(int row, int col){
        super(row, col);

        createId();

        this.labyrinth = new LabirintField[this.row][this.col];

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                this.labyrinth[i][j] = new LabirintField(10, idWall, events.get(0));
            }
        }
    }

    private void createId(){
        idField.add("0001");
        idField.add("0010");
        idField.add("0011");
        idField.add("0100");
        idField.add("0101");
        idField.add("0110");
        idField.add("0111");
        idField.add("1000");
        idField.add("1001");
        idField.add("1010");
        idField.add("1011");
        idField.add("1100");
        idField.add("1101");
        idField.add("1110");
        idField.add("1111");

        idNorth.add("1000");
        idNorth.add("1001");
        idNorth.add("1010");
        idNorth.add("1011");
        idNorth.add("1100");
        idNorth.add("1101");
        idNorth.add("1110");
        idNorth.add("1111");

        idSouth.add("0100");
        idSouth.add("0101");
        idSouth.add("0110");
        idSouth.add("0111");
        idSouth.add("1100");
        idSouth.add("1101");
        idSouth.add("1110");
        idSouth.add("1111");

        idEast.add("0010");
        idEast.add("0011");
        idEast.add("0110");
        idEast.add("0111");
        idEast.add("1010");
        idEast.add("1011");
        idEast.add("1110");
        idEast.add("1111");

        idWest.add("0001");
        idWest.add("0011");
        idWest.add("0101");
        idWest.add("0111");
        idWest.add("1001");
        idWest.add("1011");
        idWest.add("1101");
        idWest.add("1111");

        events.add("Wall");
        events.add("Empt");
        events.add("Ches");
        events.add("Enem");
        events.add("Entr");
        events.add("Exit");

    }
    public void generateLabyrinth(){
        Random randomGenerator = new Random();
        int randX = randomGenerator.nextInt(col);
        int randY = randomGenerator.nextInt(row);
        int len = idField.size();
        int randomInt = randomGenerator.nextInt(len);
        String randId = idField.get(randomInt);

        labyrinth[randX][randY].setId(randId);
        labyrinth[randX][randY].setEvent_(events.get(4));

        for(int i = 0; i < 100; i++){
            allGenerateLabyrinth();
        }

    }

    private boolean checkPass(String idField, int direction) {
        char ch = idField.charAt(direction);
        if (ch == '1') {
            return true;
        } else return false;
    }

    private boolean checkBorderX(int direction, int x){
        if((x + direction) < 0 || (x + direction) >= this.col){
            return false;
        } else return true;
    }

    private boolean checkBorderY(int direction, int y){
        if((y + direction) < 0 || (y + direction) >= this.row){
            return false;
        } else return true;
    }

    private boolean checkWall(String idField){
        if(idField == idWall){
            return true;
        } else return false;
    }

    private String randomizeEvent(){
        Random randomGenerator = new Random();
        int cube = randomGenerator.nextInt(100);
        if(existExit == false){
            if (cube <= 80){
                return events.get(1);
            } else if(cube <= 90){
                return events.get(3);
            } else if(cube <= 95){
                return events.get(2);
            } else {
                existExit = true;
                return events.get(5);
            }
        } else {
            if (cube <= 80) {
                return events.get(1);
            } else if (cube <= 90) {
                return events.get(3);
            } else return events.get(2);
        }
    }

    private void generatingPassageWays(int x, int y){
        Random randomGenerator = new Random();
        for(int i = 0; i < SIZE_ID; i++){
            if(checkPass(labyrinth[x][y].getId(), i)){
                int direction = 0;
                int size = 0;
                switch(i){
                    case 0:
                        direction = -1;
                        size = idSouth.size();
                        if(checkBorderX(direction, x)){
                            if(checkWall(labyrinth[x + direction][y].getId())){
                                String randId = idSouth.get(randomGenerator.nextInt(size));
                                labyrinth[x + direction][y].setId(randId);
                                labyrinth[x + direction][y].setEvent_(randomizeEvent());
                            }
                        }
                        break;
                    case 1:
                        direction = 1;
                        size = idNorth.size();
                        if(checkBorderX(direction, x)){
                            if(checkWall(labyrinth[x + direction][y].getId())){
                                String randId = idNorth.get(randomGenerator.nextInt(size));
                                labyrinth[x + direction][y].setId(randId);
                                labyrinth[x + direction][y].setEvent_(randomizeEvent());
                            }
                        }
                        break;
                    case 2:
                        direction = 1;
                        size = idWest.size();
                        if(checkBorderY(direction, y)){
                            if(checkWall(labyrinth[x][y + direction].getId())){
                                String randId = idWest.get(randomGenerator.nextInt(size));
                                labyrinth[x][y + direction].setId(randId);
                                labyrinth[x][y + direction].setEvent_(randomizeEvent());
                            }
                        }
                        break;
                    case 3:
                        direction = -1;
                        size = idEast.size();
                        if(checkBorderX(direction, y)){
                            if(checkWall(labyrinth[x][y + direction].getId())){
                                String randId = idEast.get(randomGenerator.nextInt(size));
                                labyrinth[x][y + direction].setId(randId);
                                labyrinth[x][y + direction].setEvent_(randomizeEvent());
                            }
                        }
                        break;
                }
            }
        }
    }

    private void allGenerateLabyrinth(){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(!checkWall(labyrinth[i][j].getId())){
                    generatingPassageWays(i, j);
                }
            }
        }
    }

    @Override
    public void printLocation(){
        for(int i = 0; i < this.row; i++){
            System.out.println(" ");
            for(int j = 0; j < this.col; j++){
                System.out.print(labyrinth[i][j].getId() + " ");
            }
            System.out.println(" ");
            for(int j = 0; j < this.col; j++){
                System.out.print(labyrinth[i][j].getEvent_() + " ");
            }
            System.out.println(" ");
        }
        System.out.println(" ");
        System.out.println(" ");
    }

    public boolean qualityControl(){
        int countWall = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (labyrinth[i][j].getId() == idWall){
                    countWall++;
                }
            }
        }
        if (countWall <= (int) ((row*col)*0.5) && existExit){
            return true;
        } else {
            return false;
        }
    }

    public void labyrinthCleaner(){
        existExit = false;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                labyrinth[i][j].setId(idWall);
                labyrinth[i][j].setEvent_(events.get(0));
            }
        }
    }
}
