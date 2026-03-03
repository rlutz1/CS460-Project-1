//
// Created by Eliud Garcia on 2/24/26.
//

#include "SensorGUI.h"

#include <QGraphicsScene>
#include <QPainter>

SensorGUI::SensorGUI(QGraphicsScene& scene, SensorId id, WidgetMeta widgetMeta) :
    sensorId(id),
    wm(widgetMeta) {

    resize(wm.width, wm.height);
    setZValue(wm.zPos);

    // scene.addItem(this);
}

// REQUIRED FOR GRAPHICS ITEM
QRectF SensorGUI::boundingRect() const {
    return QRectF(wm.x, wm.y, // this is BETTER
                  wm.width, wm.height);
}

// REQUIRED FOR GRAPHICS ITEM
void SensorGUI::paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option,
    QWidget *widget) {
    // painter->setBackground(Qt::transparent);
    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->setPen(QPen(Qt::black));
    painter->setBrush(QBrush(wm.color));
    // painter->setBrush(QBrush(Qt::transparent));
    painter->drawRect(boundingRect());
}

void SensorGUI::reset() {

}

