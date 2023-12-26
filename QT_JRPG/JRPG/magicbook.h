#ifndef MAGICBOOK_H
#define MAGICBOOK_H

#include "hero.h"
#include "lineofmagicbook.h"
#include "skill.h"
#include <QWidget>

class MagicBook : public QWidget
{
    Q_OBJECT
public:
    explicit MagicBook(QWidget *parent = nullptr);
    void setCat(const Hero &newCat);

private:
    QWidget *background;
    LineOfMagicBook **pageMagicBook;
    QVector<Skill> compendium;
    Hero cat;
signals:

};

#endif // MAGICBOOK_H
