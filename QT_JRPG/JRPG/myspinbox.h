#ifndef MYSPINBOX_H
#define MYSPINBOX_H

#include "imagebutton.h"
#include "qlabel.h"
#include <QWidget>

class MySpinBox : public QWidget
{
    Q_OBJECT
public:
    explicit MySpinBox(QWidget *parent = nullptr);
    int getValue() const;
    void setValue(int newValue);

    int getMinimum() const;
    void setMinimum(int newMinimum);

    int getMaximum() const;
    void setMaximum(int newMaximum);

    void setRange(int newMinimum, int newMaximum);

    void setPlusDisable(bool disable);
    void setMinusDisable(bool disable);
    void setVolume(float volume);
private:
    QWidget* spinBox;
    ImageButton* plus;
    ImageButton* minus;
    QLabel* lblValue;


    int maximum = 10;
    int minimum = 1;
    int value = minimum;

    bool checkBorder(int pos);
    void checkMin(int val);
    void checkMax(int val);
private slots:
    void plusClicked();
    void minusClicked();
signals:
    void plusSig();
    void minusSig();
};

#endif // MYSPINBOX_H
