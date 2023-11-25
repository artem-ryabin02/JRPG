#ifndef FIELDLOCATION_H
#define FIELDLOCATION_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>

enum class NAME_FIELD {
    GRASS,
    WATER,
    GRASS_WATER_B,
    GRASS_WATER_T,
    GRASS_WATER_S,
    GRASS_WATER_C_B,
    GRASS_WATER_C_T,
    LABYRINTH_ENTRY,
    NONE
};

class FieldLocation: public QWidget
{
    Q_OBJECT
public:
    explicit FieldLocation(QWidget* parent=nullptr);
    void rescale(int _size);

    void setFree(bool f);
    void setNPC(bool f);
    void setLabyrinth(bool f);
    void setFieldName(QString fn);
    void fullSet(bool isFree, bool isNPC, bool isLab, QString flName);
    void setHero(bool f);

    bool getFree();
    bool getNPC();

    bool getIsLabyrinth() const;

protected:
    void paintEvent(QPaintEvent * pE) override;


private:
    int size;
    bool isFree;
    bool isLabyrinth;
    bool isNPC;
    bool isHero;

    QString fieldName;




signals:

};

#endif // FIELDLOCATION_H
