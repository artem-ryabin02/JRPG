#ifndef LINEOFMAGICBOOK_H
#define LINEOFMAGICBOOK_H

#include "imagebutton.h"
#include "qlabel.h"
#include <QWidget>

class LineOfMagicBook : public QWidget
{
    Q_OBJECT
public:
    explicit LineOfMagicBook(QWidget *parent = nullptr);
    void setDisable(bool disable);
    void setLabels(QString name, int cost);
    void setHidden(bool hidden);
    void setHiddenButton(bool hidden);
    void setFixedSize(int w, int h);
    void setVolume(float volume);
private:
    QWidget* layoutWidget;
    QLabel* nameSkill;
    QLabel* costSkill;
    ImageButton* useButton;
signals:
    void used();
};

#endif // LINEOFMAGICBOOK_H
