#ifndef BOARDLOCATION_H
#define BOARDLOCATION_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QFile>
#include <map>
#include <QProcess>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QDir>

#include "fieldlocation.h"

enum class NAME_OBJECT{
    HERO,
    NPC,
    NONE
};

class BoardLocation: public QWidget
{
    Q_OBJECT
public:
    explicit BoardLocation(QWidget* parent=nullptr);
    ~BoardLocation();
    void rescale(int _size);

    void updatePostion(int r, int c);
    void setDisable(bool disable);

    void setVolume(int volume);
protected:

private:
    QGridLayout* grid;
    FieldLocation*** fl;
    QMediaPlayer *player;
    QAudioOutput* ao;
    int cols = 7;
    int rows = 7;
    int xHero = 3;
    int yHero = 1;





    std::map<NAME_FIELD, QString> fieldName ={
        {NAME_FIELD::GRASS, "grass_middle.png"},
        {NAME_FIELD::WATER, "water.png"},
        {NAME_FIELD::GRASS_WATER_B, "grass_water_bottom.png"},
        {NAME_FIELD::GRASS_WATER_T, "grass_water_top.png"},
        {NAME_FIELD::GRASS_WATER_S, "grass_water_side.png"},
        {NAME_FIELD::GRASS_WATER_C_B, "grass_water_corner_bottom.png"},
        {NAME_FIELD::GRASS_WATER_C_T, "grass_water_corner_top.png"},
        {NAME_FIELD::LABYRINTH_ENTRY, "vkhod.png"},
        {NAME_FIELD::NONE, ""}
    };

    void loadBoardVillage(QFile& file);
    void initialization();


signals:
    void signalDialogWithNPC();
    void signalEntryLabyrinth();
};

#endif // BOARDLOCATION_H
