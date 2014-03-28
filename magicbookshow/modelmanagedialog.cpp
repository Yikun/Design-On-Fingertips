#include "modelmanagedialog.h"
#include "ui_modelmanagedialog.h"
#include<QtCore>
#include <QDomDocument>
#include <QDomElement>
#include <QDomAttr>
#include <QFile>
ModelManageDialog::ModelManageDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    readmodelXML("./res/model/conf.xml");
    QStringList headers;
    headers<< "Model ID" << "Model Name" << "Model Price"<< "Mesh"<<"Testure"<<"preview";
    tableWidget->setHorizontalHeaderLabels(headers);
    tableWidget->verticalHeader()->setResizeMode(QHeaderView::Stretch);
    tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    //frame->setStyleSheet("background-image:url(./res/1.jpg)");
    connect(tableWidget, SIGNAL(clicked(QModelIndex)), SLOT(selectItem(QModelIndex)));
}
void ModelManageDialog::selectItem(QModelIndex current)
{
    //QTextStream cout(stdout, QIODevice::WriteOnly);
    //cout<<current.column()<<endl;//第X列
    //cout<<current.row()<<endl;//第X行
    idEdit->setText(tableWidget->item(current.row(),0)->text());
    nameEdit->setText(tableWidget->item(current.row(),1)->text());
    priceEdit->setText(tableWidget->item(current.row(),2)->text());
    meshEdit->setText(tableWidget->item(current.row(),3)->text());
    textEdit->setText(tableWidget->item(current.row(),4)->text());
    previewEdit->setText(tableWidget->item(current.row(),5)->text());
    frame->setStyleSheet("background-image:url(./res/model/"+tableWidget->item(current.row(),5)->text()+")");
    //    for(int i=0;i<tableWidget->rowCount();++i)
//    cout<<tableWidget->item(current.row(),i)->text()<<endl;
    //cout<<tableWidget->item(current.row(),1)->text()<<endl;



}
void ModelManageDialog::readmodelXML(const char *filename)
{
    if( NULL == filename )
        return;

    QFile file( filename );
    if( !file.open(QFile::ReadOnly | QFile::Text) ) {
        printf( "open file '%s' failed, error: %s !\n", filename, file.errorString().toStdString().c_str() );
        return;
    }

    QDomDocument	document;
    QString			strError;
    int				errLin = 0, errCol = 0;
    if( !document.setContent(&file, false, &strError, &errLin, &errCol) ) {
        printf( "parse file failed at line %d column %d, error: %s !\n", errLin, errCol, &strError );
        return;
    }

    if( document.isNull() ) {
        printf( "document is null !\n" );
        return;
    }

    QDomElement root = document.documentElement();
    printf( "%s ", root.tagName().toStdString().c_str() );//config
//    if( root.hasAttribute("name") )
//        ;//printf( "%s\n", root.attributeNode("name").value().toStdString().c_str() );

    QDomElement files = root.firstChildElement();
    if( files.isNull() )
        return;
    else
        printf( "\t%s\n", files.tagName().toStdString().c_str() );//model

    QDomElement element = root.firstChildElement();//files.firstChildElement();
    int tabrows=0;
    while( !element.isNull() ) {
        tableWidget->setRowCount(tabrows+1);
        tableWidget->setColumnCount(6);
        if(element.nodeName()=="model")
        {
            //只对model节点进行处理
            if( element.hasAttribute("id") )
            {
                tableWidget->setItem(tabrows, 0, new QTableWidgetItem(element.attributeNode("id").value()));
                //printf( "id: %s", element.attributeNode("id").value().toStdString().c_str() );
            }
            if( element.hasAttribute("name") )
                tableWidget->setItem(tabrows, 1, new QTableWidgetItem(element.attributeNode("name").value()));
                //printf( " | name: %s", element.attributeNode("name").value().toStdString().c_str() );
            if( element.hasAttribute("price") )
                tableWidget->setItem(tabrows, 2, new QTableWidgetItem(element.attributeNode("price").value()));
                //printf( " | price: %s", element.attributeNode("price").value().toStdString().c_str() );
            if( element.hasAttribute("mesh") )
                tableWidget->setItem(tabrows, 3, new QTableWidgetItem(element.attributeNode("mesh").value()));
                //printf( " | mesh: %s", element.attributeNode("mesh").value().toStdString().c_str() );
            if( element.hasAttribute("texture") )
                tableWidget->setItem(tabrows, 4, new QTableWidgetItem(element.attributeNode("texture").value()));
                //printf( " | texture: %s", element.attributeNode("texture").value().toStdString().c_str() );
            if( element.hasAttribute("preview") )
                tableWidget->setItem(tabrows, 5, new QTableWidgetItem(element.attributeNode("preview").value()));
                //printf( " | preview: %s", element.attributeNode("preview").value().toStdString().c_str() );
            printf( "\n" );

        }
        //QListWidgetItem *itm = new QListWidgetItem("test");

         element = element.nextSiblingElement();
        tabrows++;
        //listWidget->addItem(itm);
        //listWidget->addItems();
    }
}

