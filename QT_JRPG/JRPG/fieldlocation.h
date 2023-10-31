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
    //void deleteHero();

    bool getFree();
    bool getNPC();

protected:
    void paintEvent(QPaintEvent * pE) override;
    //void mouseDoubleClickEvent(QMouseEvent *event) override;
    //void keyReleaseEvent(QKeyEvent *event)override;

private:
    int size;
    bool isFree;
    bool isLabyrinth;
    bool isNPC;
    bool isHero;

    QString fieldName;
    //std::map<NAME_FIELD, QString> fieldName;



signals:
    void leftMouseDoubleClick();
    void wPress();
    void aPress();
    void sPress();
    void dPress();
};

#endif // FIELDLOCATION_H
