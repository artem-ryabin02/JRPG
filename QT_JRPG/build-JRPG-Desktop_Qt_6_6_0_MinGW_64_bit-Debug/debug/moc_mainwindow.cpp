/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../JRPG/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "wPress",
    "",
    "aPress",
    "sPress",
    "dPress",
    "onButtonExitClicked",
    "onButtonNewGameClicked",
    "onButtonLoadGameClicked",
    "onButtonInvetoryClicked",
    "onButtonCharListClicked",
    "returnFromCharList",
    "recTalk",
    "recGoodbye",
    "recEnemy",
    "returnFromBattleArena"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[11];
    char stringdata1[7];
    char stringdata2[1];
    char stringdata3[7];
    char stringdata4[7];
    char stringdata5[7];
    char stringdata6[20];
    char stringdata7[23];
    char stringdata8[24];
    char stringdata9[24];
    char stringdata10[24];
    char stringdata11[19];
    char stringdata12[8];
    char stringdata13[11];
    char stringdata14[9];
    char stringdata15[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 6),  // "wPress"
        QT_MOC_LITERAL(18, 0),  // ""
        QT_MOC_LITERAL(19, 6),  // "aPress"
        QT_MOC_LITERAL(26, 6),  // "sPress"
        QT_MOC_LITERAL(33, 6),  // "dPress"
        QT_MOC_LITERAL(40, 19),  // "onButtonExitClicked"
        QT_MOC_LITERAL(60, 22),  // "onButtonNewGameClicked"
        QT_MOC_LITERAL(83, 23),  // "onButtonLoadGameClicked"
        QT_MOC_LITERAL(107, 23),  // "onButtonInvetoryClicked"
        QT_MOC_LITERAL(131, 23),  // "onButtonCharListClicked"
        QT_MOC_LITERAL(155, 18),  // "returnFromCharList"
        QT_MOC_LITERAL(174, 7),  // "recTalk"
        QT_MOC_LITERAL(182, 10),  // "recGoodbye"
        QT_MOC_LITERAL(193, 8),  // "recEnemy"
        QT_MOC_LITERAL(202, 21)   // "returnFromBattleArena"
    },
    "MainWindow",
    "wPress",
    "",
    "aPress",
    "sPress",
    "dPress",
    "onButtonExitClicked",
    "onButtonNewGameClicked",
    "onButtonLoadGameClicked",
    "onButtonInvetoryClicked",
    "onButtonCharListClicked",
    "returnFromCharList",
    "recTalk",
    "recGoodbye",
    "recEnemy",
    "returnFromBattleArena"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x06,    1 /* Public */,
       3,    0,   99,    2, 0x06,    2 /* Public */,
       4,    0,  100,    2, 0x06,    3 /* Public */,
       5,    0,  101,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,  102,    2, 0x08,    5 /* Private */,
       7,    0,  103,    2, 0x08,    6 /* Private */,
       8,    0,  104,    2, 0x08,    7 /* Private */,
       9,    0,  105,    2, 0x08,    8 /* Private */,
      10,    0,  106,    2, 0x08,    9 /* Private */,
      11,    0,  107,    2, 0x08,   10 /* Private */,
      12,    0,  108,    2, 0x08,   11 /* Private */,
      13,    0,  109,    2, 0x08,   12 /* Private */,
      14,    0,  110,    2, 0x08,   13 /* Private */,
      15,    0,  111,    2, 0x08,   14 /* Private */,

 // signals: parameters
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

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'wPress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'aPress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sPress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'dPress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonExitClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonNewGameClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonLoadGameClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonInvetoryClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonCharListClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'returnFromCharList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'recTalk'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'recGoodbye'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'recEnemy'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'returnFromBattleArena'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->wPress(); break;
        case 1: _t->aPress(); break;
        case 2: _t->sPress(); break;
        case 3: _t->dPress(); break;
        case 4: _t->onButtonExitClicked(); break;
        case 5: _t->onButtonNewGameClicked(); break;
        case 6: _t->onButtonLoadGameClicked(); break;
        case 7: _t->onButtonInvetoryClicked(); break;
        case 8: _t->onButtonCharListClicked(); break;
        case 9: _t->returnFromCharList(); break;
        case 10: _t->recTalk(); break;
        case 11: _t->recGoodbye(); break;
        case 12: _t->recEnemy(); break;
        case 13: _t->returnFromBattleArena(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::wPress; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::aPress; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::sPress; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::dPress; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::wPress()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::aPress()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::sPress()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::dPress()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
