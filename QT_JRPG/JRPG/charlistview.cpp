#include "charlistview.h"

CharListView::CharListView(QWidget *parent)
    : QWidget{parent}
{
    QFont textFont("Stencil", 36);

    wArtEquips = new QWidget(parent);
    wArtEquips->setLayout(new QHBoxLayout);
    wArtEquips->setGeometry(75, 165, 600, 750);
    art = new QLabel();
    art->setFixedSize(365, 575);
    art->setStyleSheet("backgroud-color: grey");
    wEquips = new QWidget();
    wEquips->setLayout(new QVBoxLayout);
    weaponArt = new QLabel();
    weaponArt->setFixedSize(90, 90);
    weaponArt->setPixmap(QPixmap(":/assets/buttonAndText/charList/weapon.png"));
    armorArt = new QLabel();
    armorArt->setFixedSize(90, 90);
    armorArt->setPixmap(QPixmap(":/assets/buttonAndText/charList/equipment.png"));
    wEquips->layout()->addWidget(armorArt);
    wEquips->layout()->addWidget(weaponArt);
    wArtEquips->layout()->addWidget(art);
    wArtEquips->layout()->addWidget(wEquips);

    wParametrs = new QWidget(parent);
    wParametrs->setGeometry(765, 165 , 1050, 750);
    wParametrs->setLayout(new QVBoxLayout);
    lblParametrs = new QLabel();
    lblParametrs->setFixedSize(1000, 150);
    QPixmap pt(":/assets/buttonAndText/Game/parametrs_table.png");
    pt.scaled(1000, 150);
    lblParametrs->setPixmap(pt);
    wParametrs->layout()->addWidget(lblParametrs);

    lblStr = new QLabel(parent);
    lblStr->setGeometry(1010, 220, 75, 69);
    lblStr->setStyleSheet("background:grey");
    lblStr->setAlignment(Qt::AlignCenter);
    lblStr->setFont(textFont);
    lblStr->setText(QString::number(5));
    lblVit = new QLabel(parent);
    lblVit->setGeometry(1010, 300, 54, 51);
    lblVit->setStyleSheet("background:grey");
    lblVit->setAlignment(Qt::AlignCenter);
    lblVit->setFont(textFont);
    lblVit->setText(QString::number(5));
    lblAgl = new QLabel(parent);
    lblAgl->setGeometry(1360, 220, 54, 51);
    lblAgl->setStyleSheet("background:grey");
    lblAgl->setAlignment(Qt::AlignCenter);
    lblAgl->setFont(textFont);
    lblAgl->setText(QString::number(5));
    lblPer = new QLabel(parent);
    lblPer->setGeometry(1360, 300, 54, 51);
    lblPer->setStyleSheet("background:grey");
    lblPer->setAlignment(Qt::AlignCenter);
    lblPer->setFont(textFont);
    lblPer->setText(QString::number(5));
    lblInt = new QLabel(parent);
    lblInt->setGeometry(1715, 220, 54, 51);
    lblInt->setStyleSheet("background:grey");
    lblInt->setAlignment(Qt::AlignCenter);
    lblInt->setFont(textFont);
    lblInt->setText(QString::number(5));
    lblWis = new QLabel(parent);
    lblWis->setGeometry(1715, 300, 54, 51);
    lblWis->setStyleSheet("background:grey");
    lblWis->setAlignment(Qt::AlignCenter);
    lblWis->setFont(textFont);
    lblWis->setText(QString::number(5));

    QWidget* wHP = new QWidget();
    wHP->setLayout(new QHBoxLayout);
    QLabel* lHP = new QLabel();
    lHP->setPixmap(QPixmap(":/assets/buttonAndText/charList/HP.png"));
    QLabel* lblhp = new QLabel();
    lblhp->setText("10/10");
    wHP->layout()->addWidget(lHP);
    wHP->layout()->addWidget(lblhp);


    QWidget* wMP = new QWidget();
    wMP->setLayout(new QHBoxLayout);
    QLabel* lMP = new QLabel();
    lMP->setPixmap(QPixmap(":/assets/buttonAndText/charList/MP.png"));
    QLabel* lblMp = new QLabel();
    lblMp->setText("10/10");
    wMP->layout()->addWidget(lMP);
    wMP->layout()->addWidget(lblMp);

    QWidget* wCC = new QWidget();
    wCC->setLayout(new QHBoxLayout);
    QLabel* lcc = new QLabel();
    lcc->setPixmap(QPixmap(":/assets/buttonAndText/charList/HP.png"));
    QLabel* lblcc = new QLabel();
    lblcc->setText("10%");
    wCC->layout()->addWidget(lcc);
    wCC->layout()->addWidget(lblcc);

    QWidget* wLC = new QWidget();
    wLC->setLayout(new QHBoxLayout);
    QLabel* llc = new QLabel();
    llc->setPixmap(QPixmap(":/assets/buttonAndText/charList/HP.png"));
    QLabel* lbllc = new QLabel();
    lbllc->setText("10%");
    wLC->layout()->addWidget(llc);
    wLC->layout()->addWidget(lbllc);

    firstCol = new QWidget();
    firstCol->setLayout(new QVBoxLayout);
    firstCol->layout()->addWidget(wHP);
    firstCol->layout()->addWidget(wMP);
    firstCol->layout()->addWidget(wCC);
    firstCol->layout()->addWidget(wLC);

    QWidget* wATC = new QWidget();
    wATC->setLayout(new QHBoxLayout);
    QLabel* lATC = new QLabel();
    lATC->setPixmap(QPixmap(":/assets/buttonAndText/charList/MP.png"));
    QLabel* lblATC = new QLabel();
    lblATC->setText("10/10");
    wATC->layout()->addWidget(lATC);
    wATC->layout()->addWidget(lblATC);

    QWidget* wDEF = new QWidget();
    wDEF->setLayout(new QHBoxLayout);
    QLabel* lDEF = new QLabel();
    lDEF->setPixmap(QPixmap(":/assets/buttonAndText/charList/HP.png"));
    QLabel* lblDEF = new QLabel();
    lblDEF->setText("10%");
    wDEF->layout()->addWidget(lDEF);
    wDEF->layout()->addWidget(lblDEF);

    QWidget* wDOD = new QWidget();
    wDOD->setLayout(new QHBoxLayout);
    QLabel* llDOD = new QLabel();
    llDOD->setPixmap(QPixmap(":/assets/buttonAndText/charList/HP.png"));
    QLabel* lblDOD = new QLabel();
    lblDOD->setText("10%");
    wDOD->layout()->addWidget(llDOD);
    wDOD->layout()->addWidget(lblDOD);

    secondCol = new QWidget();
    secondCol->setLayout(new QVBoxLayout);
    secondCol->layout()->addWidget(lATC);
    secondCol->layout()->addWidget(wDEF);
    secondCol->layout()->addWidget(wDOD);

    wHorizon = new QWidget(parent);
    wHorizon->setLayout(new QHBoxLayout);
    wHorizon->layout()->addWidget(firstCol);
    wHorizon->layout()->addWidget(secondCol);
    wParametrs->layout()->addWidget(wHorizon);

    skills = new ImageButton(":/assets/buttonAndText/charList/skills.png");
    skills->setCursor(Qt::CursorShape::PointingHandCursor);
    wParametrs->layout()->addWidget(skills);
}

//QWidget* wParametrs;
//QLabel* lblStr;
//QLabel* lblVit;
//QLabel* lblAgl;
//QLabel* lblPer;
//QLabel* lblInt;
//QLabel* lblWis;
//QLabel* lblParametrs;
//QWidget* firstCol;
//QWidget* secondCol;
//QWidget* wHorizon;


//ImageButton* skills;
