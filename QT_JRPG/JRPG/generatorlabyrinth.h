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
    GeneratorLabyrinth(int row, int col);
    ~GeneratorLabyrinth();

    TmpData **getLab();
private:
    const QString idWall = "0000";
    const QVector<QString> idField {
        "0001", "0010", "0011", "0100", "0101",
        "0110", "0111", "1000", "1001", "1010",
        "1011", "1100", "1101", "1110", "1111"
    };
    const QVector<QString> idNorth{
        "1000", "1001", "1010", "1011",
        "1100", "1101", "1110", "1111"
    };
    const QVector<QString> idSouth{
        "0100", "0101", "0110", "0111",
        "1100", "1101", "1110", "1111"
    };
    const QVector<QString> idEast{
        "0010", "0011", "0110", "0111",
        "1010", "1011", "1110", "1111"
    };
    const QVector<QString> idWest{
        "0001", "0011", "0101", "0111",
        "1001", "1011", "1101", "1111"
    };
    const QVector<QString> nameEv{
        "wall", "empty" , "enemy", "chest", "boss", "entry"
    };
    bool boss;
    int row, col;

    TmpData** tmpData;

    bool checkPass(QString idField, int direction);
    bool checkBorderX(int direction, int x);
    bool checkBorderY(int direction, int y);
    bool checkWall(QString idField);
    QString randomizeEvent();
    void generatingPassageWays(int x, int y);
    void allGenerateLabyrinth();
    void generateLabyrinth();
    bool qualityControl();
    void labyrinthCleaner();
};

#endif // GENERATORLABYRINTH_H
