#include "mainwindow.h"
#include "imagebutton.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    QPixmap bkgnd(":/assets/background/menu_demo.png");
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
    QPalette p = palette();
    p.setBrush(QPalette::Window, bkgnd);
    setPalette(p);
    w = new QWidget(ui->centralwidget);
    w->setObjectName("containerWidget");
    w->setLayout(new QVBoxLayout);
    w->setGeometry(1488, 435, 375, 250);
    ImageButton* nbg = new ImageButton(":/assets/buttonAndText/new_game_button.png");
    nbg->setObjectName("newGameB");
    nbg->setCursor(Qt::CursorShape::PointingHandCursor);
    w->layout()->addWidget(nbg);
    w->layout()->setAlignment(nbg, Qt::AlignHCenter);
    ImageButton* lbg = new ImageButton(":/assets/buttonAndText/load_button.png");
    lbg->setObjectName("loadGameB");
    lbg->setCursor(Qt::CursorShape::PointingHandCursor);
    w->layout()->addWidget(lbg);
    w->layout()->setAlignment(lbg, Qt::AlignHCenter);
    ImageButton* ebg = new ImageButton(":/assets/buttonAndText/exit_button.png");
    ebg->setObjectName("exitGameB");
    ebg->setCursor(Qt::CursorShape::PointingHandCursor);
    w->layout()->addWidget(ebg);
    w->layout()->setAlignment(ebg, Qt::AlignHCenter);
    connect(nbg, &ImageButton::clicked, this, &MainWindow::on_buttonNewGame_clicked);
    connect(lbg, &ImageButton::clicked, this, &MainWindow::on_buttonLoadGame_clicked);
    connect(ebg, &ImageButton::clicked, this, &MainWindow::on_buttonExit_clicked);





    mwg = new MainWindowGame();


}

MainWindow::~MainWindow()
{
    delete ui;
    delete mwg;
    delete w;
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

void MainWindow::objFilter(QObject *obj)
{
    if (obj->objectName() == "newGameB"){
        on_buttonNewGame_clicked();
    }
    if (obj->objectName() == "loadGameB"){
        on_buttonLoadGame_clicked();
    }
    if (obj->objectName() == "exitGameB"){
        on_buttonExit_clicked();
    }
}


