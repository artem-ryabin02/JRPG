#ifndef BOARDLABYRINTH_H
#define BOARDLABYRINTH_H

#include "fieldlabyrinth.h"
#include "tmpdata.h"

#include <QGridLayout>
#include <QMediaPlayer>
#include <QAudioOutput>
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

    void setDisable(bool disable);

    void setVolume(int volume);


private:
    QGridLayout* grid;
    FieldLabyrinth*** fl;
    QMediaPlayer* player;
    QAudioOutput* ao;
    int cols = 10;
    int rows = 10;
    int xHero = 3;
    int yHero = 1;

    void loadBoardLab(TmpData **tmpLab );
    void initialization();
    bool isCanGo(int x, int y, int nx, int ny);

    std::map<NAME_FIELD_LAB, QString> fieldName ={
        {NAME_FIELD_LAB::E, "E.png"},
        {NAME_FIELD_LAB::N, "N.png"},
        {NAME_FIELD_LAB::NE, "NE.png"},
        {NAME_FIELD_LAB::NS, "NS.png"},
        {NAME_FIELD_LAB::NSE, "NSE.png"},
        {NAME_FIELD_LAB::NSW, "NSW.png"},
        {NAME_FIELD_LAB::NSWE, "NSWE.png"},
        {NAME_FIELD_LAB::NW, "NW.png"},
        {NAME_FIELD_LAB::NWE, "NWE.png"},
        {NAME_FIELD_LAB::S, "S.png"},
        {NAME_FIELD_LAB::SE, "SE.png"},
        {NAME_FIELD_LAB::SW, "SW.png"},
        {NAME_FIELD_LAB::SWE, "SWE.png"},
        {NAME_FIELD_LAB::W, "W.png"},
        {NAME_FIELD_LAB::WALL, "WALL.png"},
        {NAME_FIELD_LAB::WE, "WE.png"}
    };

signals:
    void enemy();
    void chest();
    void boss();
    void entry();

};

#endif // BOARDLABYRINTH_H
