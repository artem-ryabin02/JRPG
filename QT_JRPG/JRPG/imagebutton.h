#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H

#include <QAbstractButton>
#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QEvent>
#include <QtMultimedia/QMediaPlayer>
#include <QAudioOutput>
#include <QDir>

class ImageButton: public QAbstractButton
{
    Q_OBJECT
public:
    ImageButton(QString namePXM);
    ~ImageButton();
    void setPixmap( const QPixmap& pm );
    QSize sizeHint() const;
    void setVolume(float volume);
    void setDisabled(bool disable);


protected:
    void paintEvent( QPaintEvent* e );
    bool eventFilter(QObject *obj, QEvent *e);
private:
    QMediaPlayer *player;
    QAudioOutput* ao;

    bool disabled = false;

    QString namePixmap;
    QSize size;
    QPixmap pixmap;



    void startHoverEnterAnimation();
    void startHoverLeaveAnimation();
    void startDisableAnimation();
};

#endif // IMAGEBUTTON_H
