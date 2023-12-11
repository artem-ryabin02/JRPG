#include "game.h"

Game::Game(QWidget *parent)
    : QWidget{parent}
{
 //   Hero cat("Cater", 5, 5, 5, 5, 5, 5);
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
    blb = new BoardLabyrinth(wBoardLab);
    blb->rescale(wBoard->height());


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
    QFont textFont("Stencil", 36);
    lblStr = new QLabel(parent);
    lblStr->setGeometry(1319, 600, 54, 51);
    lblStr->setStyleSheet("background:grey");
    lblStr->setAlignment(Qt::AlignCenter);
    lblStr->setFont(textFont);
    lblStr->setText(QString::number(/*cat.getStrength()*/5));
    lblVit = new QLabel(parent);
    lblVit->setGeometry(1319, 659, 54, 51);
    lblVit->setStyleSheet("background:grey");
    lblVit->setAlignment(Qt::AlignCenter);
    lblVit->setFont(textFont);
    lblVit->setText(QString::number(/*cat.getVitality()*/5));
    lblAgl = new QLabel(parent);
    lblAgl->setGeometry(1570, 600, 54, 51);
    lblAgl->setStyleSheet("background:grey");
    lblAgl->setAlignment(Qt::AlignCenter);
    lblAgl->setFont(textFont);
    lblAgl->setText(QString::number(/*cat.getAgility()*/5));
    lblPer = new QLabel(parent);
    lblPer->setGeometry(1570, 659, 54, 51);
    lblPer->setStyleSheet("background:grey");
    lblPer->setAlignment(Qt::AlignCenter);
    lblPer->setFont(textFont);
    lblPer->setText(QString::number(/*cat.getPerception()*/5));
    lblInt = new QLabel(parent);
    lblInt->setGeometry(1823, 600, 54, 51);
    lblInt->setStyleSheet("background:grey");
    lblInt->setAlignment(Qt::AlignCenter);
    lblInt->setFont(textFont);
    lblInt->setText(QString::number(/*cat.getIntelligence()*/5));
    lblWis = new QLabel(parent);
    lblWis->setGeometry(1823, 659, 54, 51);
    lblWis->setStyleSheet("background:grey");
    lblWis->setAlignment(Qt::AlignCenter);
    lblWis->setFont(textFont);
    lblWis->setText(QString::number(/*cat.getWisdom()*/5));


    wHPMP = new QWidget(parent);
    wHPMP->setObjectName("HPMPWidget");
    wHPMP->setLayout(new QHBoxLayout);
    wHPMP->setGeometry(1160, 45, 720, 500);
    pbHP = new QProgressBar();
    pbMP = new QProgressBar();
    pbHP->setOrientation(Qt::Vertical);
    pbHP->setStyleSheet("QProgressBar::chunk {background:QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #FF0350,stop: 0.4999 #FF0020,stop: 0.5 #FF0019,stop: 1 #FF0000 );border-radius: 5px;border: .px solid black;}QProgressBar{border-radius: 5px;background:grey}");
    pbHP->setFixedSize(100, 450);
    pbHP->setTextVisible(false);
    pbHP->setMaximum(/*cat.getMaxHealth()*/100);
    pbHP->setValue(/*cat.getMaxHealth()*/100);
    pbMP->setOrientation(Qt::Vertical);
    pbMP->setStyleSheet("QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #78d,stop: 0.4999 #46a,stop: 0.5 #45a,stop: 1 #238 );border-radius: 5px;border: px solid black;}QProgressBar{border-radius: 5px;background:grey}");
    pbMP->setFixedSize(100, 450);
    pbMP->setTextVisible(false);
    pbMP->setMaximum(/*cat.getMaxMana()*/100);
    pbMP->setValue(/*cat.getMaxMana()*/100);
    lblHero = new QLabel();
    lblHero->setFixedSize(430, 500);
    QPixmap hero(":/assets/characters/hero.png");
    lblHero->setPixmap(hero);
    lblHero->setScaledContents(true);
    wHPMP->layout()->addWidget(pbHP);
    wHPMP->layout()->addWidget(lblHero);
    wHPMP->layout()->addWidget(pbMP);

    connect(chlb, &ImageButton::clicked, this, &Game::onPushCharListButtonClicked);
    connect(invb, &ImageButton::clicked, this, &Game::onPushInventoryButtonClicked);
    connect(lgb, &ImageButton::clicked, this, &Game::onPushLoadButtonClicked);
    connect(egb, &ImageButton::clicked, this, &Game::onPushExitButtonClicked);


   connect(bl, &BoardLocation::signalDialogWithNPC, this, &Game::receivedSignalDialogWithNPC);
   connect(bl, &BoardLocation::signalEntryLabyrinth, this, &Game::receivedSignalEntryLab);

   connect(blb, &BoardLabyrinth::enemy, this, &Game::transmitEnemyEntry);

}

Game::~Game()
{
    delete wBoard;
    delete wHPMP;
    delete wButtoms;
}

void Game::setHidden(bool hidden)
{
    if(wBoard->isHidden()){
        if (labAct){
            wBoardLab->setHidden(hidden);
            wBoard->setHidden(!hidden);
        }
        else{
            wBoardLab->setHidden(!hidden);
            wBoard->setHidden(hidden);
        }
    }
    else{
        wBoardLab->setHidden(hidden);
        wBoard->setHidden(hidden);
    }
    wHPMP->setHidden(hidden);
    wButtoms->setHidden(hidden);
    lblAgl->setHidden(hidden);
    lblPer->setHidden(hidden);
    lblStr->setHidden(hidden);
    lblVit->setHidden(hidden);
    lblInt->setHidden(hidden);
    lblWis->setHidden(hidden);
    lblParametrs->setHidden(hidden);
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

void Game::receivedSignalExitDialogWithNPC()
{

}

void Game::receivedSignalEntryLab()
{
    wBoard->setHidden(true);
    bl->setDisable(true);
    wBoardLab->setHidden(false);
    blb->setDisable(false);
    labAct = true;
}

void Game::receivedSignalExitLab()
{
    wBoard->setHidden(false);
    bl->setDisable(false);
    wBoardLab->setHidden(true);
    blb->setDisable(true);
    labAct = false;
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

void Game::setLabAct(bool newLabAct)
{
    labAct = newLabAct;
}
