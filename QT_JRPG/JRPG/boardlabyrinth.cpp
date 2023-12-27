#include "boardlabyrinth.h"
#include "generatorlabyrinth.h"

#include <QDir>

BoardLabyrinth::BoardLabyrinth(QWidget *parent)
    : QWidget{parent}
{
    grid = new QGridLayout(this);
    grid->setSpacing(0);
    fl = new FieldLabyrinth**[rows];
    for (int r = 0; r < rows; r++){
        fl[r] = new FieldLabyrinth*[cols];
        for(int c = 0; c < cols; c++){
            fl[r][c] = new FieldLabyrinth(this);
        }
    }

    regeneration();
    player = new QMediaPlayer();
    ao = new QAudioOutput();
    ao->setVolume(50);
    player->setSource(QUrl::fromLocalFile(QDir::currentPath()+ "/music/sound_steps_on_labyrinth.wav"));
    player->setAudioOutput(ao);
}

BoardLabyrinth::~BoardLabyrinth(){

    delete player;
    delete ao;
    delete grid;
}

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

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (tmpLab[i][j].getId() == "0001"){
                fl[i][j]->fullSet(tmpLab[i][j].getId(), fieldName[NAME_FIELD_LAB::E], tmpLab[i][j].getEvents());
            }
            if (tmpLab[i][j].getId() == "1000"){
                fl[i][j]->fullSet(tmpLab[i][j].getId(), fieldName[NAME_FIELD_LAB::N], tmpLab[i][j].getEvents());
            }
            if (tmpLab[i][j].getId() == "1001"){
                fl[i][j]->fullSet(tmpLab[i][j].getId(), fieldName[NAME_FIELD_LAB::NE], tmpLab[i][j].getEvents());
            }
            if (tmpLab[i][j].getId() == "1100"){
                fl[i][j]->fullSet(tmpLab[i][j].getId(), fieldName[NAME_FIELD_LAB::NS], tmpLab[i][j].getEvents());
            }
            if (tmpLab[i][j].getId() == "1101"){
                fl[i][j]->fullSet(tmpLab[i][j].getId(), fieldName[NAME_FIELD_LAB::NSE], tmpLab[i][j].getEvents());
            }
            if (tmpLab[i][j].getId() == "1110"){
                fl[i][j]->fullSet(tmpLab[i][j].getId(), fieldName[NAME_FIELD_LAB::NSW], tmpLab[i][j].getEvents());
            }
            if (tmpLab[i][j].getId() == "1111"){
                fl[i][j]->fullSet(tmpLab[i][j].getId(), fieldName[NAME_FIELD_LAB::NSWE], tmpLab[i][j].getEvents());
            }
            if (tmpLab[i][j].getId() == "1010"){
                fl[i][j]->fullSet(tmpLab[i][j].getId(), fieldName[NAME_FIELD_LAB::NW], tmpLab[i][j].getEvents());
            }
            if (tmpLab[i][j].getId() == "1011"){
                fl[i][j]->fullSet(tmpLab[i][j].getId(), fieldName[NAME_FIELD_LAB::NWE], tmpLab[i][j].getEvents());
            }
            if (tmpLab[i][j].getId() == "0100"){
                fl[i][j]->fullSet(tmpLab[i][j].getId(), fieldName[NAME_FIELD_LAB::S], tmpLab[i][j].getEvents());
            }
            if (tmpLab[i][j].getId() == "0101"){
                fl[i][j]->fullSet(tmpLab[i][j].getId(), fieldName[NAME_FIELD_LAB::SE], tmpLab[i][j].getEvents());
            }
            if (tmpLab[i][j].getId() == "0110"){
                fl[i][j]->fullSet(tmpLab[i][j].getId(), fieldName[NAME_FIELD_LAB::SW], tmpLab[i][j].getEvents());
            }
            if (tmpLab[i][j].getId() == "0111"){
                fl[i][j]->fullSet(tmpLab[i][j].getId(), fieldName[NAME_FIELD_LAB::SWE], tmpLab[i][j].getEvents());
            }
            if (tmpLab[i][j].getId() == "0010"){
                fl[i][j]->fullSet(tmpLab[i][j].getId(), fieldName[NAME_FIELD_LAB::W], tmpLab[i][j].getEvents());
            }
            if (tmpLab[i][j].getId() == "0000"){
                fl[i][j]->fullSet(tmpLab[i][j].getId(), fieldName[NAME_FIELD_LAB::WALL], tmpLab[i][j].getEvents());
            }
            if (tmpLab[i][j].getId() == "0011"){
                fl[i][j]->fullSet(tmpLab[i][j].getId(), fieldName[NAME_FIELD_LAB::WE], tmpLab[i][j].getEvents());
            }
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
            grid->addWidget(fl[r][c], r, c);
        }
    }
}

void BoardLabyrinth::updatePostion(int r, int c){

    int xNew = xHero + r;
    int yNew = yHero + c;
    if ((xNew >= 0 && yNew >= 0) && (xNew < rows && yNew < cols)){
        if(isCanGo(xHero, yHero, xNew, yNew)){
            player->play();
            fl[xHero][yHero]->setHero(false);
            fl[xNew][yNew]->setHero(true);
            xHero = xNew;
            yHero = yNew;
            if (fl[xNew][yNew]->getEventBoss()){
                emit boss();
                fl[xNew][yNew]->setEventBoss(false);
            }
            if (fl[xNew][yNew]->getEventChest()){
                emit chest();
                fl[xNew][yNew]->setEventChest(false);
            }
            if (fl[xNew][yNew]->getEventEnemy()){
                emit enemy();
                fl[xNew][yNew]->setEventEnemy(false);
            }
            if (fl[xNew][yNew]->getEventEntry()){
                emit entry();
            }
        }

    }
}

void BoardLabyrinth::setDisable(bool disable)
{
    this->blockSignals(disable);
}

void BoardLabyrinth::setVolume(int volume)
{
    ao->setVolume(volume);
}

void BoardLabyrinth::regeneration()
{
    setNulls();
    GeneratorLabyrinth gnerLab(rows, cols);
    loadBoardLab(gnerLab.getLab());
    initialization();
}

void BoardLabyrinth::setNulls()
{
    for( int r = 0 ; r < rows ; r ++ ){
        for(int c = 0 ; c < cols ; c ++ ){
            fl[r][c]->setNulls();
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
