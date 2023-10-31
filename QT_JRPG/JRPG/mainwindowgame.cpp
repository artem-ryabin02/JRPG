#include "mainwindowgame.h"
#include "ui_mainwindowgame.h"

MainWindowGame::MainWindowGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowGame)
{
    ui->setupUi(this);

    bl = new BoardLocation(ui->widget);
    dwNPC = new DialogWithNPC();
    bl->rescale(ui->widget->height());
    connect(this, &MainWindowGame::wPress, bl, [=](){
        bl->updatePostion(-1, 0);});
    connect(this, &MainWindowGame::aPress, bl, [=](){
        bl->updatePostion(0, -1);});
    connect(this, &MainWindowGame::sPress, bl, [=](){
        bl->updatePostion(1, 0);});
    connect(this, &MainWindowGame::dPress, bl, [=](){
        bl->updatePostion(0, 1);});
    connect(bl, &BoardLocation::signalDialogWithNPC, this, &MainWindowGame::receivedSignalDialogWithNPC);
    connect(dwNPC, &DialogWithNPC::exitSignal, this, &MainWindowGame::receivedSignalExitDialogWithNPC);


}

MainWindowGame::~MainWindowGame()
{
    delete ui;
    delete bl;
    delete dwNPC;
}

void MainWindowGame::keyPressEvent(QKeyEvent *event){
    qDebug()<< "keyReleaseEvent\n";
    switch (event->key()) {
    case Qt::Key_W:
        emit wPress();
        break;
    case Qt::Key_A:
        emit aPress();
        break;
    case Qt::Key_S:
        emit sPress();
        break;
    case Qt::Key_D:
        emit dPress();
        break;
    default:
        break;
    }
}


void MainWindowGame::on_pushButton_clicked()
{
    this->close();
}

void MainWindowGame::receivedSignalDialogWithNPC()
{
    this->window()->setEnabled(false);
    dwNPC->showFullScreen();
}

void MainWindowGame::receivedSignalExitDialogWithNPC()
{
    this->window()->setEnabled(true);

}

