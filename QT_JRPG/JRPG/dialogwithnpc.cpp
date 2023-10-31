#include "dialogwithnpc.h"
#include "ui_dialogwithnpc.h"

DialogWithNPC::DialogWithNPC(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogWithNPC)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint);
    //setWindowOpacity(0.6);
    setStyleSheet("QWidget{background: #ffffff}");
    setAttribute(Qt::WA_TranslucentBackground);



}

DialogWithNPC::~DialogWithNPC()
{
    delete ui;
}

void DialogWithNPC::on_pushButtonQuest_clicked()
{
    ui->textEdit->setText("Нет, пока что ничего");
}


void DialogWithNPC::on_pushButtonTrade_clicked()
{
    ui->textEdit->setText("Нет, пока что нечем торговать");
}


void DialogWithNPC::on_pushButtonExit_clicked()
{
    emit exitSignal();
    this->close();
}

