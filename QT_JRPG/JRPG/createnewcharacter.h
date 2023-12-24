#ifndef CREATENEWCHARACTER_H
#define CREATENEWCHARACTER_H

#include "hero.h"
#include "myspinbox.h"
#include "qlabel.h"
#include "qlineedit.h"
#include <QWidget>

class CreateNewCharacter : public QWidget
{
    Q_OBJECT
public:
    explicit CreateNewCharacter(QWidget *parent = nullptr);

    void setHidden(bool hidden);

    Hero getCat() const;

private:
    QWidget* background;

    QWidget* parametrs;

    QWidget* strNvit;
    QLabel* lblStr;
    QLabel* lblVit;
    MySpinBox* spinBoxStr;
    MySpinBox* spinBoxVit;

    QWidget* aglNper;
    QLabel* lblAgl;
    QLabel* lblPer;
    MySpinBox* spinBoxAgl;
    MySpinBox* spinBoxPer;

    QWidget* intNwis;
    QLabel* lblInt;
    QLabel* lblWis;
    MySpinBox* spinBoxInt;
    MySpinBox* spinBoxWis;

    QWidget* pointsPanel;
    QLabel* lblPoints;
    QLabel* points;

    QWidget* widHero;
    QLabel* picHero;
    QWidget* namePanel;
    QLabel* lblName;
    QLineEdit* editName;


    QWidget* buttonsPanel;
    ImageButton* backButton;
    ImageButton* skipButton;
    ImageButton* readyButton;


    Hero cat;

    int startPoints = 20;

private slots:
    void onButtonClickedReady();

    void receivedPlusSig();
    void receivedMinusSig();

signals:
    void back();
    void skip();
    void ready();

};

#endif // CREATENEWCHARACTER_H
