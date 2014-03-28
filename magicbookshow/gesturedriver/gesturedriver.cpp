
#include <QtGui/QApplication>
#include <QtCore>
#include "qextserialport/posix_qextserialport.h"
#include "gestureview.h"
//全局变量串口类
Posix_QextSerialPort *myCom;
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));
    GestureView *gestureview=new GestureView;
    gestureview->showFullScreen();
    return app.exec();
}
