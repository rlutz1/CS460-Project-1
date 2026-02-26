//
// Created by lutzr on 2/25/2026.
//

#include "ExitGateGUI.h"
#include <QGraphicsScene>
#include <QPainter>

ExitGateGUI::ExitGateGUI(QGraphicsScene& scene, InitializationPackage& initPackage, GateId id, WidgetMeta widgetMeta) :
led(
    scene,
    {.x = wm.x + (wm.width / 2), .y = wm.y, .width = 25, .height = 25, .color = Qt::gray, .zPos = (wm.zPos + 1)}
    ),
initOpenSensor(
    scene,
    id.initOpenId,
    {.x = wm.x + wm.width + (wm.width / 2), .y = wm.y, .width = 25, .height = 25, .color = Qt::black, .zPos = (wm.zPos + 1)}

    ),
stayOpenSensor(
    scene,
    id.stayOpenId,
    {.x = wm.x - 50, .y = wm.y, .width = 25, .height = 25, .color = Qt::black, .zPos = (wm.zPos + 1)}
    ),
spikes(
    scene,
    {.x = wm.x + wm.width + (wm.width / 2) + wm.width, .y = wm.y, .width = 25, .height = 100, .color = Qt::magenta, .zPos = (wm.zPos + 1)}
    ),
    id(id),
    wm(widgetMeta) {

    resize(wm.width, wm.height);
    setZValue(wm.zPos);

    scene.addItem(this);
}

// REQUIRED FOR GRAPHICS ITEM
QRectF ExitGateGUI::boundingRect() const {
    return QRectF(wm.x, wm.y, // this is BETTER
                  wm.width, wm.height);
}

// REQUIRED FOR GRAPHICS ITEM
void ExitGateGUI::paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option,
    QWidget *widget) {
    // painter->setBackground(Qt::transparent);
    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->setPen(QPen(Qt::black));
    painter->setBrush(QBrush(wm.color));
    // painter->setBrush(QBrush(Qt::transparent));
    painter->drawRect(boundingRect());
}

