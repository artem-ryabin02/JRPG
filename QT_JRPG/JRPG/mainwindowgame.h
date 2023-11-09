#ifndef MAINWINDOWGAME_H
#define MAINWINDOWGAME_H

#include <QMainWindow>
#include "boardlocation.h"
#include "dialogwithnpc.h"

namespace Ui {
class MainWindowGame;
}

class MainWindowGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowGame(QWidget *parent = nullptr);
    ~MainWindowGame();

protected:
    void keyPressEvent(QKeyEvent *event)override;
private slots:
    void on_pushExitButton_clicked();
    void on_pushInventoryButton_clicked();
    void on_pushCharListButton_clicked();
    void on_pushLoadButton_clicked();


    void receivedSignalDialogWithNPC();
    void receivedSignalExitDialogWithNPC();

private:
    Ui::MainWindowGame* ui;
    BoardLocation* bl;
    DialogWithNPC* dwNPC;
    QWidget* w;
signals:
    void wPress();
    void aPress();
    void sPress();
    void dPress();
};

#endif // MAINWINDOWGAME_H
