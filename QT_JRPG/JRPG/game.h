#ifndef GAME_H
#define GAME_H

#include "boardlabyrinth.h"
#include "boardlocation.h"
#include "hero.h"
#include "imagebutton.h"
#include <QObject>
#include <QWidget>
#include <QProgressBar>

class Game: public QWidget
{
    Q_OBJECT
public:
    explicit Game(QWidget* parent = nullptr);
    ~Game();

    void setHidden(bool hidden);
    void setFHidden(bool hidden);
    void setLabAct(bool newLabAct);

    Hero getCat() const;
    void setCat(const Hero &newCat);

private slots:
    void onPushExitButtonClicked();
    void onPushInventoryButtonClicked();
    void onPushCharListButtonClicked();
    void onPushLoadButtonClicked();
    void receivedSignalDialogWithNPC();

    void receivedSignalEntryLab();
    void receivedSignalExitLab();

    void receiverChest();

public slots:
    void recaivedSouth();
    void recaivedNorth();
    void recaivedEast();
    void recaivedWest();


private:

    BoardLocation* bl;
    BoardLabyrinth* blb;
    QWidget* wBoard;
    QWidget* wBoardLab;
    QWidget* wHPMP;
    QWidget* wParametrs;
    QWidget* wButtoms;

    QLabel* lblStr;
    QLabel* lblVit;
    QLabel* lblAgl;
    QLabel* lblPer;
    QLabel* lblInt;
    QLabel* lblWis;
    QLabel* lblParametrs;
    QLabel* lblHero;
    QProgressBar* pbHP;
    QProgressBar* pbMP;

    QWidget* artCounter;
    QLabel* artefact;
    QLabel* counter;

    ImageButton* chlb;
    ImageButton* invb;
    ImageButton* lgb;
    ImageButton* egb;

    Hero cat;
    int countArt = 0;
    bool labAct = 0;
signals:
    void exit();
    void charList();
    void inventory();
    void loadGame();
    void talkWithNPC();

    void transmitEnemyEntry();

};

#endif // GAME_H
