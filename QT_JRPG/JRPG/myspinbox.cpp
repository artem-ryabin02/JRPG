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

    checkMin(value);

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

void MySpinBox::setVolume(float volume)
{
    plus->setVolume(volume);
    minus->setVolume(volume);
}

bool MySpinBox::checkBorder(int pos)
{
    int val = value + pos;
    checkMin(val);
    checkMax(val);
    if(val >= minimum && val <= maximum){
        return true;
    }
    else {
        return false;
    }
}

void MySpinBox::checkMin(int val)
{
    if(val == minimum ){
        minus->setDisabled(true);
    }
    else minus->setDisabled(false);
}

void MySpinBox::checkMax(int val)
{
    if(val == maximum ){
        plus->setDisabled(true);
    }
    else plus->setDisabled(false);
}

void MySpinBox::plusClicked()
{
    if (checkBorder(1)){
        value++;
        lblValue->setText(QString::number(value));
        checkMin(value);
        emit plusSig();
    }
}

void MySpinBox::minusClicked()
{
    if (checkBorder(-1)){
        value--;
        lblValue->setText(QString::number(value));
        checkMax(value);
        emit minusSig();
    }
}
