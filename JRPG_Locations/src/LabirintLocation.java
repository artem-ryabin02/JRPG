import java.util.LinkedList;
import java.util.Random;
import java.util.Vector;
public class LabirintLocation extends Location{
    LinkedList<String> idField = new LinkedList<>();
    LinkedList<String> idNorth = new LinkedList<>();
    LinkedList<String> idSouth = new LinkedList<>();
    LinkedList<String> idEast = new LinkedList<>();
    LinkedList<String> idWest = new LinkedList<>();
    final String idWall = "0000";
    LinkedList<String> events = new LinkedList<>();
    final int SIZE_ID = 4;
    boolean existExit = false;
    LabirintField[][] labirint;
    LabirintLocation(int row, int col){
        super(row, col);

        createId();

        this.labirint = new LabirintField[this.row][this.col];

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                this.labirint[i][j] = new LabirintField(idWall, events.get(0));
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
    public void generateLabirint(){
        Random randomGenerator = new Random();
        int randX = randomGenerator.nextInt(col);
        int randY = randomGenerator.nextInt(row);
        int len = idField.size();
        int randomInt = randomGenerator.nextInt(len);
        String randId = idField.get(randomInt);

        labirint[randX][randY].setId(randId);
        labirint[randX][randY].setEvent_(events.get(4));

        for(int i = 0; i < row * col; i++){
            allGenerateLabirint();
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
            if(checkPass(labirint[x][y].getId(), i)){
                int direction = 0;
                int size = 0;
                switch(i){
                    case 0:
                        direction = -1;
                        size = idSouth.size();
                        if(checkBorderX(direction, x)){
                            if(checkWall(labirint[x + direction][y].getId())){
                                String randId = idSouth.get(randomGenerator.nextInt(size));
                                labirint[x + direction][y].setId(randId);
                                labirint[x + direction][y].setEvent_(randomizeEvent());
                            }
                        }
                        break;
                    case 1:
                        direction = 1;
                        size = idNorth.size();
                        if(checkBorderX(direction, x)){
                            if(checkWall(labirint[x + direction][y].getId())){
                                String randId = idNorth.get(randomGenerator.nextInt(size));
                                labirint[x + direction][y].setId(randId);
                                labirint[x + direction][y].setEvent_(randomizeEvent());
                            }
                        }
                        break;
                    case 2:
                        direction = 1;
                        size = idWest.size();
                        if(checkBorderY(direction, y)){
                            if(checkWall(labirint[x][y = direction].getId())){
                                String randId = idWest.get(randomGenerator.nextInt(size));
                                labirint[x][y + direction].setId(randId);
                                labirint[x][y + direction].setEvent_(randomizeEvent());
                            }
                        }
                        break;
                    case 3:
                        direction = -1;
                        size = idEast.size();
                        if(checkBorderX(direction, y)){
                            if(checkWall(labirint[x][y + direction].getId())){
                                String randId = idEast.get(randomGenerator.nextInt(size));
                                labirint[x][y + direction].setId(randId);
                                labirint[x][y + direction].setEvent_(randomizeEvent());
                            }
                        }
                        break;
                }
            }
        }
    }

    private void allGenerateLabirint(){
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(!checkWall(labirint[i][j].getId())){
                    generatingPassageWays(i, j);
                }
            }
        }
    }

    public void printLabirint(){
        for(int i = 0; i < this.row; i++){
            System.out.println(" ");
            for(int j = 0; j < this.col; j++){
                System.out.print(labirint[i][j].getId() + " ");
            }
            System.out.println(" ");
            for(int j = 0; j < this.col; j++){
                System.out.print(labirint[i][j].getEvent_() + " ");
            }
            System.out.println(" ");
        }
        System.out.println(" ");
        System.out.println(" ");
    }
}
