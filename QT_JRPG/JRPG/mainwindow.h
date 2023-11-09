#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
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

    //bool eventFilter(QObject* obj, QEvent* e);
    void objFilter(QObject* obj);

private:
    Ui::MainWindow *ui;
    MainWindowGame* mwg;
    QWidget* w;

};
#endif // MAINWINDOW_H
