QT       += core gui
QT       += sql
QT       += multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    boardlabyrinth.cpp \
    boardlocation.cpp \
    character.cpp \
    charlistview.cpp \
    dbcontroller.cpp \
    effect.cpp \
    enemy.cpp \
    fieldlabyrinth.cpp \
    fieldlocation.cpp \
    game.cpp \
    generatorlabyrinth.cpp \
    hero.cpp \
    imagebutton.cpp \
    item.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    skill.cpp \
    talkingwithnpc.cpp \
    tmpdata.cpp

HEADERS += \
    boardlabyrinth.h \
    boardlocation.h \
    character.h \
    charlistview.h \
    dbcontroller.h \
    effect.h \
    enemy.h \
    fieldlabyrinth.h \
    fieldlocation.h \
    game.h \
    generatorlabyrinth.h \
    hero.h \
    imagebutton.h \
    imagebutton_копия.h \
    item.h \
    mainmenu.h \
    mainwindow.h \
    skill.h \
    talkingwithnpc.h \
    tmpdata.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    assets.qrc

DISTFILES += \
    assets/buttonAndText/charList/Crit Chance_.png \
    assets/buttonAndText/charList/Load capacity_.png
