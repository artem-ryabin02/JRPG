#include "createnewcharacter.h"
#include "qboxlayout.h"

#include <QFontDatabase>

CreateNewCharacter::CreateNewCharacter(QWidget *parent)
    : QWidget{parent},  cat("Cater", 5,5,5,5,5,5)
{

    int id = QFontDatabase::addApplicationFont(":/assets/PressStart2P-Regular.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont textFont(family, 36);

    background = new QWidget(parent);
    background->setGeometry(60, 150, 1800, 800);
    background->setStyleSheet("background: darkgrey");

    parametrs = new QWidget(parent);
    parametrs->setLayout(new QHBoxLayout);
    parametrs->setGeometry(105, 223, 1010, 660);

    strNvit = new QWidget();
    strNvit->setLayout(new QVBoxLayout);

    lblStr = new QLabel();
    lblStr->setPixmap(QPixmap(":/assets/buttonAndText/newCharacter/str.png"));
    spinBoxStr = new MySpinBox();

    lblVit = new QLabel();
    lblVit->setPixmap(QPixmap(":/assets/buttonAndText/newCharacter/vit.png"));
    spinBoxVit = new MySpinBox();

    strNvit->layout()->addWidget(lblStr);
    strNvit->layout()->addWidget(spinBoxStr);

    strNvit->layout()->addWidget(lblVit);
    strNvit->layout()->addWidget(spinBoxVit);



    aglNper = new QWidget();
    aglNper->setLayout(new QVBoxLayout);

    lblAgl = new QLabel();
    lblAgl->setPixmap(QPixmap(":/assets/buttonAndText/newCharacter/agl.png"));
    spinBoxAgl = new MySpinBox();

    lblPer = new QLabel();
    lblPer->setPixmap(QPixmap(":/assets/buttonAndText/newCharacter/per.png"));
    spinBoxPer = new MySpinBox();

    aglNper->layout()->addWidget(lblAgl);
    aglNper->layout()->addWidget(spinBoxAgl);

    aglNper->layout()->addWidget(lblPer);
    aglNper->layout()->addWidget(spinBoxPer);

    intNwis = new QWidget();
    intNwis->setLayout(new QVBoxLayout);

    lblInt = new QLabel();
    lblInt->setPixmap(QPixmap(":/assets/buttonAndText/newCharacter/intl.png"));
    spinBoxInt = new MySpinBox();

    lblWis = new QLabel();
    lblWis->setPixmap(QPixmap(":/assets/buttonAndText/newCharacter/wis.png"));
    spinBoxWis = new MySpinBox();

    intNwis->layout()->addWidget(lblInt);
    intNwis->layout()->addWidget(spinBoxInt);

    intNwis->layout()->addWidget(lblWis);
    intNwis->layout()->addWidget(spinBoxWis);

    parametrs->layout()->addWidget(strNvit);
    parametrs->layout()->addWidget(aglNper);
    parametrs->layout()->addWidget(intNwis);

    pointsPanel = new QWidget(parent);
    pointsPanel->setLayout(new QHBoxLayout);
    pointsPanel->setGeometry(105, 175, 775, 60);

    lblPoints = new QLabel();
    lblPoints->setPixmap(QPixmap(":/assets/buttonAndText/newCharacter/points.png"));

    points = new QLabel();
    points->setText(QString::number(startPoints));
    points->setFont(textFont);

    pointsPanel->layout()->addWidget(lblPoints);
    pointsPanel->layout()->addWidget(points);

    widHero = new QWidget(parent);
    widHero->setGeometry(1297, 205, 480, 540);
    widHero->setLayout(new QVBoxLayout);
    picHero = new QLabel();
    picHero->setPixmap(QPixmap(":/assets/characters/hero.png"));
    picHero->setFixedSize(480, 480);
    picHero->setScaledContents(true);
    namePanel = new QWidget();
    namePanel->setLayout(new QHBoxLayout);
    lblName = new QLabel();
    lblName->setPixmap(QPixmap(":/assets/buttonAndText/newCharacter/name.png"));
    editName = new QLineEdit();
    editName->setText("Cater");
    editName->setFont(textFont);

    namePanel->layout()->addWidget(lblName);
    namePanel->layout()->addWidget(editName);

    widHero->layout()->addWidget(picHero);
    widHero->layout()->addWidget(namePanel);

    buttonsPanel = new QWidget(parent);
    buttonsPanel->setLayout(new QHBoxLayout);
    buttonsPanel->setGeometry(105, 883, 1730, 60);
    backButton = new ImageButton(":/assets/buttonAndText/back.png");
    readyButton = new ImageButton(":/assets/buttonAndText/newCharacter/ready.png");
    skipButton = new ImageButton(":/assets/buttonAndText/newCharacter/skip.png");

    buttonsPanel->layout()->addWidget(skipButton);
    buttonsPanel->layout()->setAlignment(skipButton, Qt::AlignLeft);
    buttonsPanel->layout()->addWidget(backButton);
    buttonsPanel->layout()->addWidget(readyButton);

    buttonsPanel->layout()->setAlignment(backButton, Qt::AlignRight);
    buttonsPanel->layout()->setAlignment(readyButton, Qt::AlignRight);

    connect(spinBoxStr, &MySpinBox::plusSig, this, &CreateNewCharacter::receivedPlusSig);
    connect(spinBoxStr, &MySpinBox::minusSig, this, &CreateNewCharacter::receivedMinusSig);

    connect(spinBoxVit, &MySpinBox::plusSig, this, &CreateNewCharacter::receivedPlusSig);
    connect(spinBoxVit, &MySpinBox::minusSig, this, &CreateNewCharacter::receivedMinusSig);

    connect(spinBoxAgl, &MySpinBox::plusSig, this, &CreateNewCharacter::receivedPlusSig);
    connect(spinBoxAgl, &MySpinBox::minusSig, this, &CreateNewCharacter::receivedMinusSig);

    connect(spinBoxPer, &MySpinBox::plusSig, this, &CreateNewCharacter::receivedPlusSig);
    connect(spinBoxPer, &MySpinBox::minusSig, this, &CreateNewCharacter::receivedMinusSig);

    connect(spinBoxInt, &MySpinBox::plusSig, this, &CreateNewCharacter::receivedPlusSig);
    connect(spinBoxInt, &MySpinBox::minusSig, this, &CreateNewCharacter::receivedMinusSig);

    connect(spinBoxWis, &MySpinBox::plusSig, this, &CreateNewCharacter::receivedPlusSig);
    connect(spinBoxWis, &MySpinBox::minusSig, this, &CreateNewCharacter::receivedMinusSig);

    connect(backButton, &ImageButton::clicked, this, &CreateNewCharacter::back);
    connect(skipButton, &ImageButton::clicked, this, &CreateNewCharacter::ready);
    connect(readyButton, &ImageButton::clicked, this, &CreateNewCharacter::onButtonClickedReady);

}

void CreateNewCharacter::setHidden(bool hidden)
{
    background->setHidden(hidden);
    buttonsPanel->setHidden(hidden);
    widHero->setHidden(hidden);
    pointsPanel->setHidden(hidden);
    parametrs->setHidden(hidden);
}

Hero CreateNewCharacter::getCat() const
{
    return cat;
}

void CreateNewCharacter::onButtonClickedReady()
{
    cat = Hero(editName->displayText(), spinBoxVit->getValue(), spinBoxStr->getValue(),
                                        spinBoxAgl->getValue(), spinBoxPer->getValue(),
                                        spinBoxInt->getValue(), spinBoxWis->getValue()
               );
    emit ready();
}

void CreateNewCharacter::receivedPlusSig()
{
    if (startPoints - 1  == 0){
        points->setText(QString::number(--startPoints));
        spinBoxStr->setPlusDisable(true);
        spinBoxVit->setPlusDisable(true);
        spinBoxAgl->setPlusDisable(true);
        spinBoxPer->setPlusDisable(true);
        spinBoxInt->setPlusDisable(true);
        spinBoxWis->setPlusDisable(true);
    }
    else {
        points->setText(QString::number(--startPoints));
    }
}

void CreateNewCharacter::receivedMinusSig()
{
    if (startPoints + 1  == 10){
        points->setText(QString::number(++startPoints));
    }
    else {
        points->setText(QString::number(++startPoints));
        spinBoxStr->setPlusDisable(false);
        spinBoxVit->setPlusDisable(false);
        spinBoxAgl->setPlusDisable(false);
        spinBoxPer->setPlusDisable(false);
        spinBoxInt->setPlusDisable(false);
        spinBoxWis->setPlusDisable(false);
    }
}


