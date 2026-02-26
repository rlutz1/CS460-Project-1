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



ParkingLotGUI::ParkingLotGUI(QGraphicsScene& scene, InitializationPackage& initPackage) :
gate(scene, initPackage) {
    // init floors

    resize(sl.width, sl.height);
    for (FloorId id: initPackage.floorIds) {
        ParkingFloorGUI* floor = new ParkingFloorGUI(scene, initPackage, id);
        if (id.uniqueId.compare("floor1") == 0  ) { // dirty, i know, but doable since we will not change
            // floor.sl = {.x = -400, .y = 300, .width = 400, .height = 600};
            floor->sl = {.x = 0, .y = 0, .width = 400, .height = 600};
        } else {
            floor->sl = {.x = 0, .y = 0, .width = 700, .height = 600};
        }
        parkingFloors.push_back(floor);
        // this -> scene -> addItem((QGraphicsWidget*) &floor); // TODO
        // scene.addItem((QGraphicsWidget*) &floor); // TODO
    } // end loop
    // ParkingFloorGUI floor(scene, initPackage, {.uniqueId = "TEST"}); // not incurring an additional call
    // parkingFloors.push_back(&floor);

    setPos(0, 0);
    setZValue(0); // hard coded, needs to be underneath ALL
    scene.addItem(this); // TODO: this still works! so this is not necessarily the issue, passing it
} // end constructor


// REQUIRED FOR GRAPHICS ITEM
QRectF ParkingLotGUI::boundingRect() const {
    qreal penWidth = 1;
    return QRectF(0, 0, // this is BETTER
                  sl.width - penWidth, sl.height - penWidth);
}

// REQUIRED FOR GRAPHICS ITEM
void ParkingLotGUI::paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option,
    QWidget *widget) {
    std::cout <<  "painting lot" << std::endl;
    painter->setBackground(Qt::transparent);
    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->setPen(QPen(Qt::black));
    painter->setBrush(QBrush(Qt::darkGray));
    // painter->setBrush(QBrush(Qt::transparent));
    painter->drawRect(QRectF(sl.x, sl.y, sl.width, sl.height));
}
