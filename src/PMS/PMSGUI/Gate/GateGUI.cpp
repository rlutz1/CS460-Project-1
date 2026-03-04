//
// Created by Eliud Garcia on 2/24/26.
//

#include "GateGUI.h"
#include "../GUIStructs/GUIStructs.h"

#include <QGraphicsScene>
#include <QGraphicsWidget>
#include <QPainter>


GateGUI::GateGUI(QGraphicsScene& scene, InitializationPackage& initPackage, WidgetMeta widgetMeta) :
    entranceGate( new EntranceGateGUI(
        scene,
        initPackage,
        initPackage.entranceGateId,
        {.x = wm.x + 150, .y = wm.y + 200, .width = 50, .height = 100, .color = Qt::green, .zPos = (wm.zPos + 1)})),
    exitGate( new ExitGateGUI(
        scene,
        initPackage,
        initPackage.exitGateId,
        {.x = wm.x + 150, .y = wm.y, .width = 50, .height = 100, .color = Qt::green, .zPos = (wm.zPos + 1)})),
    wm(widgetMeta)
    {
    resize(wm.width, wm.height);
    setZValue(wm.zPos);

    // entranceGate = new EntranceGateGUI(
    //     scene,
    //     initPackage,
    //     initPackage.entranceGateId,
    //     {.x = wm.x + 150, .y = wm.y + 200, .width = 50, .height = 100, .color = Qt::green, .zPos = (wm.zPos + 1)}
    // );
    //
    entranceGate->setParentItem(this);
    //
    // exitGate = new ExitGateGUI(
    //     scene,
    //     initPackage,
    //     initPackage.exitGateId,
    //     {.x = wm.x + 150, .y = wm.y, .width = 50, .height = 100, .color = Qt::green, .zPos = (wm.zPos + 1)}
    // );

    exitGate->setParentItem(this);

    // scene.addItem(this);
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

void GateGUI::reset() {
    entranceGate->reset();
    exitGate->reset();
}

