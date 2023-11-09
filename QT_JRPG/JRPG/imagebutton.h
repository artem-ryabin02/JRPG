#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H

#include <QAbstractButton>
#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QEvent>
#include <QPropertyAnimation>

class ImageButton: public QAbstractButton
{
    Q_OBJECT
public:
    ImageButton(QString namePXM);
    void setPixmap( const QPixmap& pm );
    QSize sizeHint() const;


protected:
    void paintEvent( QPaintEvent* e );
    bool eventFilter(QObject *obj, QEvent *e);
private:
    QString namePixmap;
    QSize size;
    QPixmap pixmap;


    void StartHoverEnterAnimation();
    void StartHoverLeaveAnimation();
};

#endif // IMAGEBUTTON_H
