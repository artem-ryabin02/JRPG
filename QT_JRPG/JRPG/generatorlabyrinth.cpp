#include "generatorlabyrinth.h"

GeneratorLabyrinth::GeneratorLabyrinth(int row, int col)
{
    this->row = row;//присваиваем новое значение строкам
    this->col = col;//присваиваем новое значение столбцам

    tmpData = new TmpData*[row];// -выделяем память
    for (int i = 0; i < row; ++i) {
        tmpData[i] = new TmpData[col];
    }//-
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            tmpData[i][j].setStr(idWall, nameEv[0]);// зануляем все данные
        }
    }
    generateLabyrinth();// генерируем лабиринт
}

GeneratorLabyrinth::~GeneratorLabyrinth(){}//очистка памяти

void GeneratorLabyrinth::generateLabyrinth()
{
    //берем случайные координаты
    int randX = QRandomGenerator::global()->bounded(row-1);
    int randY = QRandomGenerator::global()->bounded(col-1);
    //выбираем случайное поле из вектора
    int randomInt = QRandomGenerator::global()->bounded(idField.size()-1);
    QString randId = idField[randomInt];

    //создание входа(выхода) в лабиринт
    //на случайных координатах образуется случайное поле и им присваивается собитие "вход"
    tmpData[randX][randY].setStr(randId, nameEv[5]);
    //100 итераций на создание полного лабиринта
    for(int i = 0; i < 100; i++){
        allGenerateLabyrinth();
    }
}

bool GeneratorLabyrinth::qualityControl()
{
    int countWall = 0;// запускаем счетчик стен
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            // если айди в хранилище данных равно айди стены, то счетчик увеличивается
            if (tmpData[i][j].getId() == idWall){
                countWall++;
            }
        }
    }
    //лабиринт проходит контроль качества если в нем меньше половины полей стены и в нем есть босс
    if (countWall <= (int) ((row * col) * 0.5) && boss){
        return true;
    }
    else return false;
}

void GeneratorLabyrinth::labyrinthCleaner()
{
    boss = false;//сбрасываемсостояние босса
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
             tmpData[i][j].setStr(idWall, nameEv[0]);//зануляем все данные
        }
    }
}

bool GeneratorLabyrinth::checkPass(QString idField, int direction)
{
    QString ch = "1";// переменная с которой происходит  сравнение
    return idField[direction] == ch;// если символ в ячейке direction равен 1 то возврает значение true, иначе false
}

bool GeneratorLabyrinth::checkBorderX(int direction, int x)
{
    return ((x + direction) >= 0 && (x + direction) < this->col);// если координата + направление находятся в пределах массива, то возврает значение true, иначе false
}

bool GeneratorLabyrinth::checkBorderY(int direction, int y)
{
    return ((y + direction) >= 0 && (y + direction) < this->row);// если координата + направление находятся в пределах массива, то возврает значение true, иначе false
}

bool GeneratorLabyrinth::checkWall(QString idField)
{
    return idField == idWall;// если айди поля равно айди стены, то возврает значение true, иначе false
}

QString GeneratorLabyrinth::randomizeEvent()
{
    int cube = QRandomGenerator::global()->bounded(100);// бросаем "кубик" от 0 до 100
    // возвращаем событие относительно выпавшего значения
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
    // запускаем цикл от 0 до 3(проверяем 4 направления)
    for(int i = 0; i < idWall.size(); i++){
        //если обнаружен проход в итом направлении
        if(checkPass(tmpData[x][y].getId(), i)){
            int direction;
            int size;
            // выполняем код в зависимости от направления, но везде одна суть
            // ставим direction и размер вектора
            // делаем проверку на выход за пределы массива
            // делаем проверку на наличие стены
            // если то направление заканчивается стеной, то генерируем поле с противоположным проходом
            // рандомизируем событие в новой ячейке
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
            //проверяем ячейки
            //если в ячейке не стена, то генерируем проходы вокруг
            if(!checkWall(tmpData[i][j].getId())){
                generatingPassageWays(i, j);
            }
        }
    }
}

TmpData **GeneratorLabyrinth::getLab()
{
    //пока лабиринт не удовлетворит качествам он будет очищаться и создавться заново
    while(!qualityControl()){
        labyrinthCleaner();
        generateLabyrinth();
    }
    return tmpData; // возвращаем данные о лабиринте
}
