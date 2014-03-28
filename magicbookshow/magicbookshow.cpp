#include <QtGui/QApplication>
#include <QtCore>
#include "ui_maindialog.h"
#include "homeview.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    //使用utf-8编码
    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf-8"));
    //Q_INIT_RESOURCE(myresource);
//    MainDialog *dialog = new MainDialog;

//    //设置全屏显示
//    dialog->showFullScreen();
//    dialog->show();
        HomeView w;

        w.resize(1024, 768);
        //w.showFullScreen();
        w.show();

        //return app.exec();
        int ret = app.exec();
        //ret = 773;
        //app.exit(773);
        if (ret == 773) {
            QProcess::startDetached(app.applicationFilePath(), QStringList());
            return 0;
        }
    return ret;
}
