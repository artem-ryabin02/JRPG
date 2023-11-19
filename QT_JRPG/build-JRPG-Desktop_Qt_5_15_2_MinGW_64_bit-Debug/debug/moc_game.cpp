/****************************************************************************
** Meta object code from reading C++ file 'game.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../JRPG/game.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Game_t {
    QByteArrayData data[17];
    char stringdata0[270];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Game_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Game_t qt_meta_stringdata_Game = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Game"
QT_MOC_LITERAL(1, 5, 4), // "exit"
QT_MOC_LITERAL(2, 10, 0), // ""
QT_MOC_LITERAL(3, 11, 8), // "charList"
QT_MOC_LITERAL(4, 20, 9), // "inventory"
QT_MOC_LITERAL(5, 30, 8), // "loadGame"
QT_MOC_LITERAL(6, 39, 11), // "talkWithNPC"
QT_MOC_LITERAL(7, 51, 23), // "onPushExitButtonClicked"
QT_MOC_LITERAL(8, 75, 28), // "onPushInventoryButtonClicked"
QT_MOC_LITERAL(9, 104, 27), // "onPushCharListButtonClicked"
QT_MOC_LITERAL(10, 132, 23), // "onPushLoadButtonClicked"
QT_MOC_LITERAL(11, 156, 27), // "receivedSignalDialogWithNPC"
QT_MOC_LITERAL(12, 184, 31), // "receivedSignalExitDialogWithNPC"
QT_MOC_LITERAL(13, 216, 13), // "recaivedSouth"
QT_MOC_LITERAL(14, 230, 13), // "recaivedNorth"
QT_MOC_LITERAL(15, 244, 12), // "recaivedEast"
QT_MOC_LITERAL(16, 257, 12) // "recaivedWest"

    },
    "Game\0exit\0\0charList\0inventory\0loadGame\0"
    "talkWithNPC\0onPushExitButtonClicked\0"
    "onPushInventoryButtonClicked\0"
    "onPushCharListButtonClicked\0"
    "onPushLoadButtonClicked\0"
    "receivedSignalDialogWithNPC\0"
    "receivedSignalExitDialogWithNPC\0"
    "recaivedSouth\0recaivedNorth\0recaivedEast\0"
    "recaivedWest"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Game[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    0,   91,    2, 0x06 /* Public */,
       5,    0,   92,    2, 0x06 /* Public */,
       6,    0,   93,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    0,   99,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x0a /* Public */,
      14,    0,  101,    2, 0x0a /* Public */,
      15,    0,  102,    2, 0x0a /* Public */,
      16,    0,  103,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Game::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Game *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->exit(); break;
        case 1: _t->charList(); break;
        case 2: _t->inventory(); break;
        case 3: _t->loadGame(); break;
        case 4: _t->talkWithNPC(); break;
        case 5: _t->onPushExitButtonClicked(); break;
        case 6: _t->onPushInventoryButtonClicked(); break;
        case 7: _t->onPushCharListButtonClicked(); break;
        case 8: _t->onPushLoadButtonClicked(); break;
        case 9: _t->receivedSignalDialogWithNPC(); break;
        case 10: _t->receivedSignalExitDialogWithNPC(); break;
        case 11: _t->recaivedSouth(); break;
        case 12: _t->recaivedNorth(); break;
        case 13: _t->recaivedEast(); break;
        case 14: _t->recaivedWest(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Game::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Game::exit)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Game::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Game::charList)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Game::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Game::inventory)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Game::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Game::loadGame)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Game::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Game::talkWithNPC)) {
                *result = 4;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Game::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Game.data,
    qt_meta_data_Game,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Game::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Game::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Game.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Game::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Game::exit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Game::charList()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Game::inventory()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Game::loadGame()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Game::talkWithNPC()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
