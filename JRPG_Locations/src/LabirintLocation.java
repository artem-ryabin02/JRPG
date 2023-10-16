import java.util.Vector;
public class LabirintLocation extends Location{

    final String idField[] = {"0001", "0010", "0011", "0100", "0101", "0110", "0111",
            "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};

    final String idNorth[] = {"1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};

    final String idSouth[] = {"0100", "0101", "0110", "0111", "1100", "1101", "1110", "1111"};

    final String idEast[] = {"0010", "0011", "0110", "0111", "1010", "1011", "1110", "1111"};

    final String idWest[] = {"0001", "0011", "0101", "0111", "1001", "1011", "1101", "1111"};

    final String idWall = "0000";

    final String events[] = {"Wall", "Empt", "Ches", "Enem", "Entr", "Exit"};

    final int SIZE_ID = 4;

    boolean existExit = false;

    LabirintField[][] labirint;

    LabirintLocation(int row, int col){
        super(row, col);

        this.labirint = new LabirintField[this.row][this.col];

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                //this.labirint[i][j].setId(idWall);
                //this.labirint[i][j].setEvent_(events[0]);
                this.labirint[i][j] = new LabirintField(idWall, events[0]);
            }
        }
    }

    public void generateLabirint(){
        int randX = (int) Math.random() * (this.col - 0) + 0;
        int randY = (int) Math.random() * (this.row - 0) + 0;

        String randId = idField[(int) Math.random() * ((idField.length - 1) - 0) + 0];

        labirint[randX][randY].setId(randId);
        labirint[randX][randY].setEvent_(events[4]);

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
        int cube = (int) Math.random() * (100 - 1 + 1) + 1;
        if(existExit == false){
            if (cube <= 80){
                return events[1];
            } else if(cube <= 90){
                return events[3];
            } else if(cube <= 95){
                return events[2];
            } else {
                existExit = true;
                return events[5];
            }
        } else {
            if (cube <= 80) {
                return events[1];
            } else if (cube <= 90) {
                return events[3];
            } else return events[2];
        }
    }

    private void generatingPassageWays(int x, int y){
        for(int i = 0; i < SIZE_ID; i++){
            if(checkPass(labirint[x][y].getId(), i)){
                int direction = 0;

                switch(i){
                    case 0:
                        direction = -1;
                        if(checkBorderX(direction, x)){
                            if(checkWall(labirint[x + direction][y].getId())){
                                String randId = idSouth[(int) Math.random() * ((idSouth.length - 1) - 0) + 0];
                                labirint[x + direction][y].setId(randId);
                                labirint[x + direction][y].setEvent_(randomizeEvent());
                            }
                        }
                        break;
                    case 1:
                        direction = 1;
                        if(checkBorderX(direction, x)){
                            if(checkWall(labirint[x + direction][y].getId())){
                                String randId = idNorth[(int) Math.random() * ((idNorth.length - 1) - 0) + 0];
                                labirint[x + direction][y].setId(randId);
                                labirint[x + direction][y].setEvent_(randomizeEvent());
                            }
                        }
                        break;
                    case 2:
                        direction = 1;
                        if(checkBorderY(direction, y)){
                            if(checkWall(labirint[x][y = direction].getId())){
                                String randId = idWest[(int) Math.random() * ((idWest.length - 1) - 0) + 0];
                                labirint[x][y + direction].setId(randId);
                                labirint[x][y + direction].setEvent_(randomizeEvent());
                            }
                        }
                        break;
                    case 3:
                        direction = -1;
                        if(checkBorderX(direction, y)){
                            if(checkWall(labirint[x][y + direction].getId())){
                                String randId = idEast[(int) Math.random() * ((idEast.length - 1) - 0) + 0];
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
