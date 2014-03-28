#ifndef MODELMANAGEDIALOG_H
#define MODELMANAGEDIALOG_H
#include <QDialog>
#include <QCloseEvent>
#include "ui_modelmanagedialog.h"
class ModelManageDialog : public QDialog, public Ui::modelmanagedialog
{
    Q_OBJECT

public:
    ModelManageDialog(QWidget *parent = 0);
private:
    void readmodelXML(const char *filename);
public slots:
    void selectItem(QModelIndex current);
};
#endif // MODELMANAGEDIALOG_H
