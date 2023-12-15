#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QDir>
#include <QSlider>
#include <QLabel>

#include "charlistview.h"
#include "game.h"
#include "mainmenu.h"
#include "talkingwithnpc.h"
#include "batllearena.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void onButtonExitClicked();

    void onButtonNewGameClicked();

    void onButtonLoadGameClicked();
    void onButtonInvetoryClicked();
    void onButtonCharListClicked();
    void returnFromCharList();
    void recTalk();
    void recGoodbye();
    void recEnemy();
    void returnFromBattleArena();
    void escapeFromBattleArena();
    void gameOver();

    void valueChanged();
protected:
    void keyPressEvent(QKeyEvent *event);
private:
    Ui::MainWindow *ui;
    MainMenu* wmm;
    Game* wg;
    TalkingWithNPC* twn;
    CharListView* clv;
    BatlleArena* ba;
    QWidget *volumeWidget;
    QSlider *slider;
    QLabel *label;

    void newGame();

    void loadSouns();
    void loadDB();
signals:
    void wPress();
    void aPress();
    void sPress();
    void dPress();
    void volumeChanged();

};
#endif // MAINWINDOW_H
