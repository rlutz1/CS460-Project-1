//
// Created by Eliud Garcia on 2/24/26.
//

#include "LedGUI.h"

#include <QGraphicsScene>
#include <QPainter>

LedGUI::LedGUI(QGraphicsScene& scene, WidgetMeta widgetMeta) :
    wm(widgetMeta),
    currColor(wm.color)
{
    resize(wm.width, wm.height);
    setZValue(wm.zPos);
}

// REQUIRED FOR GRAPHICS ITEM
QRectF LedGUI::boundingRect() const {
    return QRectF(wm.x, wm.y, // this is BETTER
                  wm.width, wm.height);
}

// REQUIRED FOR GRAPHICS ITEM
void LedGUI::paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option,
    QWidget *widget) {
    // painter->setBackground(Qt::transparent);
    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->setPen(QPen(Qt::black));
    painter->setBrush(QBrush(currColor));
    // painter->setBrush(QBrush(Qt::transparent));
    painter->drawRect(boundingRect());
}

void LedGUI::reset(QColor color) {
    currColor = color;
    update();
}
