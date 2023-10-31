#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwindowgame.h"

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

private:
    Ui::MainWindow *ui;
    MainWindowGame* mwg;
};
#endif // MAINWINDOW_H
