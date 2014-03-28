#include "homeview.h"
HomeView::HomeView(QWidget *parent)
        : QGraphicsView(parent)
        , m_pageOffset(-1) {

    //界面初始化
    setupScene();
    setScene(&m_scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFrameShape(QFrame::NoFrame);
    setWindowTitle("Design Home");
    //设置背景透明
//    setAttribute(Qt::WA_TranslucentBackground);
//    setStyleSheet("background: transparent");
    //隐藏标题栏
    //setWindowFlags(Qt::FramelessWindowHint);
    connect(&m_pageAnimator, SIGNAL(frameChanged(int)), SLOT(shiftPage(int)));
    m_pageAnimator.setDuration(500);
    m_pageAnimator.setFrameRange(0, 100);
    m_pageAnimator.setCurveShape(QTimeLine::EaseInCurve);

    pageChanged(static_cast<int>(m_pageOffset));
    //readsceneXML("./res/model/conf.xml");
    //setTabOrder(m_book_btn,m_scene_btn);
//    m_book_btn->setFocusPolicy(Qt::StrongFocus);

    //m_book_btn->setHidden(true);

}

void HomeView::showBookScene()
{
    //setVisible(false);
    //creat a BookScene to show irrAR
    //QTextStream cout(stdout,  QIODevice::WriteOnly);
    Bookscene *booksecne=new Bookscene;
    booksecne->show();
    //cout<<"-----------------------------"<<(test1->sceneflag)<<endl;
    //creat a roomScene to enter the roomscene
    //模板从0开始，依次递增，没有模板为-1
    //booksecne->sceneflag+1的话就和id一致了
    if((booksecne->sceneflag+1)&&(booksecne->sceneflag!=16))
    {
//        booksecne->scenemanager[booksecne->sceneflag+1].getscene1path();
        Roomscene *m_roomscene=new Roomscene;
        //打开场景1（自定义）
        m_roomscene->show(booksecne->scenemanager[booksecne->sceneflag].getscene1path());

    }
    else{
        QMessageBox::critical(this, tr("Sorry"), tr("Sorry, Failed recognition"), QMessageBox::Ok);
    }
    //setVisible(true);

    //exit 773 to restart the process, to release the video(any way else to solve it!)
    qApp->closeAllWindows();
    qApp->exit(773);
    //exit(773);
}
void HomeView::showSceneSelect()
{
    Bookscene *bookscene=new Bookscene;
    bookscene->readsceneXML();
    Roomscene *m_roomselect = new Roomscene;
    m_roomselect->showselect();
//    if (m_roomselect->sceneid)
//        m_roomselect->show(bookscene->scenemanager[(m_roomselect->sceneid-1)/3].getscene1path());
    if ((m_roomselect->sceneid==1)||(m_roomselect->sceneid==4))
        m_roomselect->show(bookscene->scenemanager[(m_roomselect->sceneid-1)/3].getscene1path());
    else if( (m_roomselect->sceneid==2)||(m_roomselect->sceneid==5) )
        m_roomselect->show(bookscene->scenemanager[(m_roomselect->sceneid-1)/3].getscene2path());
    else if((m_roomselect->sceneid==3)||(m_roomselect->sceneid==6))
        m_roomselect->show(bookscene->scenemanager[(m_roomselect->sceneid-1)/3].getscene3path());
    //setVisible(true);
    //exit 773 to restart the process, to release the video(any way else to solve it!)
    qApp->closeAllWindows();
    qApp->exit(773);
}
void HomeView::showModelManage()
{
    ModelManageDialog *Modeldialog = new ModelManageDialog;
    Modeldialog->exec();
}
void HomeView::showViewManage()
{
    printf("showViewManage");
    ViewManageDialog *Viewdialog = new ViewManageDialog;
    Viewdialog->exec();
}
void HomeView::showSetting()
{
    SettingDialog *settingdialog = new SettingDialog;
    settingdialog->show();
}
void HomeView::slideRight() {
    if (m_pageAnimator.state() != QTimeLine::NotRunning)
        return;
    int edge = -(m_pageOffset - 1);
    if (edge < PAGE_COUNT)
        slideBy(-1);
}

void HomeView::slideLeft() {
    if (m_pageAnimator.state() != QTimeLine::NotRunning)
        return;
    if (m_pageOffset < 0)
        slideBy(1);
}

void HomeView::slideBy(int dx) {
    int start = m_pageOffset * 1000;
    int end = (m_pageOffset + dx) * 1000;
    m_pageAnimator.setFrameRange(start, end);
    m_pageAnimator.start();
}

void HomeView::choosePage(int page) {
    if (m_pageAnimator.state() != QTimeLine::NotRunning)
        return;
    if (static_cast<int>(-m_pageOffset) == page)
        return;
    slideBy(-page - m_pageOffset);
}


void HomeView::shiftPage(int frame) {

    int ww = width();
    int hh = height() - m_naviBar->rect().height();
    //animate navibar
    int oldPage = static_cast<int>(-m_pageOffset);
    m_pageOffset = static_cast<qreal>(frame) / qreal(1000);
    int newPage = static_cast<int>(-m_pageOffset);
    m_naviBar->setPageOffset(-m_pageOffset);
    if (oldPage != newPage)
        emit pageChanged(newPage);
    int ofs = m_pageOffset * ww;
    //animate the pic

//    for (int i = 0; i < m_items.count(); ++i) {
//        QPointF pos = m_positions[i];
//        QPointF xy(pos.x() * ww, pos.y() * hh);
//        m_items[i]->setPos(xy + QPointF(ofs, 0));
//    }
    //animate the background
    //int center = m_wallpaper->pixmap().width();// / 2
    //const int parallax = 3;
    //int base = center - (ww / 2) - (PAGE_COUNT >> 1) * (ww / parallax);
    //int wofs = base - m_pageOffset * ww / parallax;
    m_wallpaper->setPos((m_pageOffset)*1024, 0);

    //animate the button/widget
    m_model_widget->setPos(ofs+100, 110);
    m_view_widget->setPos(ofs+100,400);

    m_book_widget->setPos(ofs+1024+100, 110);
    m_scene_widget->setPos(ofs+1024+100,400);

    m_setting_widget->setPos(ofs+2048+100,250);


}


//void HomeView::mousePressEvent(QGraphicsSceneMouseEvent *event);

void HomeView::resizeEvent(QResizeEvent *event) {
    Q_UNUSED(event);
    layoutScene();
}

void HomeView::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_D)
        slideRight();
    if (event->key() == Qt::Key_A)
        slideLeft();
    if (event->key() == Qt::Key_W)

//        QWidget::focusNextPrevChild();
//    if (event->key() == Qt::Key_W)
//        QWidget::focusPreviousChild();
    event->accept();
}

void HomeView::layoutScene() {


    int ww = width();
    int hh = height();

    m_scene.setSceneRect(0, 0, PAGE_COUNT * ww - 1, hh - 1);
    centerOn(ww / 2, hh / 2);

    int nw = m_naviBar->rect().width();
    int nh = m_naviBar->rect().height();
    m_naviBar->setPos((ww - nw) / 2, hh - nh);

    shiftPage(m_pageOffset * 1000);
}

void HomeView::setupScene() {

    qsrand(QTime::currentTime().second());

//        QStringList names;
//        names << "brownies" << "cookies" << "mussels" << "pizza" << "sushi";
//        names << "chocolate" << "fish" << "pasta" << "puding" << "trouts";

//        for (int i = 0; i < PAGE_COUNT * 2; ++i) {
//            QString fname = names[i];
//            fname.prepend(":/images/");
//            fname.append(".jpg");
//            QPixmap pixmap(fname);
//            pixmap = pixmap.scaledToWidth(200);
//            QGraphicsPixmapItem *item = m_scene.addPixmap(pixmap);

//            m_items << item;

//            qreal x = (i >> 1) + (qrand() % 30) / 100.0;
//            qreal y = (i & 1) / 2.0  + (qrand() % 20) / 100.0;
//            m_positions << QPointF(x, y);
//            item->setZValue(1);
//        }

//    int i = 0;
//    QPixmap pixmap(":/images/brownies.jpg");
//    pixmap = pixmap.scaledToWidth(200);
//    QGraphicsPixmapItem *item = m_scene.addPixmap(pixmap);
//    m_items << item;
//    qreal x = (i >> 1) + (qrand() % 30) / 100.0;
//    qreal y = (i & 1) / 2.0  + (qrand() % 20) / 100.0;
//    m_positions << QPointF(x, y);
//    item->setZValue(1);

    m_naviBar = new NaviBar;
    m_scene.addItem(m_naviBar);
    m_naviBar->setZValue(2);
    connect(m_naviBar, SIGNAL(pageSelected(int)), SLOT(choosePage(int)));

    m_wallpaper = m_scene.addPixmap(QPixmap(":/icons/homeui/ui_bg.png"));

    m_wallpaper->setZValue(0);

    m_scene.setItemIndexMethod(QGraphicsScene::NoIndex);
    //const QString &normal, const QString &hovered, const QString &pressed, const QString &checked =""
    m_book_btn=new QImageButton(":/icons/homeui/item_2_1.png",":/icons/homeui/item_2_10.png",":/icons/homeui/item_2_10.png",":/icons/homeui/item_2_10.png");
    //m_book_btn->setText("test");
    m_book_widget=m_scene.addWidget(m_book_btn);
    connect(m_book_btn, SIGNAL(clicked()), SLOT(showBookScene()));

    m_scene_btn=new QImageButton(":/icons/homeui/item_2_2.png",":/icons/homeui/item_2_20.png",":/icons/homeui/item_2_20.png",":/icons/homeui/item_2_20.png");
    m_scene_widget=m_scene.addWidget(m_scene_btn);
    connect(m_scene_btn, SIGNAL(clicked()), SLOT(showSceneSelect()));

    m_model_btn=new QImageButton(":/icons/homeui/item_1_2.png",":/icons/homeui/item_1_20.png",":/icons/homeui/item_1_20.png",":/icons/homeui/item_1_20.png");
    m_model_widget=m_scene.addWidget(m_model_btn);
    connect(m_model_btn, SIGNAL(clicked()), SLOT(showModelManage()));

    m_view_btn=new QImageButton(":/icons/homeui/item_1_1.png",":/icons/homeui/item_1_10.png",":/icons/homeui/item_1_10.png",":/icons/homeui/item_1_10.png");
    m_view_widget=m_scene.addWidget(m_view_btn);
    connect(m_view_btn, SIGNAL(clicked()), SLOT(showViewManage()));

    m_setting_btn=new QImageButton(":/icons/homeui/item_3_1.png",":/icons/homeui/item_3_10.png",":/icons/homeui/item_3_10.png",":/icons/homeui/item_3_10.png");
    m_setting_widget=m_scene.addWidget(m_setting_btn);
    connect(m_setting_btn, SIGNAL(clicked()), SLOT(showSetting()));
    //connect(&m_scene, SIGNAL(itemSelected(QPointF &)), SLOT(chooseitem(QPointF &)) );
    //setTabOrder(m_book_widget,m_scene_widget);


}


