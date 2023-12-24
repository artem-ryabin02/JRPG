#include "generatorlabyrinth.h"

GeneratorLabyrinth::GeneratorLabyrinth(int row, int col)
{
    this->row = row;
    this->col = col;

    tmpData = new TmpData*[row];
    for (int i = 0; i < row; ++i) {
        tmpData[i] = new TmpData[col];
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            tmpData[i][j].setStr(idWall, nameEv[0]);
        }
    }
    generateLabyrinth();
}

GeneratorLabyrinth::~GeneratorLabyrinth()
{
    qDebug() << "GeneratorLabyrinth";

}

void GeneratorLabyrinth::generateLabyrinth()
{
    int randX = QRandomGenerator::global()->bounded(row-1);
    int randY = QRandomGenerator::global()->bounded(col-1);
    int size = idField.size();
    int randomInt = QRandomGenerator::global()->bounded(size-1);
    QString randId = idField[randomInt];

    tmpData[randX][randY].setStr(randId, nameEv[5]);
    for(int i = 0; i < 100; i++){
        allGenerateLabyrinth();
    }
}

bool GeneratorLabyrinth::qualityControl()
{
    int countWall = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (tmpData[i][j].getId() == idWall){
                countWall++;
            }
        }
    }
    if (countWall <= (int) ((row * col) * 0.5) && boss){
        return true;
    }
    else return false;
}

void GeneratorLabyrinth::labyrinthCleaner()
{
    boss = false;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
             tmpData[i][j].setStr(idWall, nameEv[0]);
        }
    }
}

bool GeneratorLabyrinth::checkPass(QString idField, int direction)
{
    QString ch = "1";
    return idField[direction] == ch;
}

bool GeneratorLabyrinth::checkBorderX(int direction, int x)
{
    return ((x + direction) >= 0 && (x + direction) < this->col);
}

bool GeneratorLabyrinth::checkBorderY(int direction, int y)
{

    return ((y + direction) >= 0 && (y + direction) < this->row);
}

bool GeneratorLabyrinth::checkWall(QString idField)
{
    return idField == idWall;
}

QString GeneratorLabyrinth::randomizeEvent()
{
    int cube = QRandomGenerator::global()->bounded(100);
    if(!boss){
        if (cube <= 70){
            return nameEv[1];
        } else if(cube <= 80){
            return nameEv[3];
        } else if(cube <= 95){
            return nameEv[2];
        } else {
            boss = true;
            return nameEv[4];
        }
    } else {
        if (cube <= 70) {
            return nameEv[1];
        } else if (cube <= 80) {
            return nameEv[3];
        } else return nameEv[2];
    }
}

void GeneratorLabyrinth::generatingPassageWays(int x, int y)
{
    for(int i = 0; i < idWall.size(); i++){
        if(checkPass(tmpData[x][y].getId(), i)){
            int direction;
            int size;
            switch(i){
            case 0:
                direction = -1;
                size = idSouth.size();
                if(checkBorderX(direction, x)){
                    if(checkWall(tmpData[x + direction][y].getId())){
                        QString randId = idSouth[QRandomGenerator::global()->bounded(size-1)];
                        tmpData[x + direction][y].setStr(randId, randomizeEvent());
                    }
                }
                break;
            case 1:
                direction = 1;
                size = idNorth.size();

                if(checkBorderX(direction, x)){
                    if(checkWall(tmpData[x + direction][y].getId())){
                        QString randId = idNorth[QRandomGenerator::global()->bounded(size-1)];
                        tmpData[x + direction][y].setStr(randId, randomizeEvent());
                    }
                }
                break;
            case 2:
                direction = 1;
                size = idWest.size();

                if(checkBorderY(direction, y)){
                    if(checkWall(tmpData[x][y + direction].getId())){
                        QString randId = idWest[QRandomGenerator::global()->bounded(size-1)];
                        tmpData[x][y + direction].setStr(randId, randomizeEvent());
                    }
                }
                break;
            case 3:
                direction = -1;
                size = idSouth.size();

                if(checkBorderY(direction, y)){

                    if(checkWall(tmpData[x][y + direction].getId())){
                        QString randId = idEast[(QRandomGenerator::global()->bounded(size-1))];
                        tmpData[x][y + direction].setStr(randId, randomizeEvent());
                    }
                }
                break;
            }

        }
    }
}

void GeneratorLabyrinth::allGenerateLabyrinth()
{
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(!checkWall(tmpData[i][j].getId())){
                generatingPassageWays(i, j);
            }
        }
    }
}

TmpData **GeneratorLabyrinth::getLab()
{
    while(!qualityControl()){
        labyrinthCleaner();
        generateLabyrinth();
    }
    return tmpData;
}
