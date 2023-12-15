#include "dialogforexitfromlab.h"
#include "qboxlayout.h"

DialogForExitFromLab::DialogForExitFromLab(QWidget *parent)
    : QWidget{parent}
{
    wid = new QWidget(parent);
    wid->setLayout(new QVBoxLayout);
    wid->setGeometry(460, 265, 1000, 550);
    wid->setStyleSheet("backround:grey");
    buttomPanel = new QWidget();
    buttomPanel->setLayout(new QHBoxLayout);
    yesButton = new ImageButton(":/assets/buttonAndText/YesOrNot/yes.png");
    noButton = new ImageButton(":/assets/buttonAndText/YesOrNot/no.png");
    buttomPanel->layout()->addWidget(yesButton);
    buttomPanel->layout()->addWidget(noButton);
    answer =  new QLabel();
    answer->setPixmap(QPixmap(":/assets/buttonAndText/YesOrNot/answer.png"));
    wid->layout()->addWidget(answer);
    wid->layout()->addWidget(buttomPanel);
}
