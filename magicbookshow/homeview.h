#ifndef HOMEDIALOG_H
#define HOMEDIALOG_H
#include <QtCore>
#include <QtGui>
#include "homeview/NaviBar.h"
#include "homeview/QImageButton.h"
#include "bookscene.h"
#include "roomscene.h"
//uishow
#include "settingdialog.h"
#include "modelmanagedialog.h"
#include "viewmanagedialog.h"
//串口相关
#include "plotter.h"

#define PAGE_COUNT 4

class HomeView: public QGraphicsView
{
    Q_OBJECT

public:
    QGraphicsScene m_scene;
    NaviBar *m_naviBar;
    QGraphicsPixmapItem *m_wallpaper;

    //book scan show button/widget
    QGraphicsProxyWidget *m_book_widget;
    QImageButton *m_book_btn;

    //scene select button/widget
    QGraphicsProxyWidget *m_scene_widget;
    QImageButton *m_scene_btn;

    //Model manage button/widget
    QGraphicsProxyWidget *m_model_widget;
    QImageButton *m_model_btn;

    //View manage button/widget
    QGraphicsProxyWidget *m_view_widget;
    QImageButton *m_view_btn;

    //setting button/widget
    QGraphicsProxyWidget *m_setting_widget;
    QImageButton *m_setting_btn;

    QTimeLine m_pageAnimator;
    qreal m_pageOffset;
    QList<QGraphicsPixmapItem*> m_items;
    QList<QPointF> m_positions;


public:
    HomeView(QWidget *parent = 0);

signals:
    void pageChanged(int page);
public slots:
//show someting dialog

    void showBookScene();

    void showSceneSelect();

    void showModelManage();

    void showViewManage();

    void showSetting();

//animate widget
    void slideRight();

    void slideLeft();

    void slideBy(int dx);

    void choosePage(int page);

private slots:

    void shiftPage(int frame);

protected:

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void resizeEvent(QResizeEvent *event) ;

    void keyPressEvent(QKeyEvent *event) ;

private:

    void layoutScene() ;
    void setupScene() ;


};

#endif // HOMEDIALOG_H
