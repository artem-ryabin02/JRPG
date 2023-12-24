#include "imagebutton.h"

#include <QSoundEffect>




ImageButton::ImageButton(QString namePXM)
{
    namePixmap = namePXM;
    setPixmap(QPixmap(namePixmap));
    installEventFilter(this);
    player = new QMediaPlayer();
    ao = new QAudioOutput();
    ao->setVolume(1);
    player->setSource(QUrl::fromLocalFile(QDir::currentPath()+ "/music/button_click.wav"));
    player->setAudioOutput(ao);

}

ImageButton::~ImageButton()
{
    qDebug() << "ImageButton";
    delete player;
    delete ao;
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

void ImageButton::setVolume(float volume)
{
    ao->setVolume(volume);
}

void ImageButton::setDisabled(bool disable){
    if (disable){
        int pos = namePixmap.lastIndexOf(QChar('.'));
        QString namePixmapDis = namePixmap.left(pos) + "_dis.png";
        setPixmap(namePixmapDis);
    }
    else{
        setPixmap(namePixmap);
    }
    this->blockSignals(disable);
}

void ImageButton::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter p( this );
    p.drawPixmap( 0, 0, pixmap );
}

bool ImageButton::eventFilter(QObject *obj, QEvent *e)
{
    Q_UNUSED(obj);
    if (e->type() == QEvent::HoverEnter) {
        StartHoverEnterAnimation();
    }
    if (e->type() == QEvent::HoverLeave) {
        StartHoverLeaveAnimation();
    }

    return false;
}

void ImageButton::StartHoverEnterAnimation()
{
    player->play();
    int pos = namePixmap.lastIndexOf(QChar('.'));
    QString namePixmapAct = namePixmap.left(pos) + "_act.png";
    setPixmap(namePixmapAct);
}

void ImageButton::StartHoverLeaveAnimation()
{
   setPixmap(namePixmap);
}


