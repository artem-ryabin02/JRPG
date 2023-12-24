#ifndef BATLLEARENA_H
#define BATLLEARENA_H

#include "enemy.h"
#include "hero.h"
#include "imagebutton.h"
#include "qlabel.h"
#include "qprogressbar.h"
#include "qstatusbar.h"
#include <QWidget>
#include <QtMultimedia/QMediaPlayer>
#include <QAudioOutput>

class BatlleArena : public QWidget
{
    Q_OBJECT
public:
    explicit BatlleArena(QWidget *parent = nullptr);
    ~BatlleArena();
    void startBattle(const Hero _hero);
    void setHidden(bool hidden);
    Hero getHero() const;

private slots:
    void onButtonClickAttack();
    void onButtonClickDefense();
    void onButtonClickItem();
    void onButtonClickSkill();
    void onButtonClickEscape();
private:
    QWidget* HeroWid;
    QWidget* EnemyWid;

    QWidget* statusBar;
    QStatusBar* sb;

    QProgressBar* HeroHPPB;
    QProgressBar* HeroMPPB;
    QProgressBar* EnemyHPPB;
    QProgressBar* EnemyMPPB;

    QLabel* HeroImage;
    QLabel* EnemyImage;

    QWidget* panelButtons;
    ImageButton* buttonAtc;
    ImageButton* buttonDef;
    ImageButton* buttonItem;
    ImageButton* buttonSkill;
    ImageButton* buttonEcp;

    QMediaPlayer* playerAtc;
    QMediaPlayer* playerDef;
    QMediaPlayer* playerSkill;

    QAudioOutput* aoA;
    QAudioOutput* aoD;
    QAudioOutput* aoS;

    Hero hero;
    Enemy enemy;

    void enemyMotion();
    void checkWin();
    bool isDamage(int damage);
    bool isCritDamage(int damage, int maxHP);
signals:
    void escape();
    void win();
    void loose();
};

#endif // BATLLEARENA_H
