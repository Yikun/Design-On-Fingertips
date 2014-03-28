#ifndef GESTUREVIEW_H
#define GESTUREVIEW_H
#include <QMainWindow>
//串口相关
#include "qextserialport/posix_qextserialport.h"
#include <QtCore>
#include <QtGui>
namespace Ui {
class GestureView;
}

class GestureView : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit GestureView(QWidget *parent = 0);
    ~GestureView();
    
private:
    Ui::GestureView *ui;
private slots:
    void readCom();
    void writeCom();
    void openserialport();
private:
    void sendKey(unsigned int keycode);
    Display *display;


};
extern Posix_QextSerialPort *myCom;
#endif // GESTUREVIEW_H
