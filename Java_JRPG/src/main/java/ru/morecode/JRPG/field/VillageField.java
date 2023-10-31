package ru.morecode.JRPG.field;

public class VillageField extends Field {
    private boolean isFree;
    private boolean isNPC;
    private boolean isEntryLabyrinth;
    private String name;

    public VillageField(int size, boolean isFree, boolean isNPC, boolean isEntryLabyrinth, String name){
        super(size);
        this.isFree = isFree;
        this.isNPC = isNPC;
        this.isEntryLabyrinth = isEntryLabyrinth;
        this.name = name;
    }


    public boolean isFree() {
        return isFree;
    }

    public boolean isNPC() {
        return isNPC;
    }

    public boolean isEntryLabyrinth() {
        return isEntryLabyrinth;
    }

    public void printField (){
        System.out.print(name + " ");
    }

}
