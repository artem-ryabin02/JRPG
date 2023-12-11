#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralwidget->setContentsMargins(0,0,0,0);

    loadSouns();
    loadDB();

    wmm = new MainMenu(ui->centralwidget);
    //wmm->setHidden(true);

    wg = new Game(ui->centralwidget);
    wg->setHidden(true);

    twn = new TalkingWithNPC(ui->centralwidget);
    twn->setHidden(true);

    //clv = new CharListView(ui->centralwidget);
    //clv->setHidden(true);

    QPixmap bkgnd(":/assets/background/menu_demo.png");
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
    QPalette p = palette();
    p.setBrush(QPalette::Window, bkgnd);
    setPalette(p);

    connect(wmm, &MainMenu::newGame, this, &MainWindow::on_buttonNewGame_clicked);
    connect(wmm, &MainMenu::loadGame, this, &MainWindow::on_buttonLoadGame_clicked);
    connect(wmm, &MainMenu::exit, this, &MainWindow::on_buttonExit_clicked);

    connect(wg, &Game::loadGame, this, &MainWindow::on_buttonLoadGame_clicked);
    connect(wg, &Game::inventory, this, &MainWindow::on_buttonInvetory_clicked);
    connect(wg, &Game::charList, this, &MainWindow::on_buttonCharList_clicked);
    connect(wg, &Game::exit, this, &MainWindow::on_buttonExit_clicked);
    connect(wg, &Game::talkWithNPC, this, &MainWindow::recTalk);

    connect(twn, &TalkingWithNPC::exitFromTWNPC, this, &MainWindow::recGoodbye);



    connect(this, &MainWindow::wPress, wg, &Game::recaivedNorth);
    connect(this, &MainWindow::aPress, wg, &Game::recaivedWest);
    connect(this, &MainWindow::sPress, wg, &Game::recaivedSouth);
    connect(this, &MainWindow::dPress, wg, &Game::recaivedEast);




}

MainWindow::~MainWindow()
{
    delete ui;
    delete wmm;
    delete twn;
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    switch (event->key()) {
    case Qt::Key_W:
        emit wPress();
        break;
    case Qt::Key_A:
        emit aPress();
        break;
    case Qt::Key_S:
        emit sPress();
        break;
    case Qt::Key_D:
        emit dPress();
        break;
    default:
        break;
    }
}

void MainWindow::loadSouns()
{
    QDir dirMusic;
    if (!dirMusic.exists("music")){
        dirMusic.mkdir("music");
    }
    static const QString SND_FILE_BUTTTON = "button_click.wav";
    static const QString SND_FILE_STEPS_V = "sound_steps_on_village.wav";
    static const QString SND_FILE_STEPS_L = "sound_steps_on_labyrinth.wav";
    static const QString SND_FILE_PATH = QDir::currentPath() + "/music/";
    QString SND_FILE_NAME = SND_FILE_PATH + SND_FILE_BUTTTON;

    QFile outB( SND_FILE_NAME );
    if( !outB.exists() ) {
        QFile in( ":/assets/music/" + SND_FILE_BUTTTON );

        if (in.copy(SND_FILE_NAME))
        {
            qDebug() << "true";
        }
        else qDebug() << QString("error copy sound. Path %1!").arg(SND_FILE_NAME);
    }
    SND_FILE_NAME = SND_FILE_PATH + SND_FILE_STEPS_V;
    QFile outSV( SND_FILE_NAME );
    if( !outSV.exists() ) {
        QFile in( ":/assets/music/" + SND_FILE_STEPS_V );

        if (in.copy(SND_FILE_NAME))
        {
            qDebug() << "true";
        }
        else qDebug() << QString("error copy sound. Path %1!").arg(SND_FILE_NAME);

    }
    SND_FILE_NAME = SND_FILE_PATH + SND_FILE_STEPS_L;
    QFile outSL( SND_FILE_NAME );
    if( !outSL.exists() ) {
        QFile in( ":/assets/music/" + SND_FILE_STEPS_L );

        if (in.copy(SND_FILE_NAME))
        {
            qDebug() << "true";
        }
        else qDebug() << QString("error copy sound. Path %1!").arg(SND_FILE_NAME);
    }
}

void MainWindow::loadDB()
{
    QDir dirDB;
    if (!dirDB.exists("db")){
        dirDB.mkdir("db");
    }
    static const QString SND_FILE_DB = "jrpg.sqlite";
    static const QString SND_FILE_PATH = QDir::currentPath() + "/db/";
    QString SND_FILE_NAME = SND_FILE_PATH + SND_FILE_DB;

    QFile outB( SND_FILE_NAME );
    if( !outB.exists() ) {
        QFile in( ":/assets/" + SND_FILE_DB );

        if (in.copy(SND_FILE_NAME))
        {
            qDebug() << "true";
        }
        else qDebug() << QString("error copy sound. Path %1!").arg(SND_FILE_NAME);
    }
}

void MainWindow::on_buttonExit_clicked()
{
    this->close();
}


void MainWindow::on_buttonNewGame_clicked()
{

    wmm->setHidden(true);
    wg->setHidden(false);

}


void MainWindow::on_buttonLoadGame_clicked()
{
    ui->statusbar->showMessage("ПОКА НЕ РАБОТАЕТ", 2000);
}

void MainWindow::on_buttonInvetory_clicked()
{
    ui->statusbar->showMessage("ПОКА НЕ РАБОТАЕТ", 2000);
}

void MainWindow::on_buttonCharList_clicked()
{
    //wg->setHidden(true);
    //clv->setHidden(false);
}

void MainWindow::recTalk()
{
    wg->setHidden(true);
    //_sleep(1000);
    twn->setHidden(false);
}

void MainWindow::recGoodbye()
{
    wg->setHidden(false);
    //_sleep(1000);
    twn->setHidden(true);
}



