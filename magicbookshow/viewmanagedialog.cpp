#include "viewmanagedialog.h"
#include "ui_viewmanagedialog.h"
#include<QtCore>
#include<QtGui>
#include <QDomDocument>
#include <QDomElement>
#include <QDomAttr>
#include <QFile>

#include "roomscene.h"
ViewManageDialog::ViewManageDialog(QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    readmodelXML("./res/model/sceneconf.xml");
    QStringList headers;
    headers<< "Scene ID" << "Scene Pat" << "Scene Model" << "Scene Texture"<<"Scene1"<<"Scene2"<<"Scene3";
    tableWidget->setHorizontalHeaderLabels(headers);
    tableWidget->verticalHeader()->setResizeMode(QHeaderView::Stretch);
    tableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);

    connect(tableWidget, SIGNAL(clicked(QModelIndex)), SLOT(selectItem(QModelIndex)));
    connect(enterButton, SIGNAL(clicked()), SLOT(showcustomscene()));
}
void ViewManageDialog::showcustomscene()
{
    Roomscene *m_roomselect = new Roomscene;
    m_roomselect->show("./test.irr");
}
void ViewManageDialog::selectItem(QModelIndex current)
{
    //QTextStream cout(stdout, QIODevice::WriteOnly);
    //cout<<current.column()<<endl;//第X列
    //cout<<current.row()<<endl;//第X行

    idEdit->setText(tableWidget->item(current.row(),0)->text());
    patEdit->setText(tableWidget->item(current.row(),1)->text());
    modelEdit->setText(tableWidget->item(current.row(),2)->text());
    textureEdit->setText(tableWidget->item(current.row(),3)->text());
    scene1Edit->setText(tableWidget->item(current.row(),4)->text());
    scene2Edit->setText(tableWidget->item(current.row(),5)->text());
    scene3Edit->setText(tableWidget->item(current.row(),6)->text());
    frame_2->setStyleSheet("background-image:url(./res/1.png)");
    if(current.row()==0)
    {
        frame->setStyleSheet("background-image:url(./res/preview/1.png)");
        frame_2->setStyleSheet("background-image:url(./res/preview/2.png)");
        frame_3->setStyleSheet("background-image:url(./res/preview/3.png)");
    }else if(current.row()==1)
    {
        frame->setStyleSheet("background-image:url(./res/preview/4.png)");
        frame_2->setStyleSheet("background-image:url(./res/preview/5.png)");
        frame_3->setStyleSheet("background-image:url(./res/preview/6.png)");
    }
    //frame->setStyleSheet("background-image:url(./res/model/"+tableWidget->item(current.row(),5)->text()+")");
    //    for(int i=0;i<tableWidget->rowCount();++i)
//    cout<<tableWidget->item(current.row(),i)->text()<<endl;
    //cout<<tableWidget->item(current.row(),1)->text()<<endl;



}
void ViewManageDialog::readmodelXML(const char *filename)
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
        tableWidget->setColumnCount(7);
        if(element.nodeName()=="scene")
        {
            //headers<< "Scene ID" << "Scene Pat" << "Scene Model" << "Scene Texture"<<"Scene1"<<"Scene2"<<"Scene3";
            //只对model节点进行处理
            if( element.hasAttribute("id") )
            {
                tableWidget->setItem(tabrows, 0, new QTableWidgetItem(element.attributeNode("id").value()));
                //printf( "id: %s", element.attributeNode("id").value().toStdString().c_str() );
            }
            if( element.hasAttribute("pat") )
                tableWidget->setItem(tabrows, 1, new QTableWidgetItem(element.attributeNode("pat").value()));
                //printf( " | name: %s", element.attributeNode("name").value().toStdString().c_str() );
            if( element.hasAttribute("scenemodel") )
                tableWidget->setItem(tabrows, 2, new QTableWidgetItem(element.attributeNode("scenemodel").value()));
                //printf( " | price: %s", element.attributeNode("price").value().toStdString().c_str() );
            if( element.hasAttribute("scenetexture") )
                tableWidget->setItem(tabrows, 3, new QTableWidgetItem(element.attributeNode("scenetexture").value()));
                //printf( " | mesh: %s", element.attributeNode("mesh").value().toStdString().c_str() );
            if( element.hasAttribute("scene1") )
                tableWidget->setItem(tabrows, 4, new QTableWidgetItem(element.attributeNode("scene1").value()));
                //printf( " | texture: %s", element.attributeNode("texture").value().toStdString().c_str() );
            if( element.hasAttribute("scene2") )
                tableWidget->setItem(tabrows, 5, new QTableWidgetItem(element.attributeNode("scene2").value()));
            if( element.hasAttribute("scene3") )
                tableWidget->setItem(tabrows, 6, new QTableWidgetItem(element.attributeNode("scene3").value()));
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




