#include "fieldlocation.h"

FieldLocation::FieldLocation(QWidget* parent)
    : QWidget{parent}
{
    size = parent->height()/7;
    this->isFree = false;
    this->isHero = false;
    this->isLabyrinth = false;
    this->isNPC = false;
    this->fieldName = "";
}

void FieldLocation::paintEvent(QPaintEvent * pE){
    Q_UNUSED(pE);
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);
    QPixmap pMap(":/assets/fieldsVillage/"+fieldName);
    p.drawPixmap(0, 0, size, size, pMap);
    if (isNPC){
        int shift = 0.05*size;
        int sz = size - 2*shift;
        QPixmap pMap(":/assets/characters/nps_map.png");
        p.drawPixmap(shift, shift, sz, sz, pMap);
    }
    if (isHero){
        int shift = 0.05*size;
        int sz = size - 2*shift;
        QPixmap pMap(":/assets/characters/hero.png");
        p.drawPixmap(shift, shift, sz, sz, pMap);
    }
    if (isSave){
        int shift = 0.05*size;
        int sz = size - 2*shift;
        QPixmap pMap(":/assets/fieldsVillage/save.png");
        p.drawPixmap(shift, shift, sz, sz, pMap);
    }


}

bool FieldLocation::getIsSave() const
{
    return isSave;
}

void FieldLocation::setIsSave(bool newIsSave)
{
    isSave = newIsSave;
}

bool FieldLocation::getIsLabyrinth() const
{
    return isLabyrinth;
}

void FieldLocation::rescale(int _size){
    size = _size;
    repaint();
}

void FieldLocation::setFree(bool f){
    isFree = f;
}

void FieldLocation::setNPC(bool f){
    isNPC = f;
}

void FieldLocation::setLabyrinth(bool f){
    isLabyrinth = f;
}

void FieldLocation::setFieldName(QString fn){
    fieldName = fn;
}

void FieldLocation::fullSet(bool isFree, bool isNPC, bool isLab, bool isSave, QString flName){
    this->setFree(isFree);
    this->setNPC(isNPC);
    this->setLabyrinth(isLab);
    this->setIsSave(isSave);
    this->setFieldName(flName);
}

void FieldLocation::setHero(bool f){
    isHero = f;
    repaint();
}

bool FieldLocation::getFree(){
    return isFree;
}

bool FieldLocation::getNPC()
{
    return isNPC;
}

