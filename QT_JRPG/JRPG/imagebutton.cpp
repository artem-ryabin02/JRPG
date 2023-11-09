#include "imagebutton.h"


ImageButton::ImageButton(QString namePXM)
{
    namePixmap = namePXM;
    setPixmap(QPixmap(namePixmap));
    installEventFilter(this);
}

void ImageButton::setPixmap(const QPixmap &pm)
{
    pixmap = pm;
    update();
}

QSize ImageButton::sizeHint() const
{
    return pixmap.size();
}

void ImageButton::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    qDebug() << "paint event\n";
    QPainter p( this );
    p.drawPixmap( 0, 0, pixmap );
}

bool ImageButton::eventFilter(QObject *obj, QEvent *e)
{
    Q_UNUSED(obj);
    if (e->type() == QEvent::HoverEnter) {
        qDebug() << "hover enter event\n";
        StartHoverEnterAnimation();
    }

    if (e->type() == QEvent::HoverLeave) {
        qDebug() << "hover leave event\n";
        StartHoverLeaveAnimation();
    }

    return false;
}

void ImageButton::StartHoverEnterAnimation()
{
    int pos = namePixmap.lastIndexOf(QChar('.'));
    QString namePixmapAct = namePixmap.left(pos) + "_act.png";
    setPixmap(namePixmapAct);
}

void ImageButton::StartHoverLeaveAnimation()
{
   setPixmap(namePixmap);
}


