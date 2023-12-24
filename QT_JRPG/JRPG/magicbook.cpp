#include "magicbook.h"
#include "dbcontroller.h"
#include "qboxlayout.h"

MagicBook::MagicBook(QWidget *parent)
    : QWidget{parent}, cat("cater", 1,1,1,1,1,1)
{
    compendium = DBcontroller::heroSkill();

    background = new QWidget(parent);
    background->setLayout(new QVBoxLayout);
    background->setGeometry(305,77,1144,927);
    background->setStyleSheet("background:grey");

}

void MagicBook::setCat(const Hero &newCat)
{
    cat = newCat;
}
