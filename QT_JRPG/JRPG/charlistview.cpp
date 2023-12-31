#include "charlistview.h"

CharListView::CharListView(QWidget *parent)
    : QWidget{parent}, cat("Cater", 5,5,5,5,5,5)
{
    QFont textFont("Stencil", 36);

    wArtEquips = new QWidget(parent);
    wArtEquips->setLayout(new QHBoxLayout);
    wArtEquips->setGeometry(75, 165, 600, 750);
    art = new QLabel();
    art->setFixedSize(365, 575);
    art->setStyleSheet("background:grey");
    wEquips = new QWidget();
    wEquips->setLayout(new QVBoxLayout);
    weaponArt = new QLabel();
    weaponArt->setFixedSize(90, 90);
    weaponArt->setStyleSheet("background:white");
    QPixmap sw(":/assets/buttonAndText/charList/weapon.png");
    sw.scaled(90, 90);
    weaponArt->setPixmap(sw);
    armorArt = new QLabel();
    armorArt->setFixedSize(90, 90);
    armorArt->setStyleSheet("background:white");
    QPixmap hlt(":/assets/buttonAndText/charList/equipment.png");
    hlt.scaled(90, 90);
    armorArt->setPixmap(hlt);
    wEquips->layout()->addWidget(armorArt);
    wEquips->layout()->addWidget(weaponArt);
    wArtEquips->layout()->addWidget(art);
    wArtEquips->layout()->addWidget(wEquips);

    wParametrs = new QWidget(parent);
    wParametrs->setStyleSheet("background:grey");
    wParametrs->setGeometry(765, 165 , 1050, 750);
    wParametrs->setLayout(new QVBoxLayout);
    lblParametrs = new QLabel();
    lblParametrs->setFixedSize(1000, 150);
    QPixmap pt(":/assets/buttonAndText/Game/parametrs_table.png");
    lblParametrs->setPixmap(pt);
    wParametrs->layout()->addWidget(lblParametrs);

    lblStr = new QLabel(parent);
    lblStr->setGeometry(933, 254, 54, 51);
    lblStr->setStyleSheet("background:grey");
    lblStr->setAlignment(Qt::AlignCenter);
    lblStr->setFont(textFont);
    lblStr->setText(QString::number(cat.getStrength()));
    lblVit = new QLabel(parent);
    lblVit->setGeometry(933, 195, 54, 51);
    lblVit->setStyleSheet("background:grey");
    lblVit->setAlignment(Qt::AlignCenter);
    lblVit->setFont(textFont);
    lblVit->setText(QString::number(cat.getVitality()));
    lblAgl = new QLabel(parent);
    lblAgl->setGeometry(1184, 195, 54, 51);
    lblAgl->setStyleSheet("background:grey");
    lblAgl->setAlignment(Qt::AlignCenter);
    lblAgl->setFont(textFont);
    lblAgl->setText(QString::number(cat.getAgility()));
    lblPer = new QLabel(parent);
    lblPer->setGeometry(1185, 254, 54, 51);
    lblPer->setStyleSheet("background:grey");
    lblPer->setAlignment(Qt::AlignCenter);
    lblPer->setFont(textFont);
    lblPer->setText(QString::number(cat.getPerception()));
    lblInt = new QLabel(parent);
    lblInt->setGeometry(1437, 195, 54, 51);
    lblInt->setStyleSheet("background:grey");
    lblInt->setAlignment(Qt::AlignCenter);
    lblInt->setFont(textFont);
    lblInt->setText(QString::number(cat.getIntelligence()));
    lblWis = new QLabel(parent);
    lblWis->setGeometry(1437, 254, 54, 51);
    lblWis->setStyleSheet("background:grey");
    lblWis->setAlignment(Qt::AlignCenter);
    lblWis->setFont(textFont);
    lblWis->setText(QString::number(cat.getWisdom()));

    wHP = new QWidget();
    wHP->setLayout(new QHBoxLayout);
    lHP = new QLabel();
    lHP->setPixmap(QPixmap(":/assets/buttonAndText/charList/HP.png"));
    lblhp = new QLabel();
    lblhp->setFont(textFont);
    lblhp->setText(QString::number(cat.getHealth()) + "/" + QString::number(cat.getMaxHealth()));
    wHP->layout()->addWidget(lHP);
    wHP->layout()->addWidget(lblhp);


    wMP = new QWidget();
    wMP->setLayout(new QHBoxLayout);
    lMP = new QLabel();
    lMP->setPixmap(QPixmap(":/assets/buttonAndText/charList/MP.png"));
    lblMp = new QLabel();
    lblMp->setFont(textFont);
    lblMp->setText(QString::number(cat.getMana()) + "/" + QString::number(cat.getMaxMana()));
    wMP->layout()->addWidget(lMP);
    wMP->layout()->addWidget(lblMp);

    wCC = new QWidget();
    wCC->setLayout(new QHBoxLayout);
    lcc = new QLabel();
    lcc->setPixmap(QPixmap(":/assets/buttonAndText/charList/critChance.png"));
    lblcc = new QLabel();
    lblcc->setText(QString::number(cat.getCritChance())+"%");
    lblcc->setFont(textFont);
    wCC->layout()->addWidget(lcc);
    wCC->layout()->addWidget(lblcc);

    wLC = new QWidget();
    wLC->setLayout(new QHBoxLayout);
    llc = new QLabel();
    llc->setPixmap(QPixmap(":/assets/buttonAndText/charList/loadcapacity.png"));
    lbllc = new QLabel();
    lbllc->setText(QString::number(100));
    lbllc->setFont(textFont);
    wLC->layout()->addWidget(llc);
    wLC->layout()->addWidget(lbllc);

    firstCol = new QWidget();
    firstCol->setLayout(new QVBoxLayout);
    firstCol->layout()->addWidget(wHP);
    firstCol->layout()->addWidget(wMP);
    firstCol->layout()->addWidget(wCC);

    wATC = new QWidget();
    wATC->setLayout(new QHBoxLayout);
    lATC = new QLabel();
    lATC->setPixmap(QPixmap(":/assets/buttonAndText/charList/attack.png"));
    lblATC = new QLabel();
    lblATC->setFont(textFont);
    lblATC->setText(QString::number(cat.getAttack()));
    wATC->layout()->addWidget(lATC);
    wATC->layout()->addWidget(lblATC);

    wDEF = new QWidget();
    wDEF->setLayout(new QHBoxLayout);
    lDEF = new QLabel();
    lDEF->setPixmap(QPixmap(":/assets/buttonAndText/charList/defence.png"));
    lblDEF = new QLabel();
    lblDEF->setFont(textFont);
    lblDEF->setText(QString::number(cat.getProtection()));
    wDEF->layout()->addWidget(lDEF);
    wDEF->layout()->addWidget(lblDEF);

    wDOD = new QWidget();
    wDOD->setLayout(new QHBoxLayout);
    llDOD = new QLabel();
    llDOD->setPixmap(QPixmap(":/assets/buttonAndText/charList/dodge.png"));
    lblDOD = new QLabel();
    lblDOD->setFont(textFont);
    lblDOD->setText(QString::number(cat.getDodge())+"%");
    wDOD->layout()->addWidget(llDOD);
    wDOD->layout()->addWidget(lblDOD);

    secondCol = new QWidget();
    secondCol->setLayout(new QVBoxLayout);
    secondCol->layout()->addWidget(wATC);
    secondCol->layout()->addWidget(wDEF);
    secondCol->layout()->addWidget(wDOD);

    wHorizon = new QWidget(parent);
    wHorizon->setLayout(new QHBoxLayout);
    wHorizon->layout()->addWidget(firstCol);
    wHorizon->layout()->addWidget(secondCol);
    wParametrs->layout()->addWidget(wHorizon);
    wParametrs->layout()->addWidget(wLC);

    skills = new ImageButton(":/assets/buttonAndText/charList/skills.png");
    skills->setCursor(Qt::CursorShape::PointingHandCursor);
    wParametrs->layout()->addWidget(skills);
    wParametrs->layout()->setAlignment(skills, Qt::AlignHCenter);
    back = new ImageButton(":/assets/buttonAndText/back.png");
    back->setCursor(Qt::CursorShape::PointingHandCursor);
    wParametrs->layout()->addWidget(back);
    wParametrs->layout()->setAlignment(back, Qt::AlignHCenter);

    MB = new MagicBook(parent);
    MB->setHidden(true);
    MB->setHiddenButtons(true);


    connect(MB, &MagicBook::backSignal, this, &CharListView::skillBack);

    connect(skills, &ImageButton::clicked, this, &CharListView::skillView);
    connect(back, &ImageButton::clicked, this, &CharListView::goBack);
}

CharListView::~CharListView()
{
    delete wArtEquips;
    delete wParametrs;
    delete lblStr;
    delete lblVit;
    delete lblAgl;
    delete lblPer;
    delete lblInt;
    delete lblWis;

}

void CharListView::setHidden(bool hidden)
{
    wArtEquips->setHidden(hidden);
    wParametrs->setHidden(hidden);
    lblStr->setHidden(hidden);
    lblVit->setHidden(hidden);
    lblAgl->setHidden(hidden);
    lblPer->setHidden(hidden);
    lblInt->setHidden(hidden);
    lblWis->setHidden(hidden);
}

void CharListView::setCat(const Hero &newCat)
{
    cat = newCat;
    lblStr->setText(QString::number(cat.getStrength()));
    lblVit->setText(QString::number(cat.getVitality()));
    lblPer->setText(QString::number(cat.getPerception()));
    lblAgl->setText(QString::number(cat.getAgility()));
    lblInt->setText(QString::number(cat.getIntelligence()));
    lblWis->setText(QString::number(cat.getWisdom()));

    lblhp->setText(QString::number(cat.getHealth()) + "/" + QString::number(cat.getMaxHealth()));
    lblMp->setText(QString::number(cat.getMana()) + "/" + QString::number(cat.getMaxMana()));
    lblcc->setText(QString::number(cat.getCritChance())+"%");
    lbllc->setText(QString::number(100));
    lblATC->setText(QString::number(cat.getAttack()));
    lblDEF->setText(QString::number(cat.getProtection()));


    lblDOD->setText(QString::number(cat.getDodge())+"%");
    MB->setCat(cat);
}

void CharListView::setVolume(float volume)
{
    back->setVolume(volume);
    skills->setVolume(volume);
}

void CharListView::skillView()
{
    this->setHidden(true);
    MB->setHidden(false);
}

void CharListView::skillBack()
{
    this->setHidden(false);
    MB->setHidden(true);
}


