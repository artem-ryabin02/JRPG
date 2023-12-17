#ifndef FIELDLABYRINTH_H
#define FIELDLABYRINTH_H

#include <QObject>
#include <QWidget>

enum class EVENT_FIELD{
    ENEMY,
    CHEST,
    BOSS,
    ENTRY,
    NONE
};
enum class NAME_FIELD_LAB{
    N, NS, NE, NW, NSE, NSW, NSWE, NWE,
    S, SE, SW, SWE,
    E, WE,
    W,
    WALL
};

class FieldLabyrinth : public QWidget
{
    Q_OBJECT
public:
    explicit FieldLabyrinth(QWidget *parent = nullptr);

    void rescale(int _size);

    void fullSet(QString _id, QString _nameFieald, QString _nameEvent);


    bool getNorth() const;

    bool getSouth() const;

    bool getEast() const;

    bool getWest() const;

    bool getEventEnemy() const;

    bool getEventChest() const;

    bool getEventBoss() const;

    bool getEventEntry() const;

    QString getNameField() const;

    void setHero(bool flag);


    int getSize() const;
    void setEventEnemy(bool newEventEnemy);

    void setEventChest(bool newEventChest);

    void setEventBoss(bool newEventBoss);

    void setNulls();
protected:
    void paintEvent(QPaintEvent * pE) override;
private:
    int size;
    QString id;
    QString nameField;
    QString nameEvent;
    bool hero;
    bool north;
    bool south;
    bool east;
    bool west;

    bool eventEnemy;
    bool eventChest;
    bool eventBoss;
    bool eventEntry;

    void setDirections(QString id);
    void setEvents(QString event);

};

#endif // FIELDLABYRINTH_H
