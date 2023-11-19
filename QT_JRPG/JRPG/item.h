#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item
{
public:   
    QString name;

    int weight;

    //Effect eff;

    Item(){};

    Item(QString name, int weight, int effKey);
};

#endif // ITEM_H
