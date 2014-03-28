
#include <QtGui>
#include "TDialog.h"
#include "maindialog.h"
#include "roomscene.h"
Tdialog::Tdialog(QWidget *parent)
    : QDialog(parent)
{
//initUI
    //载入UI
    setupUi(this);
    connect(pushButton,SIGNAL(clicked()),this,SLOT(show()));
    setAttribute(Qt::WA_DeleteOnClose);
}

void Tdialog::show()
{
    printf("test!!!");
    setVisible(false);
    Roomscene *test=new Roomscene;

    test->showselect();
    //if (test->sceneid)
        test->show("./test.irr");
    setVisible(true);
}
