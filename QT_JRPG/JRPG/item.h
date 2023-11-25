#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item
{
public:
    Item(QString name, int weight, int effKey);
private:
    QString name;
    int weight;
    //Effect eff;
};

#endif // ITEM_H
