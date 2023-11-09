#include "imagebutton.h"
#include "mainwindowgame.h"
#include "ui_mainwindowgame.h"

MainWindowGame::MainWindowGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowGame)
{
    ui->setupUi(this);
    ui->progressBarHP->setValue(ui->progressBarHP->maximum());
    ui->progressBarMP->setValue(ui->progressBarMP->maximum());

    bl = new BoardLocation(ui->widget);
    dwNPC = new DialogWithNPC();
    bl->rescale(ui->widget->height());

    w = new QWidget(ui->centralwidget);
    w->setObjectName("containerWidget");
    w->setLayout(new QVBoxLayout);
    w->setGeometry(1150, 750, 717, 260);
    ImageButton* chlb = new ImageButton(":/assets/buttonAndText/char_list_button.png");
    chlb->setObjectName("charListB");
    chlb->setCursor(Qt::CursorShape::PointingHandCursor);
    w->layout()->addWidget(chlb);
    w->layout()->setAlignment(chlb, Qt::AlignHCenter);
    ImageButton* invb = new ImageButton(":/assets/buttonAndText/inventory_button.png");
    invb->setObjectName("inventoryB");
    invb->setCursor(Qt::CursorShape::PointingHandCursor);
    w->layout()->addWidget(invb);
    w->layout()->setAlignment(invb, Qt::AlignHCenter);
    ImageButton* lgb = new ImageButton(":/assets/buttonAndText/load_button.png");
    lgb->setObjectName("loadGameB");
    lgb->setCursor(Qt::CursorShape::PointingHandCursor);
    w->layout()->addWidget(lgb);
    w->layout()->setAlignment(lgb, Qt::AlignHCenter);
    ImageButton* egb = new ImageButton(":/assets/buttonAndText/exit_button.png");
    egb->setObjectName("exitGameB");
    egb->setCursor(Qt::CursorShape::PointingHandCursor);
    w->layout()->addWidget(egb);
    w->layout()->setAlignment(egb, Qt::AlignHCenter);


    connect(chlb, &ImageButton::clicked, this, &MainWindowGame::on_pushCharListButton_clicked);
    connect(invb, &ImageButton::clicked, this, &MainWindowGame::on_pushInventoryButton_clicked);
    connect(lgb, &ImageButton::clicked, this, &MainWindowGame::on_pushLoadButton_clicked);
    connect(egb, &ImageButton::clicked, this, &MainWindowGame::on_pushExitButton_clicked);


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

void MainWindowGame::on_pushExitButton_clicked()
{
    this->close();
}

void MainWindowGame::on_pushInventoryButton_clicked()
{
    ui->statusbar->showMessage("ПОКА НЕ РАБОТАЕТ", 2000);
}

void MainWindowGame::on_pushCharListButton_clicked()
{
    ui->statusbar->showMessage("ПОКА НЕ РАБОТАЕТ", 2000);
}

void MainWindowGame::on_pushLoadButton_clicked()
{
    ui->statusbar->showMessage("ПОКА НЕ РАБОТАЕТ", 2000);
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

