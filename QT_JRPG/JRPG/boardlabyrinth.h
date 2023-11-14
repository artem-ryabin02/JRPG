#ifndef BOARDLABYRINTH_H
#define BOARDLABYRINTH_H

#include "fieldlabyrinth.h"
#include "tmpdata.h"

#include <QGridLayout>
#include <QWidget>
#include <map>

class BoardLabyrinth : public QWidget
{
    Q_OBJECT
public:
    explicit BoardLabyrinth(QWidget *parent = nullptr);
    ~BoardLabyrinth();
    void rescale(int _size);

    void updatePostion(int r, int c);
private:
    QGridLayout* grid;
    FieldLabyrinth*** fl;
    int cols = 7;
    int rows = 7;
    int xHero = 3;
    int yHero = 1;



    void loadBoardLab(TmpData **tmpLab );
    void initialization();
    bool isCanGo(int x, int y, int nx, int ny);
//    std::map<NAME_FIELD_LAB, QString> fieldName ={
//        {NAME_FIELD::GRASS, "grass_middle.png"},
//        {NAME_FIELD::WATER, "water.png"},
//        {NAME_FIELD::GRASS_WATER_B, "grass_water_bottom.png"},
//        {NAME_FIELD::GRASS_WATER_T, "grass_water_top.png"},
//        {NAME_FIELD::GRASS_WATER_S, "grass_water_side.png"},
//        {NAME_FIELD::GRASS_WATER_C_B, "grass_water_corner_bottom.png"},
//        {NAME_FIELD::GRASS_WATER_C_T, "grass_water_corner_top.png"},
//        {NAME_FIELD::LABYRINTH_ENTRY, "vkhod.png"},
//        {NAME_FIELD::NONE, ""}
//    };

signals:

};

#endif // BOARDLABYRINTH_H
