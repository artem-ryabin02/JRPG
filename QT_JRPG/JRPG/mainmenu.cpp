#include "mainmenu.h"
#include "qboxlayout.h"



MainMenu::MainMenu(QWidget *parent)
    : QWidget{parent}
{

    wButtons = new QWidget(parent);
    wButtons->setObjectName("buttonWidget");
    wButtons->setLayout(new QVBoxLayout);
    wButtons->setGeometry(1488, 435, 375, 250);
    nbg = new ImageButton(":/assets/buttonAndText/mainMenu/new_game_button.png");
    nbg->setObjectName("newGameB");
    nbg->setCursor(Qt::CursorShape::PointingHandCursor);
    wButtons->layout()->addWidget(nbg);
    wButtons->layout()->setAlignment(nbg, Qt::AlignHCenter);
    lbg = new ImageButton(":/assets/buttonAndText/mainMenu/load_button.png");
    lbg->setObjectName("loadGameB");
    lbg->setCursor(Qt::CursorShape::PointingHandCursor);
    wButtons->layout()->addWidget(lbg);
    wButtons->layout()->setAlignment(lbg, Qt::AlignHCenter);
    ebg = new ImageButton(":/assets/buttonAndText/mainMenu/exit_button.png");
    ebg->setObjectName("exitGameB");
    ebg->setCursor(Qt::CursorShape::PointingHandCursor);
    wButtons->layout()->addWidget(ebg);
    wButtons->layout()->setAlignment(ebg, Qt::AlignHCenter);

    wTitle = new QWidget(parent);
    wTitle->setObjectName("titleWidget");
    wTitle->setLayout(new QVBoxLayout);
    wTitle->setGeometry(39, 428, 582, 156);
    QPixmap title(":/assets/buttonAndText/mainMenu/title.png");
    lt = new QLabel();
    lt->setPixmap(title);
    wTitle->layout()->addWidget(lt);


    connect(nbg, &ImageButton::clicked, this, &MainMenu::onButtonNewGameClicked);
    connect(lbg, &ImageButton::clicked, this, &MainMenu::onButtonLoadGameClicked);
    connect(ebg, &ImageButton::clicked, this, &MainMenu::onButtonExitClicked);
}

MainMenu::~MainMenu()
{
    delete wButtons;
    delete wTitle;
}

void MainMenu::setHidden(bool hidden)
{
    wButtons->setHidden(hidden);
    wTitle->setHidden(hidden);
}

void MainMenu::setVolume(float volume)
{
    ebg->setVolume(volume);
    lbg->setVolume(volume);
    nbg->setVolume(volume);
}

void MainMenu::onButtonExitClicked()
{
    emit exit();
}

void MainMenu::onButtonNewGameClicked()
{
    emit newGame();
}

void MainMenu::onButtonLoadGameClicked()
{
    emit loadGame();
}

