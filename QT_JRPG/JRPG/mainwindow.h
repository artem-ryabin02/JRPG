#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QDir>
#include "charlistview.h"
#include "game.h"
#include "mainmenu.h"
#include "talkingwithnpc.h"


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
    void on_buttonExit_clicked();

    void on_buttonNewGame_clicked();

    void on_buttonLoadGame_clicked();
    void on_buttonInvetory_clicked();
    void on_buttonCharList_clicked();
    void recTalk();
    void recGoodbye();


protected:
    void keyPressEvent(QKeyEvent *event);
private:
    Ui::MainWindow *ui;
    MainMenu* wmm;
    Game* wg;
    TalkingWithNPC* twn;
    CharListView* clv;

    void loadSouns();
    void loadDB();
signals:
    void wPress();
    void aPress();
    void sPress();
    void dPress();

};
#endif // MAINWINDOW_H
