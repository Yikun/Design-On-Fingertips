#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H
#include <QDialog>
#include <QCloseEvent>
#include "ui_settingdialog.h"
class SettingDialog : public QDialog, public Ui::SettingDialog
{
    Q_OBJECT

public:
    SettingDialog(QWidget *parent = 0);
    void closeEvent(QCloseEvent *event);
    void keyPressEvent(QKeyEvent *event);

};
#endif // SETTINGDIALOG_H
