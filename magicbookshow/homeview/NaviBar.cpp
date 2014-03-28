#define ICON_SIZE 50
#define ICON_PAD 4
#include"NaviBar.h"
NaviBar::NaviBar()
        : QGraphicsRectItem()
{
    //设置底部滑动背景
    setBrush(QColor(Qt::white));
    setRect(0, 0, 4 * ICON_SIZE, ICON_SIZE);
    setPen(Qt::NoPen);

    QStringList names;
    //设置底部图片
    names << "bt_1"<<"bt_2"<<"bt_3"<<"bt_4"<<"bt_10"<<"bt_20"<<"bt_30"<<"bt_40";
    for (int i = 0; i < names.count()-4; ++i) {
        QString fname = names[i];
        fname.prepend(":/icons/homeui/");
        fname.append(".png");
        QGraphicsPixmapItem *icon = new QGraphicsPixmapItem(fname);
        icon->setParentItem(this);
        const int dim = ICON_SIZE - ICON_PAD * 2;
        qreal sw = dim / icon->boundingRect().width();
        qreal sh = dim / icon->boundingRect().height();
        icon->setTransform(QTransform().scale(sw, sh));
        icon->setZValue(2);
        m_icons << icon;
    }
    //覆盖层图片(选中部分)
    m_cursor = new QGraphicsRectItem;
    m_cursor->setParentItem(this);
    m_cursor->setRect(0, 0, ICON_SIZE, ICON_SIZE);
    m_cursor->setZValue(1);
    m_cursor->setPen(Qt::NoPen);
    m_cursor->setBrush(QColor(Qt::white));
    m_cursor->setOpacity(0.6);
}

void NaviBar::setPageOffset(qreal ofs)
{
    m_cursor->setPos(ofs * ICON_SIZE, 0);
    for (int i = 0; i < m_icons.count(); ++i) {
        int y = (i == static_cast<int>(ofs + 0.5)) ? ICON_PAD : ICON_PAD * 2;
        m_icons[i]->setPos(i * ICON_SIZE + ICON_PAD, y);
//        QGraphicsColorizeEffect *e0=new QGraphicsColorizeEffect(this);
//        e0->setColor(QColor(0,0,255));
//        m_icons[i]->setGraphicsEffect(e0);
        m_icons[i]->setOpacity(1);
    }
}

void NaviBar::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit pageSelected(static_cast<int>(event->pos().x() / ICON_SIZE));
}


void NaviBar::paint(QPainter * painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //设置笔刷Bar的颜色
    painter->setBrush(Qt::white);
    //设置透明度
    painter->setOpacity(0.2);
    //绘制背景图形
    //painter->drawRect(option->rect.adjusted(-20, ICON_PAD, 20, 0));
    painter->drawRoundedRect(option->rect.adjusted(-20, ICON_PAD, 20, 0),5,5);
}
