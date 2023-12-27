#ifndef MAGICBOOK_H
#define MAGICBOOK_H

#include "enemy.h"
#include "hero.h"
#include "lineofmagicbook.h"
#include "skill.h"
#include <QWidget>

class MagicBook : public QWidget
{
    Q_OBJECT
public:
    explicit MagicBook(QWidget *parent = nullptr);

    Hero getCat() const;
    void setCat(const Hero &newCat);

    Enemy getRat() const;
    void setRat(const Enemy &newRat);

    void setHidden(bool hidden);


private:
    QWidget *background;
    ImageButton *back;
    LineOfMagicBook **pageMagicBook;
    QVector<Skill> compendium;
    Hero cat;
    Enemy rat;
private slots:
    void useMagicBook(int index);
signals:
    void backSignal();
    void used();
};

#endif // MAGICBOOK_H
