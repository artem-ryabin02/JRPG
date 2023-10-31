#ifndef DIALOGWITHNPC_H
#define DIALOGWITHNPC_H

#include <QDialog>

namespace Ui {
class DialogWithNPC;
}

class DialogWithNPC : public QDialog
{
    Q_OBJECT

public:
    explicit DialogWithNPC(QWidget *parent = nullptr);
    ~DialogWithNPC();

private slots:
    void on_pushButtonQuest_clicked();

    void on_pushButtonTrade_clicked();

    void on_pushButtonExit_clicked();

private:
    Ui::DialogWithNPC *ui;

signals:
    void exitSignal();
};

#endif // DIALOGWITHNPC_H
