#include "talkingwithnpc.h"
#include "qboxlayout.h"
#include <QFontDatabase>

TalkingWithNPC::TalkingWithNPC(QWidget *parent)
    : QWidget{parent}, cat("H", 1,1,1,1,1,1)
{

    int id = QFontDatabase::addApplicationFont(":/assets/PressStart2P-Regular.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont textFont(family, 36);

    panelText = new QWidget(parent);
    panelText->setObjectName("panelTextWidget");
    panelText->setLayout(new QVBoxLayout);
    panelText->setGeometry(0, 600, 1920, 440);
    panelText->setStyleSheet("background-color: rgb(115, 115, 115);");

    h = new QLabel();
    n = new QLabel();
    h->setFont(textFont);
    h->setText(cat.getName());
    n->setFont(textFont);
    n->setText("Кролик");
    h->setFixedHeight(50);
    n->setFixedHeight(50);




    monolog = new QTextEdit();
    monolog->setReadOnly(true);
    monolog->setFont(textFont);
    monolog->setFixedSize(1840, 130);
    monolog->setText("Короче, Котяра, я тебя спас и в благородство играть не буду: "
                     "принесешь для меня пару артефактов – и мы в расчете. ");
    monolog->setStyleSheet("border-color: black");
    monolog->setTextInteractionFlags(Qt::NoTextInteraction);
    monolog->setMouseTracking(false);
    panelText->layout()->addWidget(monolog);
    qb = new ImageButton(":/assets/buttonAndText/Talking/quest.png");
    qb->setObjectName("questB");
    qb->setCursor(Qt::CursorShape::PointingHandCursor);

    tb = new ImageButton(":/assets/buttonAndText/Talking/trade.png");
    tb->setObjectName("tradeB");
    tb->setCursor(Qt::CursorShape::PointingHandCursor);

    gbb = new ImageButton(":/assets/buttonAndText/Talking/goodbye.png");
    gbb->setObjectName("goodbyeB");
    gbb->setCursor(Qt::CursorShape::PointingHandCursor);

    panelText->layout()->addWidget(qb);
    panelText->layout()->addWidget(tb);
    panelText->layout()->addWidget(gbb);

    wNPC =new QWidget(parent);
    wHero =new QWidget(parent);
    wNPC->setGeometry(40, 405, 560, 250);
    wNPC->setLayout(new QHBoxLayout);
    wHero->setGeometry(1400, 405, 500, 250);
    wHero->setLayout(new QHBoxLayout);


    lblHero = new QLabel();
    lblHero->setPixmap(QPixmap(":/assets/characters/hero.png"));
    lblHero->setScaledContents(true);
    lblHero->setFixedSize(250, 250);
    lblNPC = new QLabel();
    lblNPC->setPixmap(QPixmap(":/assets/characters/nps_demot.png"));
    lblNPC->setScaledContents(true);
    lblNPC->setFixedSize(250, 250);

    wNPC->layout()->addWidget(lblNPC);
    wNPC->layout()->addWidget(n);
    wNPC->layout()->setAlignment(n, Qt::AlignRight);
    wNPC->layout()->setAlignment(n, Qt::AlignBottom);

    wHero->layout()->addWidget(h);
    wHero->layout()->addWidget(lblHero);
    wHero->layout()->setAlignment(h, Qt::AlignLeft);
    wHero->layout()->setAlignment(h, Qt::AlignBottom);

    connect(gbb, &ImageButton::clicked, this, &TalkingWithNPC::onClickedGoodbye);
    connect(qb, &ImageButton::clicked, this, &TalkingWithNPC::onClickedQuest);
    connect(tb, &ImageButton::clicked, this, &TalkingWithNPC::onClickedTrade);


}

TalkingWithNPC::~TalkingWithNPC()
{
    delete panelText;
    delete wNPC;
    delete wHero;
}

void TalkingWithNPC::setHidden(bool hidden)
{
    if (hidden){
        if (!cat.getIsQuest()){
            monolog->setText("Короче, Котяра, я тебя спас и в благородство играть не буду: "
                             "принесешь для меня пару артефактов – и мы в расчете. ");
        }
        else{
            monolog->setText("Привет " + cat.getName() + "! Как дела?");
        }
    }
    wNPC->setHidden(hidden);
    wHero->setHidden(hidden);
    panelText->setHidden(hidden);
}

Hero TalkingWithNPC::getCat() const
{
    return cat;
}

void TalkingWithNPC::setCat(const Hero &newCat)
{
    cat = newCat;
    h->setText(cat.getName());
}

void TalkingWithNPC::setQuest()
{
    cat.setIsQuest(true);
    cat.setMission(cat.getMission()*scale);

}

void TalkingWithNPC::getQuest()
{
    cat.setCounterQuest(cat.getCounterQuest() - cat.getMission());

    cat.setIsQuest(false);
}

void TalkingWithNPC::onClickedGoodbye()
{
    emit exitFromTWNPC();
}

void TalkingWithNPC::onClickedQuest()
{
    if (!cat.getIsQuest()){
        monolog->setText("Сейчас мне нужно - " + QString::number(cat.getMission()*scale) + " артефактов");
        setQuest();
    }else{
        if (cat.getReadyQuest()){
            monolog->setText("Молодец, теперь мне нужно " + QString::number(cat.getMission()*scale) + " артефактов");
            getQuest();
            setQuest();
        }
        else{
            monolog->setText("Ты ничего не сделал. Мне нужно " + QString::number(cat.getMission()) + " артефактов");
        }
    }
}

void TalkingWithNPC::onClickedTrade()
{
    monolog->setText("Пока нечем торговать");
}
