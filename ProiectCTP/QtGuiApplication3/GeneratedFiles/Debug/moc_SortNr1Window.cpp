/****************************************************************************
** Meta object code from reading C++ file 'SortNr1Window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../SortNr1Window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SortNr1Window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SortNr1Window_t {
    QByteArrayData data[9];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SortNr1Window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SortNr1Window_t qt_meta_stringdata_SortNr1Window = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SortNr1Window"
QT_MOC_LITERAL(1, 14, 11), // "donePressed"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "std::string"
QT_MOC_LITERAL(4, 39, 12), // "sortLineEdit"
QT_MOC_LITERAL(5, 52, 13), // "sortLineEdit1"
QT_MOC_LITERAL(6, 66, 13), // "SrotLineedit2"
QT_MOC_LITERAL(7, 80, 13), // "SortLineedit3"
QT_MOC_LITERAL(8, 94, 13) // "SortLineedit4"

    },
    "SortNr1Window\0donePressed\0\0std::string\0"
    "sortLineEdit\0sortLineEdit1\0SrotLineedit2\0"
    "SortLineedit3\0SortLineedit4"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SortNr1Window[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3,    4,    5,    6,    7,    8,

       0        // eod
};

void SortNr1Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SortNr1Window *_t = static_cast<SortNr1Window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->donePressed((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< std::string(*)>(_a[2])),(*reinterpret_cast< std::string(*)>(_a[3])),(*reinterpret_cast< std::string(*)>(_a[4])),(*reinterpret_cast< std::string(*)>(_a[5]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SortNr1Window::*_t)(std::string , std::string , std::string , std::string , std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SortNr1Window::donePressed)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject SortNr1Window::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SortNr1Window.data,
      qt_meta_data_SortNr1Window,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SortNr1Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SortNr1Window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SortNr1Window.stringdata0))
        return static_cast<void*>(const_cast< SortNr1Window*>(this));
    return QWidget::qt_metacast(_clname);
}

int SortNr1Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void SortNr1Window::donePressed(std::string _t1, std::string _t2, std::string _t3, std::string _t4, std::string _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
