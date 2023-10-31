#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    QPixmap bkgnd(":/assets/menu_demo.png");
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
    QPalette p = palette();
    p.setBrush(QPalette::Window, bkgnd);
    setPalette(p);

    mwg = new MainWindowGame();


}

MainWindow::~MainWindow()
{
    delete ui;
    delete mwg;
}



void MainWindow::on_buttonExit_clicked()
{
    this->close();
}


void MainWindow::on_buttonNewGame_clicked()
{

    this->close();
    mwg->showFullScreen();
}


void MainWindow::on_buttonLoadGame_clicked()
{
    ui->statusbar->showMessage("ПОКА НЕ РАБОТАЕТ", 2000);
}

