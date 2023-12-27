#ifndef MAINMENU_H
#define MAINMENU_H

#include "imagebutton.h"
#include <QLabel>
#include <QObject>
#include <QWidget>

class MainMenu: public QWidget
{
    Q_OBJECT
public:
    explicit MainMenu(QWidget* parent = nullptr);
    ~MainMenu();

    void setHidden(bool hidden);
    void setVolume(float volume);
protected:
private:
    QWidget* wButtons;
    QWidget* wTitle;
    QLabel* lt;
    QLabel* bkd;
    ImageButton* nbg;
    ImageButton* lbg;
    ImageButton* ebg;
private slots:

    void onButtonExitClicked();

    void onButtonNewGameClicked();

    void onButtonLoadGameClicked();
signals:
    void exit();
    void newGame();
    void loadGame();

};

#endif // MAINMENU_H
