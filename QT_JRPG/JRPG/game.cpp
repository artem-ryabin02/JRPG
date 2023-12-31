#include "game.h"

#include <QFileDialog>
#include <QFontDatabase>
#include <QMessageBox>
#include <QRandomGenerator>

Game::Game(QWidget *parent)
    : QWidget{parent}, cat("Cater", 5, 5, 5, 5, 5, 5)
{
    int id = QFontDatabase::addApplicationFont(":/assets/PressStart2P-Regular.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont textFont(family, 36);

    background = new QWidget(parent);
    background->setStyleSheet("background: grey");
    background->setGeometry(1120, 55, 770, 1010);

    wBoard = new QWidget(parent);
    wBoard->setObjectName("boardWidget");
    wBoard->setLayout(new QVBoxLayout);
    wBoard->setGeometry(0, 0, 1080, 1080);
    bl = new BoardLocation(wBoard);
    bl->rescale(wBoard->height());
    wBoardLab = new QWidget(parent);
    wBoardLab->setObjectName("boardLabWidget");
    wBoardLab->setLayout(new QGridLayout);
    wBoardLab->setGeometry(0, 0, 1080, 1080);

    wButtoms = new QWidget(parent);
    wButtoms->setObjectName("buttomsWidget");
    wButtoms->setLayout(new QVBoxLayout);
    wButtoms->setGeometry(1150, 750, 717, 260);
    chlb = new ImageButton(":/assets/buttonAndText/Game/char_list_button.png");
    chlb->setObjectName("charListB");
    chlb->setCursor(Qt::CursorShape::PointingHandCursor);
    wButtoms->layout()->addWidget(chlb);
    wButtoms->layout()->setAlignment(chlb, Qt::AlignHCenter);
    invb = new ImageButton(":/assets/buttonAndText/Game/inventory_button.png");
    invb->setObjectName("inventoryB");
    invb->setCursor(Qt::CursorShape::PointingHandCursor);
    wButtoms->layout()->addWidget(invb);
    wButtoms->layout()->setAlignment(invb, Qt::AlignHCenter);
    lgb = new ImageButton(":/assets/buttonAndText/Game/load_button.png");
    lgb->setObjectName("loadGameB");
    lgb->setCursor(Qt::CursorShape::PointingHandCursor);
    wButtoms->layout()->addWidget(lgb);
    wButtoms->layout()->setAlignment(lgb, Qt::AlignHCenter);
    egb = new ImageButton(":/assets/buttonAndText/Game/exit_button.png");
    egb->setObjectName("exitGameB");
    egb->setCursor(Qt::CursorShape::PointingHandCursor);
    wButtoms->layout()->addWidget(egb);
    wButtoms->layout()->setAlignment(egb, Qt::AlignHCenter);


    lblParametrs = new QLabel(parent);
    lblParametrs->setGeometry(1160, 600, 717, 109);
    lblParametrs->setPixmap(QPixmap(":/assets/buttonAndText/Game/parametrs_table.png"));
    lblStr = new QLabel(parent);
    lblVit = new QLabel(parent);
    lblVit->setGeometry(1319, 600, 54, 51);
    lblVit->setStyleSheet("background:grey");
    lblVit->setAlignment(Qt::AlignCenter);
    lblVit->setFont(textFont);
    lblVit->setText(QString::number(cat.getVitality()));
    lblStr->setGeometry(1319, 659, 54, 51);
    lblStr->setStyleSheet("background:grey");
    lblStr->setAlignment(Qt::AlignCenter);
    lblStr->setFont(textFont);
    lblStr->setText(QString::number(cat.getStrength()));

    lblAgl = new QLabel(parent);
    lblAgl->setGeometry(1570, 600, 54, 51);
    lblAgl->setStyleSheet("background:grey");
    lblAgl->setAlignment(Qt::AlignCenter);
    lblAgl->setFont(textFont);
    lblAgl->setText(QString::number(cat.getAgility()));
    lblPer = new QLabel(parent);
    lblPer->setGeometry(1570, 659, 54, 51);
    lblPer->setStyleSheet("background:grey");
    lblPer->setAlignment(Qt::AlignCenter);
    lblPer->setFont(textFont);
    lblPer->setText(QString::number(cat.getPerception()));
    lblInt = new QLabel(parent);
    lblInt->setGeometry(1823, 600, 54, 51);
    lblInt->setStyleSheet("background:grey");
    lblInt->setAlignment(Qt::AlignCenter);
    lblInt->setFont(textFont);
    lblInt->setText(QString::number(cat.getIntelligence()));
    lblWis = new QLabel(parent);
    lblWis->setGeometry(1823, 659, 54, 51);
    lblWis->setStyleSheet("background:grey");
    lblWis->setAlignment(Qt::AlignCenter);
    lblWis->setFont(textFont);
    lblWis->setText(QString::number(cat.getWisdom()));


    wHPMP = new QWidget(parent);
    wHPMP->setObjectName("HPMPWidget");
    wHPMP->setLayout(new QHBoxLayout);
    wHPMP->setGeometry(1160, 45, 720, 500);
    pbHP = new QProgressBar();
    pbMP = new QProgressBar();
    pbHP->setOrientation(Qt::Vertical);
    pbHP->setStyleSheet("QProgressBar::chunk {background:rgb(168, 41, 40); border-radius: 5px;border: .px solid black;}QProgressBar{border-radius: 5px;background:white}");
    pbHP->setFixedSize(100, 450);
    pbHP->setTextVisible(false);
    pbHP->setMaximum(cat.getMaxHealth());
    pbHP->setValue(cat.getMaxHealth());
    pbMP->setOrientation(Qt::Vertical);
    pbMP->setStyleSheet("QProgressBar::chunk {background: rgb(38, 72, 109) ;border-radius: 5px;border: px solid black;}QProgressBar{border-radius: 5px;background:white}");
    pbMP->setFixedSize(100, 450);
    pbMP->setTextVisible(false);
    pbMP->setMaximum(cat.getMaxMana());
    pbMP->setValue(cat.getMaxMana());
    lblHero = new QLabel();
    lblHero->setFixedSize(430, 500);
    QPixmap hero(":/assets/characters/gg_temp.jpg");
    hero.scaled(hero.height()*2, hero.width()*2);
    lblHero->setPixmap(hero);
    lblHero->setScaledContents(true);
    wHPMP->layout()->addWidget(pbHP);
    wHPMP->layout()->addWidget(lblHero);
    wHPMP->layout()->addWidget(pbMP);

    artCounter = new QWidget(parent);
    artCounter->setLayout(new QHBoxLayout());
    artCounter->setGeometry(1080, 0, 410, 60);
    artefact = new QLabel();
    artefact->setPixmap(QPixmap(":/assets/buttonAndText/Game/artefact.png"));
    artefact->setFont(textFont);
    counter =new QLabel(QString::number(countArt));
    counter->setFont(textFont);
    counter->setStyleSheet("background:grey");
    artCounter->layout()->addWidget(artefact);
    artCounter->layout()->addWidget(counter);

    dfefl= new DialogForExitFromLab(parent);
    dfefl->setHidden(true);

    blb = new BoardLabyrinth(wBoardLab);
    blb->rescale(wBoard->height());

    connect(blb, &BoardLabyrinth::enemy, this, &Game::transmitEnemyEntry);
    connect(blb, &BoardLabyrinth::chest, this, &Game::receiverChest);
    connect(blb, &BoardLabyrinth::entry, this, &Game::answerForExit);
    connect(blb, &BoardLabyrinth::boss, this, [this](){
        bossF = true;
        emit transmitEnemyEntry();
    });

    connect(chlb, &ImageButton::clicked, this, &Game::onPushCharListButtonClicked);
    connect(invb, &ImageButton::clicked, this, &Game::onPushInventoryButtonClicked);
    connect(lgb, &ImageButton::clicked, this, &Game::onPushLoadButtonClicked);
    connect(egb, &ImageButton::clicked, this, &Game::onPushExitButtonClicked);


    connect(bl, &BoardLocation::signalDialogWithNPC, this, &Game::receivedSignalDialogWithNPC);
    connect(bl, &BoardLocation::signalEntryLabyrinth, this, &Game::receivedSignalEntryLab);
    connect(bl, &BoardLocation::signalSave, this, &Game::receiverSave);


    connect(dfefl, &DialogForExitFromLab::yesSig, this, &Game::receivedSignalExitLab);
    connect(dfefl, &DialogForExitFromLab::noSig, this, &Game::hideAnswer);
}

Game::~Game()
{
    delete wBoard;
    delete wHPMP;
    delete wButtoms;
    delete wBoardLab;
    delete lblParametrs;
    delete lblStr;
    delete lblVit;
    delete lblAgl;
    delete lblPer;
    delete lblInt;
    delete lblWis;
    delete artCounter;
}

void Game::setHidden(bool hidden)
{
    if (!labAct){
        wBoardLab->setHidden(true);
        wBoard->setHidden(false);
    }
    else{
        wBoardLab->setHidden(false);
        wBoard->setHidden(true);
    }
    background->setHidden(hidden);
    wHPMP->setHidden(hidden);
    wButtoms->setHidden(hidden);
    lblAgl->setHidden(hidden);
    lblPer->setHidden(hidden);
    lblStr->setHidden(hidden);
    lblVit->setHidden(hidden);
    lblInt->setHidden(hidden);
    lblWis->setHidden(hidden);
    lblParametrs->setHidden(hidden);
    artCounter->setHidden(hidden);
}

void Game::setFHidden(bool hidden)
{
    background->setHidden(hidden);
    wBoardLab->setHidden(hidden);
    wBoard->setHidden(hidden);
    wHPMP->setHidden(hidden);
    wButtoms->setHidden(hidden);
    lblAgl->setHidden(hidden);
    lblPer->setHidden(hidden);
    lblStr->setHidden(hidden);
    lblVit->setHidden(hidden);
    lblInt->setHidden(hidden);
    lblWis->setHidden(hidden);
    lblParametrs->setHidden(hidden);
    artCounter->setHidden(hidden);
}

void Game::onPushExitButtonClicked()
{
    emit exit();
}

void Game::onPushInventoryButtonClicked()
{
    emit inventory();
}

void Game::onPushCharListButtonClicked()
{
    emit charList();
}

void Game::onPushLoadButtonClicked()
{
    emit loadGame();
}

void Game::receivedSignalDialogWithNPC()
{
    emit talkWithNPC();
}

void Game::receivedSignalEntryLab()
{
    wBoard->setHidden(true);
    wBoardLab->setHidden(false);
    labAct = true;
}

void Game::receivedSignalExitLab()
{
    emit goUnBlockSig();
    dfefl->setHidden(true);
    blb->regeneration();
    wBoard->setHidden(false);
    wBoardLab->setHidden(true);
    labAct = false;

}

void Game::answerForExit()
{
    emit goBlockSig();
    dfefl->setHidden(false);
}

void Game::hideAnswer()
{
    emit goUnBlockSig();
    dfefl->setHidden(true);
}

void Game::receiverChest()
{
    countArt += QRandomGenerator::global()->bounded(5);
    counter->setText(QString::number(countArt));
    cat.setCounterQuest(countArt);
}

void Game::receiverSave()
{

    QMessageBox msgFile;
    msgFile.setFixedSize(500,200);
    QString saveName = QFileDialog::getSaveFileName(this, tr("Куда хотите сохранить?"), QDir::currentPath()+"/saves", tr("Matrix Files (*.txt)"));
    QFile saveFile(saveName);
    if(!saveFile.open(QIODevice::WriteOnly | QIODevice::Text)){
        msgFile.critical(0, "Error", "Невозможно открыть файл");
        return;
    }
    QTextStream out(&saveFile);
    out << bl->getXHero()<< "|" << bl->getYHero()<<"|\n";
    out << cat.getName()<< "|\n";
    out << cat.getVitality() << "|" <<cat.getStrength() << "|" <<cat.getWisdom() << "|" <<cat.getIntelligence()
        << "|" <<cat.getAgility() << "|" <<cat.getPerception() << "|\n";
    out << cat.getIsQuest() << "|" << cat.getReadyQuest() << "|\n";
    out << cat.getMission() << "|" << cat.getCounterQuest() << "|\n";
    saveFile.close();

    cat.setHealth(cat.getMaxHealth());
    cat.setMana(cat.getMaxMana());
    pbHP->setMaximum(cat.getMaxHealth());
    pbHP->setValue(cat.getMaxHealth());
    pbMP->setMaximum(cat.getMaxMana());
    pbMP->setValue(cat.getMaxMana());

}

void Game::receiverLoad()
{
    QString inputName = QFileDialog::getOpenFileName(this, tr("Что хотите загрузить?"), QDir::currentPath()+"/saves", tr("Matrix Files (*.dat *.txt)"));
    QFile inputFile(inputName);
    QMessageBox msgFile;
    msgFile.setFixedSize(500,200);
    if(!inputFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        msgFile.critical(0, "Error", "Невозможно открыть файл");
        return;
    }
    labAct = false;
    receivedSignalExitLab();
    bl->deleteHero();
    QString xy = inputFile.readLine();
    QStringList xyList = xy.split("|");
    bl->setHero(xyList[0].toInt(), xyList[1].toInt());
    QString name = inputFile.readLine();
    name = name.left(name.lastIndexOf("|"));
    QString parametrs = inputFile.readLine();
    QStringList paramList = parametrs.split("|");
    setCat(Hero(name, paramList[0].toInt(), paramList[1].toInt(), paramList[2].toInt(),
                paramList[3].toInt(), paramList[4].toInt(), paramList[5].toInt()));
    QString boolean = inputFile.readLine();
    QStringList boolList = boolean.split("|");

    cat.setIsQuest(boolList[0].toInt());
    cat.setReadyQuest(boolList[1].toInt());

    QString mnc = inputFile.readLine();
    QStringList mncList = mnc.split("|");

    cat.setMission(mncList[0].toInt());
    cat.setCounterQuest(mncList[1].toInt());


    pbHP->setMaximum(cat.getMaxHealth());
    pbHP->setValue(cat.getMaxHealth());
    pbMP->setMaximum(cat.getMaxMana());
    pbHP->setValue(cat.getMaxMana());

    countArt = cat.getCounterQuest();
    counter->setText(QString::number(countArt));
    inputFile.close();
}

void Game::recaivedSouth()
{
    if (!wBoard->isHidden()){
        bl->updatePostion(1, 0);
    }
    if (!wBoardLab->isHidden()){
        blb->updatePostion(1, 0);
    }
}

void Game::recaivedNorth()
{
    if (!wBoard->isHidden()){
        bl->updatePostion(-1, 0);
    }
    if (!wBoardLab->isHidden()){
        blb->updatePostion(-1, 0);
    }
}

void Game::recaivedEast()
{
    if (!wBoard->isHidden()){
        bl->updatePostion(0, 1);
    }
    if (!wBoardLab->isHidden()){
        blb->updatePostion(0, 1);
    }
}

void Game::recaivedWest()
{
    if (!wBoard->isHidden()){
        bl->updatePostion(0, -1);
    }
    if (!wBoardLab->isHidden()){
        blb->updatePostion(0, -1);
    }
}

Hero Game::getCat() const
{
    return cat;
}

void Game::setCat(const Hero &newCat)
{
    cat = newCat;
    pbHP->setMaximum(cat.getMaxHealth());
    pbHP->setValue(cat.getHealth());

    pbMP->setMaximum(cat.getMaxMana());
    pbMP->setValue(cat.getMana());
    lblAgl->setText(QString::number(cat.getAgility()));
    lblPer->setText(QString::number(cat.getPerception()));
    lblVit->setText(QString::number(cat.getVitality()));
    lblStr->setText(QString::number(cat.getStrength()));
    lblInt->setText(QString::number(cat.getIntelligence()));
    lblWis->setText(QString::number(cat.getWisdom()));

    countArt = cat.getCounterQuest();
    counter->setText(QString::number(countArt));
}

void Game::setVolume(float volume)
{
    chlb->setVolume(volume);
    invb->setVolume(volume);
    lgb->setVolume(volume);
    egb->setVolume(volume);
    bl->setVolume(volume);
    blb->setVolume(volume);
    dfefl->setVolume(volume);

}

bool Game::getBossF() const
{
    return bossF;
}

void Game::setBossF(bool newBossF)
{
    bossF = newBossF;
}

void Game::setLabAct(bool newLabAct)
{
    labAct = newLabAct;
}
