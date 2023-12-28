#include "magicbook.h"
#include "dbcontroller.h"
#include "qboxlayout.h"

MagicBook::MagicBook(QWidget *parent)
    : QWidget{parent}, cat("cater", 1,1,1,1,1,1), rat("rat",1,1,1,1,1,1,"rat_skill","ratpath")
{
    compendium = DBcontroller::heroSkill();
    background = new QWidget(parent);
    background->setLayout(new QVBoxLayout);
    background->setGeometry(305,77,1144,927);
    background->setStyleSheet("background:grey");

    pageMagicBook = new LineOfMagicBook *[compendium.size()];

    for (int i = 0; i < compendium.size(); i++) {
        pageMagicBook[i] = new LineOfMagicBook();
        pageMagicBook[i]->setLabels(compendium[i].getName(), compendium[i].getCost());
        pageMagicBook[i]->setFixedSize(background->width()-10, 60);
        background->layout()->addWidget(pageMagicBook[i]);
        qDebug() << compendium[i].getName();
    }


    back = new ImageButton(":/assets/buttonAndText/back.png");
    back->setParent(parent);
    background->layout()->addWidget(back);

    background->layout()->setAlignment(back, Qt::AlignBottom|Qt::AlignHCenter);

    connect(pageMagicBook[0],&LineOfMagicBook::used, this, [this](){useMagicBook(0); emit used();});
    connect(pageMagicBook[1],&LineOfMagicBook::used, this, [this](){useMagicBook(1); emit used();});
    connect(pageMagicBook[2],&LineOfMagicBook::used, this, [this](){useMagicBook(2); emit used();});

    connect(back, &ImageButton::clicked, this, &MagicBook::backSignal);
}

void MagicBook::setCat(const Hero &newCat)
{
    cat = newCat;
    compendium.last().setCost(cat.getMaxMana());
    pageMagicBook[2]->setLabels(compendium[2].getName(), compendium[2].getCost());
    for(int i = 0; i < compendium.size(); i++){
        if(compendium[i].getCost() > cat.getMana()){
            pageMagicBook[i]->setDisable(true);
        }
        else pageMagicBook[i]->setDisable(false);
    }
}

Enemy MagicBook::getRat() const
{
    return rat;
}

void MagicBook::setRat(const Enemy &newRat)
{
    rat = newRat;
}

void MagicBook::setHidden(bool hidden)
{
    background->setHidden(hidden);
}

void MagicBook::setHiddenButtons(bool hidden)
{
    for (int i = 0; i < compendium.size(); i++){
        pageMagicBook[i]->setHiddenButton(hidden);
    }
}

void MagicBook::setVolume(float volume)
{
    for (int i = 0; i < compendium.size(); i++){
        pageMagicBook[i]->setVolume(volume);
    }
    back->setVolume(volume);
}

void MagicBook::useMagicBook(int index)
{
    cat.wastingMana(compendium[index].getCost());
    compendium[index].useSkill(cat, rat);
    qDebug() << "здоровье врага " << rat.getHealth();
}

Hero MagicBook::getCat() const
{
    return cat;
}

