//
// Created by Eliud Garcia on 2/24/26.
//

#include "GateGUI.h"

#include <QGraphicsScene>
#include <QGraphicsWidget>
#include <QPainter>


GateGUI::GateGUI(QGraphicsScene& scene, InitializationPackage& initPackage, WidgetMeta widgetMeta) :
    entranceGate(
        scene,
        initPackage,
        initPackage.entranceGateId,
        {}),
    exitGate(scene,
        initPackage,
        initPackage.exitGateId,
        {}),
    wm(widgetMeta)
    {
    resize(wm.width, wm.height);
    setZValue(wm.zPos);

    scene.addItem(this);
    // scene.addItem((QGraphicsWidget*) &exitGate);
    // scene.addItem((QGraphicsWidget*) &entranceGate);
}


// REQUIRED FOR GRAPHICS ITEM
QRectF GateGUI::boundingRect() const {
    return QRectF(wm.x, wm.y, // this is BETTER
                  wm.width, wm.height);
}

// REQUIRED FOR GRAPHICS ITEM
void GateGUI::paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option,
    QWidget *widget) {
    // painter->setBackground(Qt::transparent);
    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->setPen(QPen(Qt::black));
    painter->setBrush(QBrush(wm.color));
    // painter->setBrush(QBrush(Qt::transparent));
    painter->drawRect(boundingRect());
}

