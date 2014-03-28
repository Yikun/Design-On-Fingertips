#ifndef VIEWMANAGEDIALOG_H
#define VIEWMANAGEDIALOG_H
#include <QDialog>
#include <QCloseEvent>
#include "ui_viewmanagedialog.h"
class ViewManageDialog : public QDialog, public Ui::ViewManageDialog
{
    Q_OBJECT

public:
    ViewManageDialog(QWidget *parent = 0);

private:
    void readmodelXML(const char *filename);
public slots:
    void selectItem(QModelIndex current);
    void showcustomscene();
};
#endif // VIEWMANAGEDIALOG_H
