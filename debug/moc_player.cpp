/****************************************************************************
** Meta object code from reading C++ file 'player.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../player.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'player.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VideoPlayer_t {
    QByteArrayData data[13];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoPlayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoPlayer_t qt_meta_stringdata_VideoPlayer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "VideoPlayer"
QT_MOC_LITERAL(1, 12, 11), // "fileChanged"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 4), // "play"
QT_MOC_LITERAL(4, 30, 17), // "mediaStateChanged"
QT_MOC_LITERAL(5, 48, 19), // "QMediaPlayer::State"
QT_MOC_LITERAL(6, 68, 5), // "state"
QT_MOC_LITERAL(7, 74, 15), // "positionChanged"
QT_MOC_LITERAL(8, 90, 8), // "position"
QT_MOC_LITERAL(9, 99, 15), // "durationChanged"
QT_MOC_LITERAL(10, 115, 8), // "duration"
QT_MOC_LITERAL(11, 124, 11), // "setPosition"
QT_MOC_LITERAL(12, 136, 11) // "handleError"

    },
    "VideoPlayer\0fileChanged\0\0play\0"
    "mediaStateChanged\0QMediaPlayer::State\0"
    "state\0positionChanged\0position\0"
    "durationChanged\0duration\0setPosition\0"
    "handleError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoPlayer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x0a /* Public */,
       4,    1,   51,    2, 0x08 /* Private */,
       7,    1,   54,    2, 0x08 /* Private */,
       9,    1,   57,    2, 0x08 /* Private */,
      11,    1,   60,    2, 0x08 /* Private */,
      12,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::LongLong,    8,
    QMetaType::Void, QMetaType::LongLong,   10,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,

       0        // eod
};

void VideoPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VideoPlayer *_t = static_cast<VideoPlayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fileChanged(); break;
        case 1: _t->play(); break;
        case 2: _t->mediaStateChanged((*reinterpret_cast< QMediaPlayer::State(*)>(_a[1]))); break;
        case 3: _t->positionChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 4: _t->durationChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 5: _t->setPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->handleError(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
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
            typedef void (VideoPlayer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VideoPlayer::fileChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject VideoPlayer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_VideoPlayer.data,
      qt_meta_data_VideoPlayer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VideoPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VideoPlayer.stringdata0))
        return static_cast<void*>(const_cast< VideoPlayer*>(this));
    return QWidget::qt_metacast(_clname);
}

int VideoPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void VideoPlayer::fileChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
