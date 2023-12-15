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
private:
    QWidget* wid;
    QWidget* buttomPanel;
    ImageButton* yesButton;
    ImageButton* noButton;
    QLabel* answer;

signals:
    void yesSig();
    void noSig();
};

#endif // DIALOGFOREXITFROMLAB_H
