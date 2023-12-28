#include "lineofmagicbook.h"
#include "qboxlayout.h"

#include <QFontDatabase>

LineOfMagicBook::LineOfMagicBook(QWidget *parent)
    : QWidget{parent}
{
    int id = QFontDatabase::addApplicationFont(":/assets/PressStart2P-Regular.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont textFont(family, 26);

    layoutWidget = new QWidget(this);
    layoutWidget->setLayout(new QHBoxLayout);

    nameSkill = new QLabel();
    nameSkill->setFont(textFont);
    nameSkill->setText("название");

    costSkill = new QLabel();
    costSkill->setFont(textFont);
    costSkill->setText("цена");

    useButton = new ImageButton(":/assets/buttonAndText/magicBook/use.png");

    layoutWidget->layout()->addWidget(nameSkill);
    layoutWidget->layout()->addWidget(costSkill);
    layoutWidget->layout()->addWidget(useButton);
    layoutWidget->layout()->setAlignment(useButton, Qt::AlignRight);
    layoutWidget->layout()->setAlignment(nameSkill, Qt::AlignLeft);

    connect(useButton, &ImageButton::clicked, this, &LineOfMagicBook::used);
}

void LineOfMagicBook::setDisable(bool disable)
{
    useButton->setDisabled(disable);
}

void LineOfMagicBook::setLabels(QString name, int cost)
{
    nameSkill->setText(name);
    costSkill->setText(" ОМ:"+QString::number(cost)+" ");
}

void LineOfMagicBook::setHidden(bool hidden)
{
    layoutWidget->setHidden(hidden);
}

void LineOfMagicBook::setHiddenButton(bool hidden)
{
    useButton->setHidden(hidden);
}

void LineOfMagicBook::setFixedSize(int w, int h)
{
    layoutWidget->setFixedSize(w, h);
}


