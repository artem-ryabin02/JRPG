#ifndef DIALOGFOREXITFROMLAB_H
#define DIALOGFOREXITFROMLAB_H
// подключаем библеотеки
#include "imagebutton.h"
#include "qlabel.h"
#include <QWidget>

class DialogForExitFromLab : public QWidget
{
    Q_OBJECT
public:
    explicit DialogForExitFromLab(QWidget *parent = nullptr);// конструктор с входными данными родителя
    void setHidden(bool hidden);// метод для того что бы спрятать виджет
private:
    QWidget* wid;// "тело" виджета. Поверхность на которой он отображается
    QWidget* buttomPanel;// панель с кнопками
    ImageButton* yesButton;// кнопка да
    ImageButton* noButton;//кнопка нет
    QLabel* answer;// вопрос к пользователю

signals:
    void yesSig();// сигнал для передчи ответа да
    void noSig();// сигнал для передчи ответа нет
};

#endif // DIALOGFOREXITFROMLAB_H
