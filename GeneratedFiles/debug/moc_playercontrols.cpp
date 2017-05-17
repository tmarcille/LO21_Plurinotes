/****************************************************************************
** Meta object code from reading C++ file 'playercontrols.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../playercontrols.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playercontrols.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlayerControls_t {
    QByteArrayData data[22];
    char stringdata0[226];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlayerControls_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlayerControls_t qt_meta_stringdata_PlayerControls = {
    {
QT_MOC_LITERAL(0, 0, 14), // "PlayerControls"
QT_MOC_LITERAL(1, 15, 4), // "play"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 5), // "pause"
QT_MOC_LITERAL(4, 27, 4), // "stop"
QT_MOC_LITERAL(5, 32, 12), // "changeVolume"
QT_MOC_LITERAL(6, 45, 6), // "volume"
QT_MOC_LITERAL(7, 52, 12), // "changeMuting"
QT_MOC_LITERAL(8, 65, 6), // "muting"
QT_MOC_LITERAL(9, 72, 10), // "changeRate"
QT_MOC_LITERAL(10, 83, 4), // "rate"
QT_MOC_LITERAL(11, 88, 8), // "setState"
QT_MOC_LITERAL(12, 97, 19), // "QMediaPlayer::State"
QT_MOC_LITERAL(13, 117, 5), // "state"
QT_MOC_LITERAL(14, 123, 9), // "setVolume"
QT_MOC_LITERAL(15, 133, 8), // "setMuted"
QT_MOC_LITERAL(16, 142, 5), // "muted"
QT_MOC_LITERAL(17, 148, 15), // "setPlaybackRate"
QT_MOC_LITERAL(18, 164, 11), // "playClicked"
QT_MOC_LITERAL(19, 176, 11), // "muteClicked"
QT_MOC_LITERAL(20, 188, 10), // "updateRate"
QT_MOC_LITERAL(21, 199, 26) // "onVolumeSliderValueChanged"

    },
    "PlayerControls\0play\0\0pause\0stop\0"
    "changeVolume\0volume\0changeMuting\0"
    "muting\0changeRate\0rate\0setState\0"
    "QMediaPlayer::State\0state\0setVolume\0"
    "setMuted\0muted\0setPlaybackRate\0"
    "playClicked\0muteClicked\0updateRate\0"
    "onVolumeSliderValueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlayerControls[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    0,   86,    2, 0x06 /* Public */,
       5,    1,   87,    2, 0x06 /* Public */,
       7,    1,   90,    2, 0x06 /* Public */,
       9,    1,   93,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   96,    2, 0x0a /* Public */,
      14,    1,   99,    2, 0x0a /* Public */,
      15,    1,  102,    2, 0x0a /* Public */,
      17,    1,  105,    2, 0x0a /* Public */,
      18,    0,  108,    2, 0x08 /* Private */,
      19,    0,  109,    2, 0x08 /* Private */,
      20,    0,  110,    2, 0x08 /* Private */,
      21,    0,  111,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::QReal,   10,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Float,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PlayerControls::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlayerControls *_t = static_cast<PlayerControls *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->play(); break;
        case 1: _t->pause(); break;
        case 2: _t->stop(); break;
        case 3: _t->changeVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->changeMuting((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->changeRate((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 6: _t->setState((*reinterpret_cast< QMediaPlayer::State(*)>(_a[1]))); break;
        case 7: _t->setVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setMuted((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->setPlaybackRate((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 10: _t->playClicked(); break;
        case 11: _t->muteClicked(); break;
        case 12: _t->updateRate(); break;
        case 13: _t->onVolumeSliderValueChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::State >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PlayerControls::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlayerControls::play)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (PlayerControls::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlayerControls::pause)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (PlayerControls::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlayerControls::stop)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (PlayerControls::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlayerControls::changeVolume)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (PlayerControls::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlayerControls::changeMuting)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (PlayerControls::*_t)(qreal );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PlayerControls::changeRate)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject PlayerControls::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PlayerControls.data,
      qt_meta_data_PlayerControls,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PlayerControls::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlayerControls::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PlayerControls.stringdata0))
        return static_cast<void*>(const_cast< PlayerControls*>(this));
    return QWidget::qt_metacast(_clname);
}

int PlayerControls::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void PlayerControls::play()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void PlayerControls::pause()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void PlayerControls::stop()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void PlayerControls::changeVolume(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PlayerControls::changeMuting(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PlayerControls::changeRate(qreal _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
