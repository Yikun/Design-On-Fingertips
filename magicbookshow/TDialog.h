#ifndef TDIALOG_H
#define TDIALOG_H
#include <QDialog>
#include "ui_dialog.h"
class Tdialog : public QDialog, public Ui::Dialog
{
    Q_OBJECT

public:
    Tdialog(QWidget *parent = 0);


private:

private slots:
    void show();

};
#endif // TDIALOG_H
