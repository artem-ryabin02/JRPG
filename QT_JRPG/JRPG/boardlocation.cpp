#include "boardlocation.h"

BoardLocation::BoardLocation(QWidget* parent)
    : QWidget{parent}
{
    grid = new QGridLayout(this);
    grid->setSpacing(0);
    QFile file(":/assets/VillageFile.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        exit(-1);
    }
    loadBoardVillage(file);
    file.close();
    initialization();

    player = new QMediaPlayer();
    ao = new QAudioOutput();
    ao->setVolume(50);
    player->setSource(QUrl::fromLocalFile(QDir::currentPath()+ "/music/sound_steps_on_village.wav"));
    player->setAudioOutput(ao);


}
BoardLocation::~BoardLocation(){}

void BoardLocation::loadBoardVillage(QFile& file){
//    QProcess process;
//    process.start("cmd", );


    fl = new FieldLocation**[rows];
    for (int r = 0; r < rows; r++){
        fl[r] = new FieldLocation*[cols];
        for(int c = 0; c < cols; c++){
            fl[r][c] = new FieldLocation(this);
        }
    }

    QString tmp;
    int j = 0;

    while((tmp = file.readLine()) != nullptr){
        QStringList tmpList = tmp.split("|");
        for (int i = 0; i < rows; i++){
            if (j == xHero && i == yHero){
                fl[j][i]->setHero(true);
            }
            if (tmpList[i] == "N"){
                fl[j][i]->fullSet(false, true, false, fieldName[NAME_FIELD::GRASS]);
            }
            if (tmpList[i] == "L"){
                fl[j][i]->fullSet(false, false, true, fieldName[NAME_FIELD::LABYRINTH_ENTRY]);
            }
            if (tmpList[i] == "G"){
                fl[j][i]->fullSet(true, false, false, fieldName[NAME_FIELD::GRASS]);
            }
            if (tmpList[i] == "GWCB"){
                fl[j][i]->fullSet(false, false, false, fieldName[NAME_FIELD::GRASS_WATER_C_B]);
            }
            if (tmpList[i] == "GWB"){
                fl[j][i]->fullSet(false, false, false, fieldName[NAME_FIELD::GRASS_WATER_B]);
            }
            if (tmpList[i] == "GWS"){
                fl[j][i]->fullSet(false, false, false, fieldName[NAME_FIELD::GRASS_WATER_S]);
            }
            if (tmpList[i] == "W"){
                fl[j][i]->fullSet(false, false, false, fieldName[NAME_FIELD::WATER]);
            }
        }

        j++;
    }
}


void BoardLocation::initialization(){
    for (int r = 0; r < rows; r++){
        for(int c = 0; c < cols; c++){
            grid->addWidget(fl[r][c], r, c);
        }
    }
}

void BoardLocation::updatePostion(int r, int c){

    int xNew = xHero + r;
    int yNew = yHero + c;
    if ((xNew >= 0 && yNew >= 0) && (xNew < rows && yNew < cols)){
        if(fl[xNew][yNew]->getFree()){
            player->play();
            fl[xHero][yHero]->setHero(false);
            fl[xNew][yNew]->setHero(true);
            xHero = xNew;
            yHero = yNew;
        }
        if (fl[xNew][yNew]->getNPC()){
            emit signalDialogWithNPC();
        }
        if (fl[xNew][yNew]->getIsLabyrinth()){
            emit signalEntryLabyrinth();
        }
    }

}

void BoardLocation::setDisable(bool disable)
{
    this->blockSignals(disable);
}

void BoardLocation::rescale(int _size){
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


