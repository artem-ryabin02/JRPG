#include "dialogforexitfromlab.h"
#include "qboxlayout.h"

DialogForExitFromLab::DialogForExitFromLab(QWidget *parent)
    : QWidget{parent}
{
    wid = new QWidget(parent);
    wid->setLayout(new QVBoxLayout);
    wid->setGeometry(460, 265, 1000, 550);
    wid->setStyleSheet("background:grey");
    buttomPanel = new QWidget();
    buttomPanel->setLayout(new QHBoxLayout);
    yesButton = new ImageButton(":/assets/buttonAndText/YesOrNot/yes.png");
    //yesButton->setFixedSize(120, 60);

    noButton = new ImageButton(":/assets/buttonAndText/YesOrNot/no.png");
    //noButton->setFixedSize(120, 60);
    buttomPanel->layout()->addWidget(yesButton);
    buttomPanel->layout()->addWidget(noButton);
    buttomPanel->layout()->setAlignment(yesButton, Qt::AlignCenter);
    buttomPanel->layout()->setAlignment(noButton, Qt::AlignCenter);
    answer =  new QLabel();
    answer->setPixmap(QPixmap(":/assets/buttonAndText/YesOrNot/answer.png"));
    wid->layout()->addWidget(answer);
    wid->layout()->addWidget(buttomPanel);
    wid->layout()->setAlignment(answer, Qt::AlignCenter);
    //wid->layout()->setAlignment(buttomPanel, Qt::AlignCenter);

    connect(yesButton, &ImageButton::clicked, this, &DialogForExitFromLab::onButtonYesClicked);
    connect(noButton, &ImageButton::clicked, this, &DialogForExitFromLab::onButtonNoClicked);
}

void DialogForExitFromLab::setHidden(bool hidden)
{
    wid->setHidden(hidden);
}

void DialogForExitFromLab::onButtonYesClicked()
{
    emit yesSig();
}

void DialogForExitFromLab::onButtonNoClicked()
{
    emit noSig();
}
