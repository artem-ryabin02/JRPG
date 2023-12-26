#ifndef GENERATORLABYRINTH_H
#define GENERATORLABYRINTH_H

#include "tmpdata.h"
#include <QString>
#include <map>
#include <QRandomGenerator>
#include <QTime>



class GeneratorLabyrinth
{
public:
    GeneratorLabyrinth(int row, int col);//  конструктор на вход подается количество строк и столбцов
    ~GeneratorLabyrinth();//деконструктор

    TmpData **getLab();// геттер для передачи данных лабиринта
private:
    const QString idWall = "0000";// айди стены,тип просто обозначение нулевого значения
    const QVector<QString> idField {// вектор со всеми возможными полями для генерации лабиринта
        "0001", "0010", "0011", "0100", "0101",
        "0110", "0111", "1000", "1001", "1010",
        "1011", "1100", "1101", "1110", "1111"
    };
    const QVector<QString> idNorth{// вектор с полями лабиринта у которых есть выход на север
        "1000", "1001", "1010", "1011",
        "1100", "1101", "1110", "1111"
    };
    const QVector<QString> idSouth{// вектор с полями лабиринта у которых есть выход на юг
        "0100", "0101", "0110", "0111",
        "1100", "1101", "1110", "1111"
    };
    const QVector<QString> idEast{// вектор с полями лабиринта у которых есть выход на восток
        "0010", "0011", "0110", "0111",
        "1010", "1011", "1110", "1111"
    };
    const QVector<QString> idWest{// вектор с полями лабиринта у которых есть выход на запад
        "0001", "0011", "0101", "0111",
        "1001", "1011", "1101", "1111"
    };
    const QVector<QString> nameEv{// ветктор с названиями ивентов (событий)
        "wall", "empty" , "enemy", "chest", "boss", "entry"
    };
    bool boss;//переменная отвечающая за наличие босса в лабиринте
    int row, col;//кол-во строк и столбцов

    TmpData** tmpData;//массив данных куда записывается лабиринт

    bool checkPass(QString idField, int direction);// метод с помощью которого мы узнаем: есть ли в том направлении проход. На вход идут айди поля и айди напрвления
    bool checkBorderX(int direction, int x);//проверка границ по оси Х. На вход идут айди направления и координата.
    bool checkBorderY(int direction, int y);//проверка границ по оси У. На вход идут айди направления и координата.
    bool checkWall(QString idField);//проверяет является ли поле стеной. На вход идет айди поля
    QString randomizeEvent();//рандомизация событий
    void generatingPassageWays(int x, int y);// генерация проходов вокруг заданной точки. На вход идут координаты
    void allGenerateLabyrinth();//один цикл генерации лабиринта
    void generateLabyrinth();//полная генераци лабиринта
    bool qualityControl();//контроль качества лабиринта
    void labyrinthCleaner();//очистка лабиринта
};

#endif // GENERATORLABYRINTH_H
