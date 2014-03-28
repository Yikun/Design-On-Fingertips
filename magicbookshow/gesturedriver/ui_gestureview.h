/********************************************************************************
** Form generated from reading UI file 'gestureview.ui'
**
** Created: Sat Jul 14 10:31:54 2012
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTUREVIEW_H
#define UI_GESTUREVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GestureView
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *writeButton;
    QLabel *label;
    QTextBrowser *textBrowser;
    QPushButton *setButton;
    QSpacerItem *horizontalSpacer;
    QGroupBox *settingBox;
    QFormLayout *formLayout;
    QLabel *label_3;
    QPushButton *openButton;
    QLabel *label_5;
    QComboBox *portNamecomboBox;
    QLabel *label_4;
    QComboBox *baudRatecomboBox;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *GestureView)
    {
        if (GestureView->objectName().isEmpty())
            GestureView->setObjectName(QString::fromUtf8("GestureView"));
        GestureView->resize(583, 338);
        centralwidget = new QWidget(GestureView);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        writeButton = new QPushButton(centralwidget);
        writeButton->setObjectName(QString::fromUtf8("writeButton"));

        gridLayout->addWidget(writeButton, 1, 1, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout->addWidget(textBrowser, 3, 0, 1, 1);

        setButton = new QPushButton(centralwidget);
        setButton->setObjectName(QString::fromUtf8("setButton"));

        gridLayout->addWidget(setButton, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 3, 1, 1);

        settingBox = new QGroupBox(centralwidget);
        settingBox->setObjectName(QString::fromUtf8("settingBox"));
        formLayout = new QFormLayout(settingBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_3 = new QLabel(settingBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        openButton = new QPushButton(settingBox);
        openButton->setObjectName(QString::fromUtf8("openButton"));

        formLayout->setWidget(0, QFormLayout::FieldRole, openButton);

        label_5 = new QLabel(settingBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_5);

        portNamecomboBox = new QComboBox(settingBox);
        portNamecomboBox->setObjectName(QString::fromUtf8("portNamecomboBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, portNamecomboBox);

        label_4 = new QLabel(settingBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        baudRatecomboBox = new QComboBox(settingBox);
        baudRatecomboBox->setObjectName(QString::fromUtf8("baudRatecomboBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, baudRatecomboBox);


        gridLayout->addWidget(settingBox, 0, 3, 4, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 3, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        GestureView->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GestureView);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 583, 25));
        GestureView->setMenuBar(menubar);
        statusbar = new QStatusBar(GestureView);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        GestureView->setStatusBar(statusbar);
        toolBar = new QToolBar(GestureView);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        GestureView->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(GestureView);
        QObject::connect(setButton, SIGNAL(toggled(bool)), settingBox, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(GestureView);
    } // setupUi

    void retranslateUi(QMainWindow *GestureView)
    {
        GestureView->setWindowTitle(QApplication::translate("GestureView", "GestureHome", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("GestureView", "Write Com", 0, QApplication::UnicodeUTF8));
        writeButton->setText(QApplication::translate("GestureView", "Write Data", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GestureView", "Read Com", 0, QApplication::UnicodeUTF8));
        setButton->setText(QApplication::translate("GestureView", "&Settings", 0, QApplication::UnicodeUTF8));
        settingBox->setTitle(QApplication::translate("GestureView", "More Setting", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("GestureView", "Port Status", 0, QApplication::UnicodeUTF8));
        openButton->setText(QApplication::translate("GestureView", "open", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("GestureView", "PortName", 0, QApplication::UnicodeUTF8));
        portNamecomboBox->clear();
        portNamecomboBox->insertItems(0, QStringList()
         << QApplication::translate("GestureView", "ttyPCH0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GestureView", "ttyPCH1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GestureView", "ttyUSB0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GestureView", "ttyUSB1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GestureView", "ttyUSB2", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("GestureView", "BaudRate", 0, QApplication::UnicodeUTF8));
        baudRatecomboBox->clear();
        baudRatecomboBox->insertItems(0, QStringList()
         << QApplication::translate("GestureView", "9600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GestureView", "115200", 0, QApplication::UnicodeUTF8)
        );
        toolBar->setWindowTitle(QApplication::translate("GestureView", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GestureView: public Ui_GestureView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTUREVIEW_H
