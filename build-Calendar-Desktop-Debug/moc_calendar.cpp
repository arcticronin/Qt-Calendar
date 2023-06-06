/****************************************************************************
** Meta object code from reading C++ file 'calendar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Calendar/calendar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calendar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Calendar_t {
    QByteArrayData data[15];
    char stringdata0[393];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Calendar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Calendar_t qt_meta_stringdata_Calendar = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Calendar"
QT_MOC_LITERAL(1, 9, 34), // "on_calendarWidget_selectionCh..."
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(4, 67, 38), // "on_comboBox_evento_currentInd..."
QT_MOC_LITERAL(5, 106, 5), // "index"
QT_MOC_LITERAL(6, 112, 30), // "on_pushButton_nextPage_clicked"
QT_MOC_LITERAL(7, 143, 34), // "on_pushButton_previousPage_cl..."
QT_MOC_LITERAL(8, 178, 30), // "on_pushButton_delete_1_clicked"
QT_MOC_LITERAL(9, 209, 30), // "on_pushButton_delete_2_clicked"
QT_MOC_LITERAL(10, 240, 30), // "on_pushButton_delete_3_clicked"
QT_MOC_LITERAL(11, 271, 28), // "on_pushButton_edit_1_clicked"
QT_MOC_LITERAL(12, 300, 28), // "on_pushButton_edit_2_clicked"
QT_MOC_LITERAL(13, 329, 28), // "on_pushButton_edit_3_clicked"
QT_MOC_LITERAL(14, 358, 34) // "on_pushButton_confirm_edit_cl..."

    },
    "Calendar\0on_calendarWidget_selectionChanged\0"
    "\0on_pushButton_clicked\0"
    "on_comboBox_evento_currentIndexChanged\0"
    "index\0on_pushButton_nextPage_clicked\0"
    "on_pushButton_previousPage_clicked\0"
    "on_pushButton_delete_1_clicked\0"
    "on_pushButton_delete_2_clicked\0"
    "on_pushButton_delete_3_clicked\0"
    "on_pushButton_edit_1_clicked\0"
    "on_pushButton_edit_2_clicked\0"
    "on_pushButton_edit_3_clicked\0"
    "on_pushButton_confirm_edit_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Calendar[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    1,   76,    2, 0x08 /* Private */,
       6,    0,   79,    2, 0x08 /* Private */,
       7,    0,   80,    2, 0x08 /* Private */,
       8,    0,   81,    2, 0x08 /* Private */,
       9,    0,   82,    2, 0x08 /* Private */,
      10,    0,   83,    2, 0x08 /* Private */,
      11,    0,   84,    2, 0x08 /* Private */,
      12,    0,   85,    2, 0x08 /* Private */,
      13,    0,   86,    2, 0x08 /* Private */,
      14,    0,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
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

void Calendar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Calendar *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_calendarWidget_selectionChanged(); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_comboBox_evento_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_pushButton_nextPage_clicked(); break;
        case 4: _t->on_pushButton_previousPage_clicked(); break;
        case 5: _t->on_pushButton_delete_1_clicked(); break;
        case 6: _t->on_pushButton_delete_2_clicked(); break;
        case 7: _t->on_pushButton_delete_3_clicked(); break;
        case 8: _t->on_pushButton_edit_1_clicked(); break;
        case 9: _t->on_pushButton_edit_2_clicked(); break;
        case 10: _t->on_pushButton_edit_3_clicked(); break;
        case 11: _t->on_pushButton_confirm_edit_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Calendar::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Calendar.data,
    qt_meta_data_Calendar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Calendar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Calendar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Calendar.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Calendar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
