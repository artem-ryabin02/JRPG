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
    QPixmap pMap(":/assets/"+fieldName);
    p.drawPixmap(0, 0, size, size, pMap);
    if (isNPC){
        int shift = 0.05*size;
        int sz = size - 2*shift;
        QPixmap pMap(":/assets/nps_demot.png");
        p.drawPixmap(shift, shift, sz, sz, pMap);
    }
    if (isHero){
        int shift = 0.05*size;
        int sz = size - 2*shift;
        QPixmap pMap(":/assets/hero.png");
        p.drawPixmap(shift, shift, sz, sz, pMap);
    }

}

//void FieldLocation::mouseDoubleClickEvent(QMouseEvent *event){
//    if (event->button() == Qt::LeftButton){
//        qDebug()<< "double click event\n";
//        emit leftMouseDoubleClick();
//    }
//}

//void FieldLocation::keyReleaseEvent(QKeyEvent *event){
//    qDebug()<< "keyReleaseEvent\n";
//    switch (event->key()) {
//    case Qt::Key_W:
//        emit wPress();
//        break;
//    case Qt::Key_A:
//        emit aPress();
//        break;
//    case Qt::Key_S:
//        emit sPress();
//        break;
//    case Qt::Key_D:
//        emit dPress();
//        break;
//    default:
//        break;
//    }
//}


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

void FieldLocation::fullSet(bool isFree, bool isNPC, bool isLab, QString flName){
    this->setFree(isFree);
    this->setNPC(isNPC);
    this->setLabyrinth(isLab);
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

