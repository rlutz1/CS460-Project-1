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



ParkingLotGUI::ParkingLotGUI(QGraphicsScene& scene, InitializationPackage& initPackage, WidgetMeta widgetMeta) :
    gate(scene, initPackage),
    wm(widgetMeta) {
    // set visual data
    // setGeometry(wm.x, wm.y, wm.width, wm.height);
    resize(wm.width, wm.height);
    setZValue(wm.zPos); // hard coded, needs to be underneath ALL

    std::cout << wm.x << wm.y << wm.width << wm.height << std::endl;

    // init floors
    ParkingFloorGUI* floor;
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
        parkingFloors.push_back(floor);
    } // end loop


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
    // std::cout <<  "painting lot" << std::endl;
    // painter->setBackground(Qt::transparent);
    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->setPen(QPen(Qt::black));
    painter->setBrush(QBrush(wm.color));
    // painter->setBrush(QBrush(Qt::transparent));
    painter->drawRect(boundingRect());
}
