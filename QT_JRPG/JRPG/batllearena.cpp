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

    sb->setGeometry(5, 100, 1915, 40);
    sb->setFont(textFont);


    HeroWid = new QWidget(parent);
    HeroWid->setGeometry(362, 203, 400, 471);
    HeroWid->setLayout(new QVBoxLayout());
    HeroHPPB = new QProgressBar();
    HeroHPPB->setStyleSheet("QProgressBar::chunk {background: rgb(168, 41, 40);border-radius: 5px;border: .px solid black;}QProgressBar{border-radius: 5px;background:grey}");
    HeroHPPB->setFixedSize(400, 30);
    HeroHPPB->setTextVisible(false);
    HeroHPPB->setMaximum(100);
    HeroHPPB->setValue(100);
    HeroWid->layout()->addWidget(HeroHPPB);
    HeroMPPB = new QProgressBar();
    HeroMPPB->setStyleSheet("QProgressBar::chunk {background:rgb(38, 72, 109);border-radius: 5px;border: px solid black;}QProgressBar{border-radius: 5px;background:grey}");
    HeroMPPB->setFixedSize(400, 30);
    HeroMPPB->setTextVisible(false);
    HeroMPPB->setMaximum(100);
    HeroMPPB->setValue(100);
    HeroWid->layout()->addWidget(HeroMPPB);

    HeroImage = new QLabel();
    QPixmap h(":/assets/characters/boy_gg.png");

    HeroImage->setPixmap(h);
    HeroImage->setScaledContents(true);
    HeroImage->setFixedSize(400, 400);
    HeroImage->setAlignment(Qt::AlignCenter);
    HeroWid->layout()->addWidget(HeroImage);

    EnemyWid = new QWidget(parent);
    EnemyWid->setGeometry(1133, 203, 400, 471);
    EnemyWid->setLayout(new QVBoxLayout());
    EnemyHPPB = new QProgressBar();
    EnemyHPPB->setStyleSheet("QProgressBar::chunk {background: rgb(168, 41, 40);border-radius: 5px;border: .px solid black;}QProgressBar{border-radius: 5px;background:grey}");
    EnemyHPPB->setFixedSize(400, 30);
    EnemyHPPB->setTextVisible(false);
    EnemyHPPB->setMaximum(100);
    EnemyHPPB->setValue(100);
    EnemyWid->layout()->addWidget(EnemyHPPB);
    EnemyMPPB = new QProgressBar();
    EnemyMPPB->setStyleSheet("QProgressBar::chunk {background: rgb(38, 72, 109);border-radius: 5px;border: px solid black;}QProgressBar{border-radius: 5px;background:grey}");
    EnemyMPPB->setFixedSize(400, 30);
    EnemyMPPB->setTextVisible(false);
    EnemyMPPB->setMaximum(100);
    EnemyMPPB->setValue(100);
    EnemyWid->layout()->addWidget(EnemyMPPB);

    EnemyImage = new QLabel();
    //QPixmap e (":/assets/characters/enemy/skeleton.png");
    //EnemyImage->setPixmap(e);
    EnemyImage->setFixedSize(400, 400);
    EnemyImage->setAlignment(Qt::AlignCenter);
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

    mb = new MagicBook(parent);
    mb->setHidden(true);

    connect(mb, &MagicBook::backSignal, this, &BatlleArena::backFromMagicBook);

    connect(mb, &MagicBook::used, this, &BatlleArena::heroUsedSkill);

    connect(buttonAtc, &ImageButton::clicked, this, &BatlleArena::onButtonClickAttack);

    connect(buttonDef, &ImageButton::clicked, this, &BatlleArena::onButtonClickDefense);

    connect(buttonItem, &ImageButton::clicked, this, &BatlleArena::onButtonClickItem);

    connect(buttonSkill, &ImageButton::clicked, this, &BatlleArena::onButtonClickSkill);

    connect(buttonEcp, &ImageButton::clicked, this, &BatlleArena::onButtonClickEscape);
}

BatlleArena::~BatlleArena()
{
    delete HeroWid;
    delete EnemyWid;
    delete panelButtons;
    delete sb;

}

void BatlleArena::startBattle(const Hero _hero, bool BF)
{
    hero = _hero;
    hero.displayStatus();
    qDebug() << "--------------------------------------\n";

    enemy = DBcontroller::randEnemy();
    EnemyImage->setPixmap(QPixmap(enemy.getPathName()));
    qDebug() << enemy.getPathName();
    if (BF){
        enemy.setMaxHealth(enemy.getMaxHealth()*10);
        enemy.setHealth(enemy.getMaxHealth());
        enemy.setMaxMana(enemy.getMaxMana()*10);
        enemy.setMana(enemy.getMaxMana());
    }

    setHPMPall();

    sb->showMessage("Ход " + hero.getName());
}

void BatlleArena::setHidden(bool hidden)
{
    HeroWid->setHidden(hidden);
    EnemyWid->setHidden(hidden);
    panelButtons->setHidden(hidden);
    sb->setHidden(hidden);
}

void BatlleArena::setVolume(float volume)
{
    buttonAtc->setVolume(volume);
    buttonDef->setVolume(volume);
    buttonItem->setVolume(volume);
    buttonSkill->setVolume(volume);
    buttonEcp->setVolume(volume);
    aoA->setVolume(volume);
    aoD->setVolume(volume);
    aoS->setVolume(volume);

}

void BatlleArena::onButtonClickAttack()
{
    playerAtc->play();
    int damage = hero.causedDamage(enemy.getProtection(), enemy.getDodge());
    if (isDamage(damage)){
        sb->showMessage(hero.getName() + " промахивается");
    } else if (isCritDamage(damage, enemy.getMaxHealth())){
        sb->showMessage(hero.getName() + " наносит критический урон");
    }
    else sb->showMessage(hero.getName() + " атакует");
    enemy.receivedDamage(damage);
    EnemyHPPB->setValue(enemy.getHealth());
    checkWin();
    enemyMotion();
}

void BatlleArena::onButtonClickDefense()
{
    playerDef->play();
    sb->showMessage(hero.getName() + " защищается");
    hero.defence();
    enemyMotion();
}

void BatlleArena::onButtonClickItem()
{
    sb->showMessage("coming soon", 4000);
}

void BatlleArena::onButtonClickSkill()
{
    mb->setHidden(false);
    mb->setCat(hero);
    mb->setRat(enemy);
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

void BatlleArena::backFromMagicBook()
{
    mb->setHidden(true);
}

void BatlleArena::heroUsedSkill()
{
    playerSkill->play();
    hero = mb->getCat();
    enemy = mb->getRat();
    backFromMagicBook();
    setHPMPall();
    enemyMotion();
}

void BatlleArena::enemyMotion()
{
    enemy.removeDefence();
    int action = enemy.randAction();
    if (action == 1) {
        playerAtc->play();      
        int damage = enemy.causedDamage(hero.getProtection(), hero.getDodge());
        if (isDamage(damage)){
            sb->showMessage(enemy.getName() + " промахивается");
        } else if (isCritDamage(damage, hero.getMaxHealth())){
            sb->showMessage(enemy.getName() + " наносит критический урон");
        }
        else sb->showMessage(enemy.getName() + " атакует");
        hero.receivedDamage(damage);
        HeroHPPB->setValue(hero.getHealth());
    }
    if (action == 2) {
        playerDef->play();
        sb->showMessage(enemy.getName() + " защищается");
        enemy.defence();
    }
    if (action == 3) {
        playerSkill->play();
        Skill sk(DBcontroller::randEnemySkill(enemy.getEnemy_skill_id()));
        qDebug() << sk.getName();
        if (enemy.wastingMana(sk.getCost())){
            EnemyMPPB->setValue(enemy.getMana());
            sk.useSkill(enemy, hero);
            sb->showMessage(enemy.getName() + " применяет навык ");
        }else{
            sb->showMessage(enemy.getName() + " не смог(ла) применть навык, из-за не хватки маны");
        }
    }
    checkWin();
    hero.removeDefence();
}

void BatlleArena::checkWin()
{
    if (!enemy.getAlive()){
        sb->showMessage(hero.getName() + " winner");
        emit win();
    }
    else if (!hero.getAlive()){
        sb->showMessage(enemy.getName() + " winner");
        emit loose();
    }
}

bool BatlleArena::isDamage(int damage)
{
    if (damage == 0){
        return true;
    }
    else return false;
}

bool BatlleArena::isCritDamage(int damage, int maxHP)
{
    if (damage >= maxHP/2){
        return true;
    }
    else return false;
}

void BatlleArena::setHPMPall()
{
    HeroHPPB->setMaximum(hero.getMaxHealth());
    HeroHPPB->setValue(hero.getHealth());
    EnemyHPPB->setMaximum(enemy.getMaxHealth());
    EnemyHPPB->setValue(enemy.getHealth());

    HeroMPPB->setMaximum(hero.getMaxMana());
    HeroMPPB->setValue(hero.getMana());
    EnemyMPPB->setMaximum(enemy.getMaxMana());
    EnemyMPPB->setValue(enemy.getMana());
}
