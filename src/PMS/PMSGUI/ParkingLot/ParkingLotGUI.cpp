//
// Created by lutzr on 2/25/2026.
//

#include "ParkingLotGUI.h"

#include <iostream>
#include <QGraphicsScene>
#include <QPainter>
#include <QVector>
#include <QPointer>

#include "ParkingFloorGUI.h"
#include "../Gate/GateGUI.h"
#include "../../Initialization.h"


ParkingLotGUI::ParkingLotGUI(QGraphicsScene& scene, InitializationPackage& initPackage, WidgetMeta widgetMeta) :
    gate(new GateGUI(
        scene,
        initPackage,
        {.x = wm.x, .y = wm.y + 150, .width = 300, .height = 300, .color = Qt::darkGray, .zPos = (wm.zPos + 1)})),
    wm(widgetMeta) {
    // set visual data
    resize(wm.width, wm.height);
    setZValue(wm.zPos); // hard coded, needs to be underneath ALL
    gate->setParentItem(this);


    QPointer<ParkingFloorGUI> floor;
    for (FloorId id: initPackage.floorIds) {
        // the scene object will delete ALL ITEMS on deconstruction. no cleanup required from us.
        if (id.uniqueId.compare("floor1") == 0) { // dirty, i know, but doable since we will not change
            floor = new ParkingFloorGUI(
            scene,
            initPackage,
            id,
            {.x = wm.x + 300, .y = wm.y, .width = 400, .height = wm.height,  .color = Qt::lightGray, .zPos = (wm.zPos + 1)}
            );
        } else {
            floor = new ParkingFloorGUI(
            scene,
            initPackage,
            id,
            {.x = wm.x + wm.width / initPackage.numbers.floors, .y = wm.y, .width = wm.width / initPackage.numbers.floors, .height = wm.height,  .color = Qt::lightGray, .zPos = (wm.zPos + 1)}
            );
        }
        floor->setParentItem(this);
        parkingFloors.push_back(floor);
    } // end loop

} // end constructor


// REQUIRED FOR GRAPHICS ITEM
QRectF ParkingLotGUI::boundingRect() const {
    return QRectF(wm.x, wm.y, // this is BETTER
                  wm.width, wm.height);
}

// REQUIRED FOR GRAPHICS ITEM
void ParkingLotGUI::paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option,
    QWidget *widget) {
    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->setPen(QPen(Qt::black));
    painter->setBrush(QBrush(wm.color));
    painter->drawRect(boundingRect());
}

void ParkingLotGUI::reset() {
    for (QPointer<ParkingFloorGUI> floor: parkingFloors) {
        floor->reset();
    }
    gate->reset();
}
