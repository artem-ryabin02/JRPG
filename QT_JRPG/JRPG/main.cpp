#include "mainwindow.h"

#include <QApplication>
#include <QSqlDriver>
#include <QSqlDatabase>
#include <QSqlQuery>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowState(Qt::WindowMaximized);
    w.showFullScreen();
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("jrpg");
    db.setPort(5432);
    db.setUserName("postgres");
    db.setPassword("1111");
    if (!db.open()) {
        qDebug() << "Error: Unable to open database";
    }
    else {
        qDebug() << "Database connection established.";
        QSqlQuery query("SELECT name FROM enemy");
        if (!query.exec()) {
            qDebug() << "Error: Unable to execute query";
            while (query.next()) {
                QString name = query.value(0).toString();
                qDebug() << " Name:" << name;
            }
        }
    }

    db.close();
    return a.exec();
}
