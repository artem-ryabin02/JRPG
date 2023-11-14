#include "boardlabyrinth.h"
#include "generatorlabyrinth.h"
#include "qlabel.h"

BoardLabyrinth::BoardLabyrinth(QWidget *parent)
    : QWidget{parent}
{
    grid = new QGridLayout(this);
    grid->setSpacing(0);
    GeneratorLabyrinth gnerLab(rows, cols);
    loadBoardLab(gnerLab.getLab());
    initialization();
}

BoardLabyrinth::~BoardLabyrinth(){}

void BoardLabyrinth::rescale(int _size){
    int w = ( _size / rows ) * rows ;
    int h = ( _size / cols ) * cols ;

    this -> setFixedHeight ( h );
    this -> setFixedWidth ( w );

    for( int r = 0 ; r < rows ; r ++ ){
        for(int c = 0 ; c < cols ; c ++ ){
            fl[r][c]-> rescale( w / cols );
        }
    }
}

void BoardLabyrinth::loadBoardLab(TmpData **tmpLab)
{
    fl = new FieldLabyrinth**[rows];
    for (int r = 0; r < rows; r++){
        fl[r] = new FieldLabyrinth*[cols];
        for(int c = 0; c < cols; c++){
            fl[r][c] = new FieldLabyrinth(this);
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            fl[i][j]->fullSet(tmpLab[i][j].getId(), tmpLab[i][j].getEvents());
            if (tmpLab[i][j].getEvents() == "entry"){
                xHero = i;
                yHero = j;
            }
        }
    }
}

void BoardLabyrinth::initialization()
{
    for( int r = 0 ; r < rows ; r ++ ){
        for(int c = 0 ; c < cols ; c ++ ){
            grid->addWidget(new QLabel(fl[r][c]->getNameField()));
        }
    }
}

void BoardLabyrinth::updatePostion(int r, int c){

    int xNew = xHero + r;
    int yNew = yHero + c;
    if ((xNew >= 0 && yNew >= 0) && (xNew < rows && yNew < cols)){
        if(isCanGo(xHero, yHero, xNew, yNew)){
            fl[xHero][yHero]->setHero(false);
            fl[xNew][yNew]->setHero(true);
            xHero = xNew;
            yHero = yNew;
        }

    }
}

bool BoardLabyrinth::isCanGo(int x, int y, int nx, int ny)
{
    if (nx - x < 0){
        if (fl[x][y]->getNorth() && fl[nx][ny]->getSouth()){
            return true;
        }
        else return false;
    }
    if (nx - x > 0){
        if (fl[x][y]->getSouth() && fl[nx][ny]->getNorth()){
            return true;
        }
        else return false;
    }
    if (ny - y < 0){
        if (fl[x][y]->getWest() && fl[nx][ny]->getEast()){
            return true;
        }
        else return false;
    }
    if (ny - y > 0){
        if (fl[x][y]->getEast() && fl[nx][ny]->getWest()){
            return true;
        }
        else return false;
    }
    return false;
}
