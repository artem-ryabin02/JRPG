package ru.morecode.JRPG.location;

public class Location {

    protected int row, col;

    Location(int row, int col){
        this.row = row;
        this.col = col;
    }

    public int getRow() {
        return row;
    }

    public int getCol() {
        return col;
    }

    public void printLocation(){    }
}
