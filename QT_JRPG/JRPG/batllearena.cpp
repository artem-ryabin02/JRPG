#include "batllearena.h"
#include "qboxlayout.h"

#include <DBcontroller.h>
#include <QFontDatabase>


BatlleArena::BatlleArena(QWidget *parent)
    : QWidget{parent}, hero("H", 1,1,1,1,1,1), enemy("E", 1,1,1,1,1,1, "skill", "qwerty")
{
    int id = QFontDatabase::addApplicationFont(":/assets/PressStart2P-Regular.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont textFont(family, 36);
    sb = new QStatusBar(parent);
    sb->setStyleSheet("color: white");

    sb->setGeometry(410, 100, 1100, 40);
    sb->setFont(textFont);


    HeroWid = new QWidget(parent);
    HeroWid->setGeometry(362, 203, 400, 471);
    HeroWid->setLayout(new QVBoxLayout());
    HeroHPPB = new QProgressBar();
    HeroHPPB->setStyleSheet("QProgressBar::chunk {background:QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #FF0350,stop: 0.4999 #FF0020,stop: 0.5 #FF0019,stop: 1 #FF0000 );border-radius: 5px;border: .px solid black;}QProgressBar{border-radius: 5px;background:grey}");
    HeroHPPB->setFixedSize(400, 30);
    HeroHPPB->setTextVisible(false);
    HeroHPPB->setMaximum(100);
    HeroHPPB->setValue(100);
    HeroWid->layout()->addWidget(HeroHPPB);
    HeroMPPB = new QProgressBar();
    HeroMPPB->setStyleSheet("QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #78d,stop: 0.4999 #46a,stop: 0.5 #45a,stop: 1 #238 );border-radius: 5px;border: px solid black;}QProgressBar{border-radius: 5px;background:grey}");
    HeroMPPB->setFixedSize(400, 30);
    HeroMPPB->setTextVisible(false);
    HeroMPPB->setMaximum(100);
    HeroMPPB->setValue(100);
    HeroWid->layout()->addWidget(HeroMPPB);

    HeroImage = new QLabel();
    QPixmap h(":/assets/characters/hero.png");
    HeroImage->setPixmap(h);
    HeroImage->setFixedSize(400, 400);
    HeroImage->setScaledContents(true);
    HeroWid->layout()->addWidget(HeroImage);

    EnemyWid = new QWidget(parent);
    EnemyWid->setGeometry(1133, 203, 400, 471);
    EnemyWid->setLayout(new QVBoxLayout());
    EnemyHPPB = new QProgressBar();
    EnemyHPPB->setStyleSheet("QProgressBar::chunk {background:QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #FF0350,stop: 0.4999 #FF0020,stop: 0.5 #FF0019,stop: 1 #FF0000 );border-radius: 5px;border: .px solid black;}QProgressBar{border-radius: 5px;background:grey}");
    EnemyHPPB->setFixedSize(400, 30);
    EnemyHPPB->setTextVisible(false);
    EnemyHPPB->setMaximum(100);
    EnemyHPPB->setValue(100);
    EnemyWid->layout()->addWidget(EnemyHPPB);
    EnemyMPPB = new QProgressBar();
    EnemyMPPB->setStyleSheet("QProgressBar::chunk {background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0,stop: 0 #78d,stop: 0.4999 #46a,stop: 0.5 #45a,stop: 1 #238 );border-radius: 5px;border: px solid black;}QProgressBar{border-radius: 5px;background:grey}");
    EnemyMPPB->setFixedSize(400, 30);
    EnemyMPPB->setTextVisible(false);
    EnemyMPPB->setMaximum(100);
    EnemyMPPB->setValue(100);
    EnemyWid->layout()->addWidget(EnemyMPPB);

    EnemyImage = new QLabel();
    QPixmap e (":/assets/characters/nps_demot.png");
    EnemyImage->setPixmap(e);
    EnemyImage->setFixedSize(400, 400);
    EnemyImage->setScaledContents(true);
    EnemyWid->layout()->addWidget(EnemyImage);


    panelButtons = new QWidget(parent);
    panelButtons->setGeometry(0, 720,1920, 360);
    panelButtons->setStyleSheet("background:grey");
    panelButtons->setLayout( new QHBoxLayout());
    QWidget* actNDef = new QWidget();
    actNDef->setFixedWidth(394);
    actNDef->setLayout(new QVBoxLayout());
    QWidget* itemNSkill = new QWidget();
    itemNSkill->setLayout(new QVBoxLayout());
    itemNSkill->setFixedWidth(394);
    buttonAtc = new ImageButton(":/assets/battleArena/attackButton.png");
    buttonAtc->setCursor(Qt::CursorShape::PointingHandCursor);
    buttonDef = new ImageButton(":/assets/battleArena/defenceButton.png");
    buttonDef->setCursor(Qt::CursorShape::PointingHandCursor);
    actNDef->layout()->addWidget(buttonAtc);
    actNDef->layout()->addWidget(buttonDef);
    buttonItem = new ImageButton(":/assets/battleArena/itemButton.png");
    buttonItem->setCursor(Qt::CursorShape::PointingHandCursor);
    buttonSkill = new ImageButton(":/assets/battleArena/skillButton.png");
    buttonSkill->setCursor(Qt::CursorShape::PointingHandCursor);
    itemNSkill->layout()->addWidget(buttonItem);
    itemNSkill->layout()->addWidget(buttonSkill);
    buttonEcp = new ImageButton(":/assets/battleArena/escapeButton.png");
    buttonEcp->setCursor(Qt::CursorShape::PointingHandCursor);
    buttonEcp->setFixedWidth(394);
    panelButtons->layout()->addWidget(actNDef);
    panelButtons->layout()->addWidget(itemNSkill);
    panelButtons->layout()->addWidget(buttonEcp);

    playerAtc = new QMediaPlayer();
    playerDef = new QMediaPlayer();
    playerSkill = new QMediaPlayer();
    aoA = new QAudioOutput();
    aoA->setVolume(50);
    aoD = new QAudioOutput();
    aoD->setVolume(50);
    aoS = new QAudioOutput();
    aoS->setVolume(50);
    playerAtc->setSource(QUrl::fromLocalFile(QDir::currentPath()+ "/music/attack_sound.wav"));
    playerDef->setSource(QUrl::fromLocalFile(QDir::currentPath()+ "/music/defence_sound.wav"));
    playerSkill->setSource(QUrl::fromLocalFile(QDir::currentPath()+ "/music/skill_sound.wav"));
    playerAtc->setAudioOutput(aoA);
    playerDef->setAudioOutput(aoD);
    playerSkill->setAudioOutput(aoS);


    connect(buttonAtc, &ImageButton::clicked, this, &BatlleArena::onButtonClickAttack);

    connect(buttonDef, &ImageButton::clicked, this, &BatlleArena::onButtonClickDefense);

    connect(buttonItem, &ImageButton::clicked, this, &BatlleArena::onButtonClickItem);

    connect(buttonSkill, &ImageButton::clicked, this, &BatlleArena::onButtonClickSkill);

    connect(buttonEcp, &ImageButton::clicked, this, &BatlleArena::onButtonClickEscape);
}

BatlleArena::~BatlleArena()
{
    qDebug() << "des BattlArena";
    delete HeroWid;
    delete EnemyWid;
    delete panelButtons;
    delete sb;

}

void BatlleArena::startBattle(const Hero _hero)
{
    hero = _hero;
    hero.displayStatus();
    qDebug() << "--------------------------------------\n";

    enemy = DBcontroller::randEnemy();
    enemy.displayStatus();
    HeroHPPB->setMaximum(hero.getMaxHealth());
    HeroHPPB->setValue(hero.getHealth());
    EnemyHPPB->setMaximum(enemy.getMaxHealth());
    EnemyHPPB->setValue(enemy.getHealth());

    HeroMPPB->setMaximum(hero.getMaxMana());
    HeroMPPB->setValue(hero.getMana());
    EnemyMPPB->setMaximum(enemy.getMaxMana());
    EnemyMPPB->setValue(enemy.getMana());

    bool motionFlag = QRandomGenerator::global()->bounded(1);

    if (motionFlag){
        sb->showMessage("Ход " + enemy.getName());
        enemyMotion();
    }
    else sb->showMessage("Ход " + hero.getName());
}

void BatlleArena::setHidden(bool hidden)
{
    HeroWid->setHidden(hidden);
    EnemyWid->setHidden(hidden);
    panelButtons->setHidden(hidden);
    sb->setHidden(hidden);
}

void BatlleArena::onButtonClickAttack()
{
    playerAtc->play();
    sb->showMessage(hero.getName() + " атакует");
    enemy.receivedDamage(hero.causedDamage(enemy.getProtection(), enemy.getDodge()));
    EnemyHPPB->setValue(enemy.getHealth());
    checkWin();
    enemyMotion();
}

void BatlleArena::onButtonClickDefense()
{
    playerDef->play();
    sb->showMessage(hero.getName() + " защищается");
    hero.Defence();
    enemyMotion();
}

void BatlleArena::onButtonClickItem()
{
    sb->showMessage("coming soon", 4000);
}

void BatlleArena::onButtonClickSkill()
{
    playerSkill->play();
    sb->showMessage("coming soon", 4000);
}

void BatlleArena::onButtonClickEscape()
{
    int cube = QRandomGenerator::global()->bounded(100);
    if (cube <= hero.getDodge()){
        emit escape();
    }
    else {
        sb->showMessage("Побег не удался");
        enemyMotion();
    }
}

Hero BatlleArena::getHero() const
{
    return hero;
}

void BatlleArena::enemyMotion()
{
    qDebug() << "enemy motion \n";
    enemy.removeDefence();
    int action = enemy.randAction();
    if (action == 1) {
        playerAtc->play();
        sb->showMessage(enemy.getName() + " атакует");
        hero.receivedDamage(enemy.causedDamage(hero.getProtection(), hero.getDodge()));
        HeroHPPB->setValue(hero.getHealth());
    }
    if (action == 2) {
        playerDef->play();
        sb->showMessage(enemy.getName() + " защищается");
        enemy.Defence();
    }
    if (action == 3) {
        playerSkill->play();
        if (enemy.wastingMana(1)){
            EnemyMPPB->setValue(enemy.getMana());
            sb->showMessage(enemy.getName() + " лечится");
            enemy.Heal(5);
        }else{
            sb->showMessage(enemy.getName() + " не смог(ла) вылечится, из-за не хватки маны");
        }
    }
    checkWin();
    hero.removeDefence();
}

void BatlleArena::checkWin()
{
    if (!enemy.getAlive()){
        sb->showMessage(hero.getName() + " winner");
        _sleep(1000);
        emit win();
    }
    else if (!hero.getAlive()){
        sb->showMessage(enemy.getName() + " winner");
        _sleep(1000);
        emit loose();
    }
}
