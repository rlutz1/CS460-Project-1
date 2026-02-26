//
// Created by lutzr on 2/25/2026.
//

#include "ParkingLotGUI.h"

#include <iostream>
#include <QGraphicsScene>
#include <QPainter>

#include "ParkingFloorGUI.h"
#include "../Gate/GateGUI.h"
#include "../../Initialization.h"


#define Y_TOP_LOTS 300
#define Y_BOTTOM_LOTS (-200)
#define Y_GATE_CENTER 0



ParkingLotGUI::ParkingLotGUI(QGraphicsScene& scene, InitializationPackage& initPackage, WidgetMeta wm) :
    gate(scene, initPackage),
    wm(wm) {
    // init floors
    for (FloorId id: initPackage.floorIds) {
        // the scene object will delete ALL ITEMS on deconstruction. no cleanup required from us.
        ParkingFloorGUI* floor = new ParkingFloorGUI(scene, initPackage, id);
        if (id.uniqueId.compare("floor1") == 0  ) { // dirty, i know, but doable since we will not change
            floor->wm = {.x = 300, .y = 0, .width = 400, .height = 600, .color = Qt::lightGray, .zPos = wm.zPos + 1};
        } else {
            floor->wm = {.x = 700, .y = 0, .width = 700, .height = 600,  .color = Qt::lightGray, .zPos = wm.zPos + 1};
        }
        parkingFloors.push_back(floor);
    } // end loop

    // set visual data
    resize(wm.width, wm.height);
    setPos(wm.x, wm.y);
    setZValue(wm.zPos); // hard coded, needs to be underneath ALL
    scene.addItem(this); // add myself to the scene
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
    std::cout <<  "painting lot" << std::endl;
    // painter->setBackground(Qt::transparent);
    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->setPen(QPen(Qt::black));
    painter->setBrush(QBrush(wm.color));
    // painter->setBrush(QBrush(Qt::transparent));
    painter->drawRect(boundingRect());
}
