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
