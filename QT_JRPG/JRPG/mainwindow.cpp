#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFontDatabase>

const static QString MAIN_FON = ":/assets/background/menu_demo.png";
const static QString FIGHT_FON = ":/assets/background/boy_fon.png";
const static QString FON = ":/assets/background/fon.jpg";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralwidget->setContentsMargins(0,0,0,0);
    
    QDir dirSaves;
    if (!dirSaves.exists("saves")){
        dirSaves.mkdir("saves");
    }

    loadSounds();
    loadDB();

    int id = QFontDatabase::addApplicationFont(":/assets/PressStart2P-Regular.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont textFont(family, 36);

    volumeWidget = new QWidget(ui->centralwidget);
    volumeWidget->setLayout(new QHBoxLayout);
    volumeWidget->setGeometry(1600, 0, 305, 55);


    slider = new QSlider(Qt::Horizontal);

    slider->setMinimum(0);
    slider->setMaximum(100);
    slider->setValue(50);



    label = new QLabel();

    label->setText(QString::number(slider->value()));
    label->setFont(textFont);
    label->setStyleSheet("Background:grey");
    label->setFixedSize(140, 60);
    label->setAlignment(Qt::AlignCenter);

    volumeWidget->layout()->addWidget(label);
    volumeWidget->layout()->addWidget(slider);

    wmm = new MainMenu(ui->centralwidget);

    newCharacter();
    newGame();

    twn = new TalkingWithNPC(ui->centralwidget);
    twn->setHidden(true);

    clv = new CharListView(ui->centralwidget);
    clv->setHidden(true);

    ba = new BatlleArena(ui->centralwidget);
    ba->setHidden(true);

    mb = new MagicBook(ui->centralwidget);
    mb->setHidden(true);


    setBackground(MAIN_FON);

    connect(wmm, &MainMenu::newGame, this, &MainWindow::onButtonNewGameClicked);
    connect(wmm, &MainMenu::loadGame, this, &MainWindow::onButtonLoadGameClicked);
    connect(wmm, &MainMenu::exit, this, &MainWindow::onButtonExitClicked);

    connect(slider, &QSlider::sliderReleased, this, &MainWindow::valueChanged);

    connect(twn, &TalkingWithNPC::exitFromTWNPC, this, &MainWindow::recGoodbye);

    connect(clv, &CharListView::goBack, this, &MainWindow::returnFromCharList);


    connect(ba, &BatlleArena::win, this, &MainWindow::returnFromBattleArena);
    connect(ba, &BatlleArena::loose, this, &MainWindow::gameOver);
    connect(ba, &BatlleArena::escape, this, &MainWindow::escapeFromBattleArena);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete wmm;
    delete twn;
    delete wg;
    delete clv;
    delete ba;
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

void MainWindow::newCharacter()
{
    wcnc = new CreateNewCharacter(ui->centralwidget);


    connect(wcnc, &CreateNewCharacter::back, this, &MainWindow::returnMainMenu);
    connect(wcnc, &CreateNewCharacter::ready, this, &MainWindow::startNewGame);
    wcnc->setHidden(true);


}

void MainWindow::newGame()
{
    wg = new Game(ui->centralwidget);
    wg->setFHidden(true);
    connect(wg, &Game::loadGame, this, &MainWindow::onButtonLoadGameClicked);
    connect(wg, &Game::inventory, this, &MainWindow::onButtonInvetoryClicked);
    connect(wg, &Game::charList, this, &MainWindow::onButtonCharListClicked);
    connect(wg, &Game::exit, this, &MainWindow::onButtonExitClicked);
    connect(wg, &Game::talkWithNPC, this, &MainWindow::recTalk);
    connect(wg, &Game::transmitEnemyEntry, this, &MainWindow::recEnemy);

    connect(wg, &Game::goBlockSig, this, [this](){blockSignals(true);});
    connect(wg, &Game::goUnBlockSig, this, [this](){blockSignals(false);});

    connect(this, &MainWindow::wPress, wg, &Game::recaivedNorth);
    connect(this, &MainWindow::aPress, wg, &Game::recaivedWest);
    connect(this, &MainWindow::sPress, wg, &Game::recaivedSouth);
    connect(this, &MainWindow::dPress, wg, &Game::recaivedEast);
    connect(this, &MainWindow::readyToLoad, wg, &Game::receiverLoad);
}

void MainWindow::copyFile(QString SND_FILE_NAME, QString SND_FILE )
{
    QFile outB( SND_FILE_NAME );
    if( !outB.exists() ) {
        QFile in( ":/assets/music/" + SND_FILE );

        if (in.copy(SND_FILE_NAME))
        {
            qDebug() << "true";
        }
        else qDebug() << QString("error copy sound. Path %1!").arg(SND_FILE_NAME);
    }
}

void MainWindow::loadSounds()
{
    QDir dirMusic;
    if (!dirMusic.exists("music")){
        dirMusic.mkdir("music");
    }
    static const QString SND_FILE_BUTTTON = "button_click.wav";
    static const QString SND_FILE_STEPS_V = "sound_steps_on_village.wav";
    static const QString SND_FILE_STEPS_L = "sound_steps_on_labyrinth.wav";
    static const QString SND_FILE_ATTACK = "attack_sound.wav";
    static const QString SND_FILE_DEFENCE = "defence_sound.wav";
    static const QString SND_FILE_SKILL = "skill_sound.wav";
    static const QString SND_FILE_PATH = QDir::currentPath() + "/music/";
    QString SND_FILE_NAME = SND_FILE_PATH + SND_FILE_BUTTTON;
    copyFile(SND_FILE_NAME, SND_FILE_BUTTTON);
    SND_FILE_NAME = SND_FILE_PATH + SND_FILE_STEPS_V;
    copyFile(SND_FILE_NAME, SND_FILE_STEPS_V);
    SND_FILE_NAME = SND_FILE_PATH + SND_FILE_STEPS_L;
    copyFile(SND_FILE_NAME, SND_FILE_STEPS_L);
    SND_FILE_NAME = SND_FILE_PATH + SND_FILE_ATTACK;
    copyFile(SND_FILE_NAME, SND_FILE_ATTACK);
    SND_FILE_NAME = SND_FILE_PATH + SND_FILE_DEFENCE;
    copyFile(SND_FILE_NAME, SND_FILE_DEFENCE);
    SND_FILE_NAME = SND_FILE_PATH + SND_FILE_SKILL;
    copyFile(SND_FILE_NAME, SND_FILE_SKILL);

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
        else qDebug() << QString("error copy db. Path %1!").arg(SND_FILE_NAME);
    }
}

void MainWindow::setBackground(QString name)
{
    QPixmap bkgnd(name);
    bkgnd = bkgnd.scaled(size(), Qt::IgnoreAspectRatio);
    QPalette p = palette();
    p.setBrush(QPalette::Window, bkgnd);
    setPalette(p);
}

void MainWindow::onButtonExitClicked()
{
    this->close();
}


void MainWindow::onButtonNewGameClicked()
{
    wmm->setHidden(true);
    setBackground(FON);
    wcnc->setHidden(false);
}


void MainWindow::onButtonLoadGameClicked()
{
    setBackground(FON);
    wmm->setHidden(true);
    clv->setHidden(true);
    twn->setHidden(true);
    ba->setHidden(true);
    if (wcnc != nullptr){
        wcnc->setHidden(true);
    }
    if (wg == nullptr){
        newGame();
    }
    wg->setHidden(false);
    emit readyToLoad();

}

void MainWindow::onButtonInvetoryClicked()
{
    ui->statusbar->showMessage("ПОКА НЕ РАБОТАЕТ", 2000);
}

void MainWindow::onButtonCharListClicked()
{
    wg->setFHidden(true);
    blockSignals(true);
    clv->setCat(wg->getCat());
    clv->setHidden(false);
}

void MainWindow::returnFromCharList()
{
    wg->setHidden(false);
    blockSignals(false);
    clv->setHidden(true);
}

void MainWindow::recTalk()
{
    wg->setFHidden(true);
    blockSignals(true);
    twn->setCat(wg->getCat());
    twn->setHidden(false);

}

void MainWindow::recGoodbye()
{
    wg->setHidden(false);
    blockSignals(false);
    wg->setCat(twn->getCat());
    twn->setHidden(true);
}

void MainWindow::recEnemy()
{
    setBackground(FIGHT_FON);
    wg->setFHidden(true);
    ba->startBattle(wg->getCat(), wg->getBossF());
    if (wg->getBossF()) wg->setBossF(false);
    ba->setHidden(false);
}

void MainWindow::returnFromBattleArena()
{
    setBackground(FON);
    wg->setHidden(false);
    wg->setCat(ba->getHero());
    ba->setHidden(true);
}

void MainWindow::escapeFromBattleArena()
{
    setBackground(FON);
    wg->setHidden(false);
    wg->setCat(ba->getHero());
    ba->setHidden(true);
}

void MainWindow::returnMainMenu()
{
    setBackground(MAIN_FON);
    wcnc->setHidden(true);
    wmm->setHidden(false);
}

void MainWindow::startNewGame()
{
    wcnc->setHidden(true);

    wg->setCat(wcnc->getCat());
    wg->setHidden(false);
}

void MainWindow::gameOver()
{
    wmm->setHidden(false);
    setBackground(MAIN_FON);
    if (wg != nullptr && wcnc != nullptr){
        delete wg;
        wg = nullptr;
        delete wcnc;
        wcnc = nullptr;
    }
    ba->setHidden(true);
    if (wg == nullptr){
        newGame();
    }
    if (wcnc == nullptr){
        newCharacter();
    }
}

void MainWindow::valueChanged(){
    label->setText(QString::number(slider->value()));
    float v = (float)slider->value() / 100;
    wg->setVolume(v);
    wmm->setVolume(v);
    clv->setVolume(v);
    wcnc->setVolume(v);
    twn->setVolume(v);
    ba->setVolume(v);
}



