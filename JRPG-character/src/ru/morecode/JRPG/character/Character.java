package ru.morecode.JRPG.character;
public  abstract class Character {
    String name;
    private int vitality;
    private int strength;
    private int wisdom;
    private int intelligence;
    private int agility;
    private int perception;
    protected int maxHealth;
    protected int health;
    protected int maxMana;
    protected int mana;
    private int attack;
    protected int protection;
    private int critChance;
    protected int dodge;
    private int tempDefence = 10;
    private boolean defenceFlag = false;
    private boolean alive = true;
    public Character(String name, int vitality, int strength, int wisdom, int intelligence, int agility, int perception) {
        this.name = name;
        this.vitality = vitality;
        this.strength = strength;
        this.wisdom = wisdom;
        this.intelligence = intelligence;
        this.agility = agility;
        this.perception = perception;
        this.maxHealth = vitality * 10;
        this.health = maxHealth;
        this.maxMana = (int) ((intelligence + wisdom) * 0.5);
        this.mana = maxMana;
        this.attack = (int) (strength + agility * 0.25);
        this.protection = (int) (vitality * 1.25);
        this.critChance = (int) ((agility * 0.05 + perception * 0.07) * 10);
        this.dodge = (int) ((agility * 2 + perception * 0.2));
    }
    public void displayStatus(){
        System.out.println("name: "+name);
        System.out.println("vitality: "+vitality);
        System.out.println("strength: "+strength);
        System.out.println("wisdom: "+wisdom);
        System.out.println("intelligence: "+intelligence);
        System.out.println("agility: "+agility);
        System.out.println("perception: "+perception);
        System.out.println("health/maxHealth:"+health+"/"+maxHealth);
        System.out.println("mana/maxMana: "+mana+"/"+maxMana);
        System.out.println("attack: "+attack);
        System.out.println("protection: "+protection);
        System.out.println("critChance: "+critChance);
        System.out.println("dodge: "+dodge);
    }

    public String getName() {
        return this.name;
    }
    public void receivedDamage(int damage){
        if(damage == 0){
            System.out.println("промах");
        }
        else {
            if (damage >= health) {
                health = 0;
                alive = false;
            } else {
                health -= damage;
                if (health <= 0) {
                    alive = false;
                }
            }
            System.out.println(name + " получил урон  " + "health/maxHealth:" + health + "/" + maxHealth);
        }
    }
    public int causedDamage(int enemyProtection, int enemyDodge){
        int hit = (int) (Math.random() * (100 - 1 + 1)) + 1;

        if (hit <= enemyDodge ){
            return 0;
        } else if ( hit >= 100 - critChance ){
            System.out.println("oh my God! Crit");
            return  (5 + attack + (hit % 10)) * 2;
        } else {
            int damage = 5 + attack - enemyProtection + (hit % 10);
            if (damage < 0 ){
                return 0;
            } else return damage;
        }
    }

    public void Defence(){
        protection += tempDefence;
        defenceFlag = true;
    }
    public void removeDefence(){
        if (defenceFlag) {
            protection -= tempDefence;
            defenceFlag = false;
        }
    }
    public void Heal (int heal) {
        if ( maxHealth - health <= heal) {
            health = maxHealth;
        } else {
            health += heal;
        }
    }
    public boolean getAlive (){
        return alive;
    }

    public int getProtection() {
        return protection;
    }

    public int getDodge() {
        return dodge;
    }
}
