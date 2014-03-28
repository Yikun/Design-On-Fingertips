#include "gestureview.h"
#include "ui_gestureview.h"

#include <X11/extensions/XTest.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/keysymdef.h>

#include <QX11Info>
GestureView::GestureView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GestureView)
{
//    QSound bells("/home/kero/workspace/magicbookshow/gesturedriver/startup.wav");
//    bells.play();
//    if(QSound::isAvailable()){
//                QSound::play("/home/kero/workspace/magicbookshow/gesturedriver/startup.wav");
//                qDebug()<<"available";
//            }
//            else
//                qDebug()<<"unavailable";


    ui->setupUi(this);
    ui->settingBox->setHidden(true);
    //串口初始化
    myCom = new Posix_QextSerialPort("/dev/ttyPCH1",QextSerialBase::Polling);

    //定义串口对象，并传递参数，在构造函数里对其进行初始化

    myCom->open(QIODevice::ReadWrite);

    myCom->setBaudRate(BAUD115200);

    myCom->setDataBits(DATA_8);

    myCom->setParity(PAR_NONE);

    myCom->setStopBits(STOP_1);

    myCom->setFlowControl(FLOW_OFF);

    myCom->setTimeout(10);
    //以可读写方式打开串口
    QTimer *readTimer = new QTimer(this);

    readTimer->start(100);

    //设置延时为100ms
    display = QX11Info::display();


    if(myCom->isOpen())
    {

        ui->openButton->setText(tr("close"));
        ui->baudRatecomboBox->setEnabled(false);
        ui->portNamecomboBox->setEnabled(false);
    }
    else
    {
        ui->openButton->setText(tr("open"));
        ui->baudRatecomboBox->setEnabled(true);
        ui->portNamecomboBox->setEnabled(true);
    }

    connect(readTimer,SIGNAL(timeout()),this,SLOT(readCom()));
    connect(ui->writeButton,SIGNAL(clicked()),this,SLOT(writeCom()));

    connect(ui->openButton,SIGNAL(clicked()),this,SLOT(openserialport()));
    ui->setButton->setCheckable(true);
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);
}

GestureView::~GestureView()
{
    delete ui;
}

void GestureView::openserialport()
{
    if(myCom->isOpen())
    {
        myCom->close();
        ui->openButton->setText(tr("open"));
        ui->baudRatecomboBox->setEnabled(true);
        ui->portNamecomboBox->setEnabled(true);

    }else{

        QString portName = "/dev/" + ui->portNamecomboBox->currentText();   //获取串口名
        myCom = new Posix_QextSerialPort(portName, QextSerialBase::Polling);

        if(myCom->open(QIODevice::ReadWrite)){
            //QMessageBox::information(this, tr("打开成功"), tr("已成功打开串口 ") + portName, QMessageBox::Ok);
            ui->openButton->setText(tr("关闭"));
            ui->baudRatecomboBox->setEnabled(false);
            ui->portNamecomboBox->setEnabled(false);
       }else{
            QMessageBox::critical(this, tr("Open Failed"), tr("Can't open ") + portName + tr("\nThis port is busy or not exist!"), QMessageBox::Ok);
            return;
        }

        //设置波特率
        if(0==ui->baudRatecomboBox->currentIndex())
        {
            //printf("9600");
            myCom->setBaudRate(BAUD9600);
        }
        else if(1==ui->baudRatecomboBox->currentIndex())
        {
            //printf("115200");
            myCom->setBaudRate(BAUD115200);
        }

        myCom->setDataBits(DATA_8);

        myCom->setParity(PAR_NONE);

        myCom->setStopBits(STOP_1);

        myCom->setFlowControl(FLOW_OFF);

        myCom->setTimeout(10);



    }
}

void GestureView::readCom() //读串口函数
{
if(myCom->bytesAvailable() >=1 )
{

    QByteArray temp = myCom->readAll();
    ui->textBrowser->append(temp);
//    char* p = temp.data();
//    float a = atof(p+1);
//    float b = atof(p+7);
//    float c = atof(p+13);
    //printf("mandialog readCom %.3f %.3f %.3f\n", a, b, c);
    char *p=temp.data();//.data();
    switch(*p)
    {
    case 'q':sendKey(24);
        break;
    case 'w':sendKey(25);
        break;
    case 'e':sendKey(26);
        break;
    case 'r':sendKey(27);
        break;
    case 'y':sendKey(29);
        break;
    case 'a':sendKey(38);
        break;
    case 's':sendKey(39);
        break;
    case 'd':sendKey(40);
        break;
    case 'z':sendKey(52);
        break;

    case 'x':sendKey(53);
        break;
    case 'c':sendKey(54);
        break;
    case 'n':sendKey(57);
        break;

    case '-':sendKey(20);
        break;
    case '=':sendKey(21);
        break;

    case 'i':sendKey(31);
        break;
    case 'k':sendKey(45);
        break;
    case 'j':sendKey(44);
        break;
    case 'l':sendKey(46);
        break;
    case 'u':sendKey(30);
        break;
    case 'm':sendKey(58);
        break;

    case 'o':sendKey(32);
        break;
    default:
        break;
    }


}
//将串口的数据显示在窗口的文本浏览器中

}

void GestureView::sendKey(unsigned int keycode)
{
    //Q_UNUSED(press);
    //Q_UNUSED(release);
    Window curr_focus;
    int revert_to;

    XGetInputFocus( display, &curr_focus, &revert_to );
    XTestFakeKeyEvent( display, keycode, true, 1 );
    XTestFakeKeyEvent( display, keycode, false, 1 );
    XFlush( display );
}

void GestureView::writeCom() //写串口函数

{

    myCom->write(ui->lineEdit->text().toAscii());

   // QTextStream cout(stdout, QIODevice::WriteOnly);
    //ui->textBrowser->insertPlainText("char is"+ui->lineEdit->text().toAscii());
    //cout <<"wirteCom function"<<endl;//必须加endl才能输出

}
