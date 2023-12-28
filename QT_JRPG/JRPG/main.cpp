#include "mainwindow.h"

#include <QApplication>
#include <QSplashScreen>
#include <QTime>
#include <QElapsedTimer>
#include <QString>
#include <QFontDatabase>

static const int LOAD_TIME_MSEC = 2 * 1000;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    int id = QFontDatabase::addApplicationFont(":/assets/PressStart2P-Regular.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont textFont(family, 90);

    QPixmap pix(":/assets/background/menu_demo.png");
    QSplashScreen splash(pix);
    splash.setFont(textFont);

    splash.show();
    a.processEvents();

    QElapsedTimer timer;
    timer.start();
    while(timer.elapsed() < LOAD_TIME_MSEC){
        splash.showMessage(QString("Mustachioed \n      Guard"), Qt::AlignCenter, Qt::lightGray);
        splash.setPixmap(pix);
        a.processEvents();
    }

    w.setWindowState(Qt::WindowMaximized);
    w.showFullScreen();

    splash.finish(&w);

    return a.exec();
}
