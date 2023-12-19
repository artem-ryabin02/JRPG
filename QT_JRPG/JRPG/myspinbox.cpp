#include "myspinbox.h"
#include "qboxlayout.h"

#include <QFontDatabase>

MySpinBox::MySpinBox(QWidget *parent)
    : QWidget{parent}
{
    int id = QFontDatabase::addApplicationFont(":/assets/PressStart2P-Regular.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont textFont(family, 36);

    spinBox = new QWidget(this);
    spinBox->setLayout(new QHBoxLayout);

    plus = new ImageButton(":/assets/buttonAndText/plus.png");
    minus = new ImageButton(":/assets/buttonAndText/minus.png");

    lblValue = new QLabel();
    lblValue->setFixedSize(90, 60);
    lblValue->setText(QString::number(value));
    lblValue->setFont(textFont);
    lblValue->setAlignment(Qt::AlignCenter);

    spinBox->layout()->addWidget(minus);
    spinBox->layout()->addWidget(lblValue);
    spinBox->layout()->addWidget(plus);

    connect(plus, &ImageButton::clicked, this, &MySpinBox::plusClicked);
    connect(minus, &ImageButton::clicked, this, &MySpinBox::minusClicked);
}

int MySpinBox::getValue() const
{
    return value;
}

void MySpinBox::setValue(int newValue)
{
    value = newValue;
}

int MySpinBox::getMinimum() const
{
    return minimum;
}

void MySpinBox::setMinimum(int newMinimum)
{
    minimum = newMinimum;
}

int MySpinBox::getMaximum() const
{
    return maximum;
}

void MySpinBox::setMaximum(int newMaximum)
{
    maximum = newMaximum;
}

void MySpinBox::setRange(int newMinimum, int newMaximum)
{
    minimum = newMinimum;
    maximum = newMaximum;
}

void MySpinBox::setPlusDisable(bool disable)
{
    plus->setDisabled(disable);
}

void MySpinBox::setMinusDisable(bool disable)
{
    minus->setDisabled(disable);
}

bool MySpinBox::checkBorder(int pos)
{
    if(value + pos >= minimum && value + pos <= maximum){
        return true;
    }
    else return false;
}

void MySpinBox::plusClicked()
{
    if (checkBorder(1)){
        value++;
        lblValue->setText(QString::number(value));
        emit plusSig();
    }
}

void MySpinBox::minusClicked()
{
    if (checkBorder(-1)){
        value--;
        lblValue->setText(QString::number(value));
        emit minusSig();
    }
}
