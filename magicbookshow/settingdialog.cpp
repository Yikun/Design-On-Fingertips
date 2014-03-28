#include <QtGui>
//X11支持 -lXtst
#include <X11/extensions/XTest.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/keysymdef.h>

#include <QX11Info>
#include "settingdialog.h"
SettingDialog::SettingDialog(QWidget *parent)
    : QDialog(parent)
{
//initUI
    //载入UI
    setupUi(this);

    //隐藏更多信息
    recivegroupBox->hide();

    layout()->setSizeConstraint(QLayout::SetFixedSize);

    //关闭Dialog后自动释放
    setAttribute(Qt::WA_DeleteOnClose);

}


void SettingDialog::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this, tr("Quit Settings"),
        QString(tr("Quit and Save？")),
        QMessageBox::Yes | QMessageBox::No);

    if (button == QMessageBox::No) {
        event->ignore();  //忽略退出信号，程序继续运行
    }
    else if (button == QMessageBox::Yes) {
        event->accept();  //接受退出信号，程序退出
        this->close();
    }
}

void SettingDialog::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_D)
        printf("press Key D in Setting");
    event->accept();
}
