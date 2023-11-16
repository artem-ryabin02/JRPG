#ifndef TALKINGWITHNPC_H
#define TALKINGWITHNPC_H

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


private slots:
    void onClickedGoodbye();
    void onClickedQuest();
    void onClickedTrade();
signals:
    void exitFromTWNPC();
};

#endif // TALKINGWITHNPC_H
