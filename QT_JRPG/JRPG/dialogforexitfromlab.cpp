#include "dialogforexitfromlab.h"
#include "qboxlayout.h"

DialogForExitFromLab::DialogForExitFromLab(QWidget *parent)
    : QWidget{parent}
{
    wid = new QWidget(parent);//выделение памяти для wid
    wid->setLayout(new QVBoxLayout);// создаем разметку для виджета
    wid->setGeometry(460, 265, 1000, 550);// задаем расположение и размер
    wid->setStyleSheet("background:grey");// ставим цвет заднего фона на серый
    buttomPanel = new QWidget();//выделяем память
    buttomPanel->setLayout(new QHBoxLayout);// создаем разметку для панели кнопок
    yesButton = new ImageButton(":/assets/buttonAndText/YesOrNot/yes.png");//выделяем память под кнопку "да" и ставим картинку

    noButton = new ImageButton(":/assets/buttonAndText/YesOrNot/no.png");//выделяем память под кнопку "нет" и ставим картинку

    buttomPanel->layout()->addWidget(yesButton);//добавляем в разметку кнопку
    buttomPanel->layout()->addWidget(noButton);//добавляем в разметку кнопку
    buttomPanel->layout()->setAlignment(yesButton, Qt::AlignCenter);//делаем выравнивание кнопки по центру
    buttomPanel->layout()->setAlignment(noButton, Qt::AlignCenter);//делаем выравнивание кнопки по центру
    answer =  new QLabel();//выделяем память
    answer->setPixmap(QPixmap(":/assets/buttonAndText/YesOrNot/answer.png"));//ставим картинку
    wid->layout()->addWidget(answer);//добавляем в разметку вопрос
    wid->layout()->addWidget(buttomPanel);//добавляем в разметку панель кнопок
    wid->layout()->setAlignment(answer, Qt::AlignCenter);//выравниваем вопрос по центру

    connect(yesButton, &ImageButton::clicked, this, &DialogForExitFromLab::yesSig);//соединяем кнопку и отправку сигнала
    connect(noButton, &ImageButton::clicked, this, &DialogForExitFromLab::noSig);//соединяем кнопку и отправку сигнала
}

void DialogForExitFromLab::setHidden(bool hidden)
{
    wid->setHidden(hidden);//прячем виджет
}

void DialogForExitFromLab::setVolume(float volume)
{
    yesButton->setVolume(volume);
    noButton->setVolume(volume);
}
