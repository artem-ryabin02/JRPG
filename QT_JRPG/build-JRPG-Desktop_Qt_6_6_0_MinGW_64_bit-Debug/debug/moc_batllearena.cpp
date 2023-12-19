/****************************************************************************
** Meta object code from reading C++ file 'batllearena.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../JRPG/batllearena.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'batllearena.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSBatlleArenaENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSBatlleArenaENDCLASS = QtMocHelpers::stringData(
    "BatlleArena",
    "escape",
    "",
    "win",
    "loose",
    "onButtonClickAttack",
    "onButtonClickDefense",
    "onButtonClickItem",
    "onButtonClickSkill",
    "onButtonClickEscape"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSBatlleArenaENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[12];
    char stringdata1[7];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[6];
    char stringdata5[20];
    char stringdata6[21];
    char stringdata7[18];
    char stringdata8[19];
    char stringdata9[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSBatlleArenaENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSBatlleArenaENDCLASS_t qt_meta_stringdata_CLASSBatlleArenaENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "BatlleArena"
        QT_MOC_LITERAL(12, 6),  // "escape"
        QT_MOC_LITERAL(19, 0),  // ""
        QT_MOC_LITERAL(20, 3),  // "win"
        QT_MOC_LITERAL(24, 5),  // "loose"
        QT_MOC_LITERAL(30, 19),  // "onButtonClickAttack"
        QT_MOC_LITERAL(50, 20),  // "onButtonClickDefense"
        QT_MOC_LITERAL(71, 17),  // "onButtonClickItem"
        QT_MOC_LITERAL(89, 18),  // "onButtonClickSkill"
        QT_MOC_LITERAL(108, 19)   // "onButtonClickEscape"
    },
    "BatlleArena",
    "escape",
    "",
    "win",
    "loose",
    "onButtonClickAttack",
    "onButtonClickDefense",
    "onButtonClickItem",
    "onButtonClickSkill",
    "onButtonClickEscape"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSBatlleArenaENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x06,    1 /* Public */,
       3,    0,   63,    2, 0x06,    2 /* Public */,
       4,    0,   64,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   65,    2, 0x08,    4 /* Private */,
       6,    0,   66,    2, 0x08,    5 /* Private */,
       7,    0,   67,    2, 0x08,    6 /* Private */,
       8,    0,   68,    2, 0x08,    7 /* Private */,
       9,    0,   69,    2, 0x08,    8 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject BatlleArena::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSBatlleArenaENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSBatlleArenaENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSBatlleArenaENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<BatlleArena, std::true_type>,
        // method 'escape'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'win'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loose'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonClickAttack'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonClickDefense'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonClickItem'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonClickSkill'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onButtonClickEscape'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void BatlleArena::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BatlleArena *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->escape(); break;
        case 1: _t->win(); break;
        case 2: _t->loose(); break;
        case 3: _t->onButtonClickAttack(); break;
        case 4: _t->onButtonClickDefense(); break;
        case 5: _t->onButtonClickItem(); break;
        case 6: _t->onButtonClickSkill(); break;
        case 7: _t->onButtonClickEscape(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BatlleArena::*)();
            if (_t _q_method = &BatlleArena::escape; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BatlleArena::*)();
            if (_t _q_method = &BatlleArena::win; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BatlleArena::*)();
            if (_t _q_method = &BatlleArena::loose; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *BatlleArena::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BatlleArena::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSBatlleArenaENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int BatlleArena::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void BatlleArena::escape()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void BatlleArena::win()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void BatlleArena::loose()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
