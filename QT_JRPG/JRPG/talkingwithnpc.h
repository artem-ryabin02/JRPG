#ifndef TALKINGWITHNPC_H
#define TALKINGWITHNPC_H

#include "hero.h"
#include "imagebutton.h"
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QTextEdit>

class TalkingWithNPC : public QWidget
{
    Q_OBJECT
public:
    explicit TalkingWithNPC(QWidget *parent = nullptr);
    ~TalkingWithNPC();
    void setHidden(bool hidden);
    Hero getCat() const;
    void setCat(const Hero &newCat);
    void setVolume(float volume);

private:
    QWidget* panelText;
    QWidget* wNPC;
    QWidget* wHero;
    QLabel* h;
    QLabel* n;
    QLabel* lblNPC;
    QLabel* lblHero;
    QTextEdit* monolog;
    ImageButton* qb;
    ImageButton* tb;
    ImageButton* gbb;



    Hero cat;
    int scale = 5;
    void setQuest();
    void getQuest();


private slots:
    void onClickedGoodbye();
    void onClickedQuest();
    void onClickedTrade();
signals:
    void exitFromTWNPC();
};

#endif // TALKINGWITHNPC_H
