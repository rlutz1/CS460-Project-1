//
// Created by Eliud Garcia on 2/24/26.
//

#include "SensorGUI.h"

#include <iostream>
#include <QGraphicsScene>
#include <QPainter>
#include <iostream>
SensorGUI::SensorGUI(QGraphicsScene& scene, SensorId id, WidgetMeta widgetMeta) :
    sensorId(id),
    wm(widgetMeta)
{
    resize(wm.width, wm.height);
    setZValue(wm.zPos);
}

TriggerPack SensorGUI::trigger() {
    std::cout << "trigger" << std::endl;
    return{};
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
    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->setPen(QPen(Qt::black));
    painter->setBrush(QBrush(wm.color));
    painter->drawRect(boundingRect());
}

void SensorGUI::reset() {

}

