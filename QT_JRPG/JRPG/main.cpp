#include "dbcontroller.h"
#include "enemy.h"
#include "mainwindow.h"

#include <QApplication>
#include <QSqlDriver>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowState(Qt::WindowMaximized);
    w.showFullScreen();
    Enemy rand = DBcontroller::randEnemy();
    rand.displayStatus();
    return a.exec();
}
