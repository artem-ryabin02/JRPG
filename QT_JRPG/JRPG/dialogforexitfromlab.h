#ifndef DIALOGFOREXITFROMLAB_H
#define DIALOGFOREXITFROMLAB_H

#include "imagebutton.h"
#include "qlabel.h"
#include <QWidget>

class DialogForExitFromLab : public QWidget
{
    Q_OBJECT
public:
    explicit DialogForExitFromLab(QWidget *parent = nullptr);
    void setHidden(bool hidden);
private:
    QWidget* wid;
    QWidget* buttomPanel;
    ImageButton* yesButton;
    ImageButton* noButton;
    QLabel* answer;
private slots:
    void onButtonYesClicked();
    void onButtonNoClicked();
signals:
    void yesSig();
    void noSig();
};

#endif // DIALOGFOREXITFROMLAB_H
