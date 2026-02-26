//
// Created by lutzr on 2/25/2026.
//

#include "EntranceGateGUI.h"
#include <QGraphicsScene>
#include <QPainter>

EntranceGateGUI::EntranceGateGUI(QGraphicsScene& scene, InitializationPackage& initPackage, GateId id, WidgetMeta widgetMeta) :

    id(id),
    wm(widgetMeta) {

    resize(wm.width, wm.height);
    setZValue(wm.zPos);

    scene.addItem(this);
    // scene.addItem((QGraphicsWidget*) &led);
    // scene.addItem((QGraphicsWidget*) &initOpenSensor);
    // scene.addItem((QGraphicsWidget*) &stayOpenSensor);
    // scene.addItem((QGraphicsWidget*) &spikes);
}

// REQUIRED FOR GRAPHICS ITEM
QRectF EntranceGateGUI::boundingRect() const {
    return QRectF(wm.x, wm.y, // this is BETTER
                  wm.width, wm.height);
}

// REQUIRED FOR GRAPHICS ITEM
void EntranceGateGUI::paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option,
    QWidget *widget) {
    // painter->setBackground(Qt::transparent);
    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->setPen(QPen(Qt::black));
    painter->setBrush(QBrush(wm.color));
    // painter->setBrush(QBrush(Qt::transparent));
    painter->drawRect(boundingRect());
}
