/****************************************************************************
** Meta object code from reading C++ file 'PluriNotes.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../PluriNotes/PluriNotes.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PluriNotes.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PluriNotes_t {
    QByteArrayData data[7];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PluriNotes_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PluriNotes_t qt_meta_stringdata_PluriNotes = {
    {
QT_MOC_LITERAL(0, 0, 10), // "PluriNotes"
QT_MOC_LITERAL(1, 11, 12), // "ouvrirProjet"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 10), // "ouvrirNote"
QT_MOC_LITERAL(4, 36, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(5, 53, 4), // "item"
QT_MOC_LITERAL(6, 58, 12) // "nouvelleNote"

    },
    "PluriNotes\0ouvrirProjet\0\0ouvrirNote\0"
    "QListWidgetItem*\0item\0nouvelleNote"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PluriNotes[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    1,   30,    2, 0x0a /* Public */,
       6,    0,   33,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,

       0        // eod
};

void PluriNotes::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PluriNotes *_t = static_cast<PluriNotes *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ouvrirProjet(); break;
        case 1: _t->ouvrirNote((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->nouvelleNote(); break;
        default: ;
        }
    }
}

const QMetaObject PluriNotes::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_PluriNotes.data,
      qt_meta_data_PluriNotes,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PluriNotes::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PluriNotes::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PluriNotes.stringdata0))
        return static_cast<void*>(const_cast< PluriNotes*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int PluriNotes::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE