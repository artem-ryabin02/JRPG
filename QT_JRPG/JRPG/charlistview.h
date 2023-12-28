#ifndef CHARLISTVIEW_H
#define CHARLISTVIEW_H

#include "hero.h"
#include "imagebutton.h"
#include <QLabel>
#include <QObject>
#include <QWidget>
#include <QLayout>

class CharListView : public QWidget
{
    Q_OBJECT
public:
    explicit CharListView(QWidget *parent = nullptr);
    ~CharListView();
    void setHidden(bool hidden);

    void setCat(const Hero &newCat);
    void setVolume(float volume);

private:
    QWidget* wArtEquips;
    QLabel* art;
    QWidget* wEquips;
    QLabel* weaponArt;
    QLabel* armorArt;

    QWidget* wParametrs;
    QLabel* lblStr;
    QLabel* lblVit;
    QLabel* lblAgl;
    QLabel* lblPer;
    QLabel* lblInt;
    QLabel* lblWis;
    QLabel* lblParametrs;
    QWidget* wHP;
    QLabel* lHP;
    QLabel* lblhp;

    QWidget* wMP;
    QLabel* lMP;
    QLabel* lblMp;

    QWidget* wCC;
    QLabel* lcc;
    QLabel* lblcc;

    QWidget* wLC;
    QLabel* llc;
    QLabel* lbllc;

    QWidget* wATC;
    QLabel* lATC;
    QLabel* lblATC;

    QWidget* wDEF;
    QLabel* lDEF;
    QLabel* lblDEF;
    QWidget* wDOD;
    QLabel* llDOD;
    QLabel* lblDOD;



    QWidget* firstCol;
    QWidget* secondCol;
    QWidget* wHorizon;


    ImageButton* skills;
    ImageButton* back;

    Hero cat;


signals:
    void goSkill();
    void goBack();


};

#endif // CHARLISTVIEW_H
