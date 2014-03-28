/****************************************************************************
** Meta object code from reading C++ file 'gestureview.h'
**
** Created: Sat Jul 14 10:32:00 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gestureview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gestureview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GestureView[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      23,   12,   12,   12, 0x08,
      34,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GestureView[] = {
    "GestureView\0\0readCom()\0writeCom()\0"
    "openserialport()\0"
};

const QMetaObject GestureView::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GestureView,
      qt_meta_data_GestureView, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GestureView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GestureView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GestureView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GestureView))
        return static_cast<void*>(const_cast< GestureView*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int GestureView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: readCom(); break;
        case 1: writeCom(); break;
        case 2: openserialport(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
