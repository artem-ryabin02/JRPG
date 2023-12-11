#include "fieldlabyrinth.h"
#include "qpainter.h"

FieldLabyrinth::FieldLabyrinth(QWidget *parent)
    : QWidget{parent}
{
    size = parent->height()/10;
    hero = false;
    this->east = false;
    this->west = false;
    this->south = false;
    this->north = false;
    this->nameEvent = "";
    this->eventBoss = false;
    this->eventChest = false;
    this->eventEnemy = false;
    this->eventEntry = false;
}

void FieldLabyrinth::rescale(int _size)
{
    size = _size;
    repaint();
}

void FieldLabyrinth::paintEvent(QPaintEvent *pE)
{
    Q_UNUSED(pE);
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);
    QPixmap pMap(":/assets/fieldsLabyrinth/"+nameField);
    p.drawPixmap(0, 0, size, size, pMap);
    if (eventBoss){
        int shift = 0.25*size;
        int sz = size - 2*shift;
        QPixmap pMap(":/assets/labyrinthEvent/boss.png");
        p.drawPixmap(shift, shift, sz, sz, pMap);
    }
    if (eventChest){
        int shift = 0.25*size;
        int sz = size - 2*shift;
        QPixmap pMap(":/assets/labyrinthEvent/chest.png");
        p.drawPixmap(shift, shift, sz, sz, pMap);
    }
    if (eventEnemy){
        int shift = 0.25*size;
        int sz = size - 2*shift;
        QPixmap pMap(":/assets/labyrinthEvent/enemy.png");
        p.drawPixmap(shift, shift, sz, sz, pMap);
    }
    if (eventEntry){
        int shift = 0.25*size;
        int sz = size - 2*shift;
        QPixmap pMap(":/assets/labyrinthEvent/entry.png");
        p.drawPixmap(shift, shift, sz, sz, pMap);
    }
    if (hero){
        int shift = 0.25*size;
        int sz = size - 2*shift;
        QPixmap pMap(":/assets/characters/hero.png");
        p.drawPixmap(shift, shift, sz, sz, pMap);
    }

}

void FieldLabyrinth::setEventBoss(bool newEventBoss)
{
    eventBoss = newEventBoss;
}

void FieldLabyrinth::setEventChest(bool newEventChest)
{
    eventChest = newEventChest;
}

void FieldLabyrinth::setEventEnemy(bool newEventEnemy)
{
    eventEnemy = newEventEnemy;
}

int FieldLabyrinth::getSize() const
{
        return size;
}


void FieldLabyrinth::setDirections(QString id)
{
    QString ed = "1";
    for (int i = 0; i < id.size(); ++i) {
        if (i==0 && id[i] == ed){
            north = true;
        }
        if (i==1 && id[i] == ed){
            south = true;
        }
        if (i==2 && id[i] == ed){
            east = true;
        }
        if (i==3 && id[i] == ed){
            west = true;
        }
    }
}

void FieldLabyrinth::setEvents(QString event)
{
    if (event == "entry"){
        setHero(true);
        eventEntry = true;
    }
    if (event == "enemy") eventEnemy = true;
    if (event == "boss") eventBoss = true;
    if (event == "chest") eventChest = true;
}


void FieldLabyrinth::fullSet(QString _id, QString _nameFieald, QString _nameEvent)
{
    id = _id;
    nameField = _nameFieald;
    setDirections(id);
    nameEvent = _nameEvent;
    setEvents(nameEvent);

}

QString FieldLabyrinth::getNameField() const
{
    return nameField;
}

void FieldLabyrinth::setHero(bool flag)
{
    hero = flag;
    repaint();
}



bool FieldLabyrinth::getNorth() const
{
    return north;
}

bool FieldLabyrinth::getSouth() const
{
    return south;
}

bool FieldLabyrinth::getEast() const
{
    return east;
}

bool FieldLabyrinth::getWest() const
{
    return west;
}

bool FieldLabyrinth::getEventEnemy() const
{
    return eventEnemy;
}

bool FieldLabyrinth::getEventChest() const
{
    return eventChest;
}

bool FieldLabyrinth::getEventBoss() const
{
    return eventBoss;
}

bool FieldLabyrinth::getEventEntry() const
{
    return eventEntry;
}
