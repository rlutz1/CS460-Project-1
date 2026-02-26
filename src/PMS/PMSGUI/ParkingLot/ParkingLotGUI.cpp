//
// Created by lutzr on 2/25/2026.
//

#include "ParkingLotGUI.h"

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
    for (FloorId id: initPackage.floorIds) {
        ParkingFloorGUI floor(scene, initPackage, id);
        parkingFloors.push_back(&floor);
        scene.addItem((QGraphicsWidget*) &floor);
    } // end loop
} // end constructor


// REQUIRED FOR GRAPHICS ITEM
QRectF ParkingLotGUI::boundingRect() const {
    qreal penWidth = 1;
    return QRectF(0, 0, // this is BETTER
                  14, 14);
}

// REQUIRED FOR GRAPHICS ITEM
void ParkingLotGUI::paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option,
    QWidget *widget) {
    painter->setBackground(Qt::transparent);
    // painter->setRenderHint(QPainter::Antialiasing);
    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->setPen(QPen(Qt::black));
    painter->setBrush(QBrush(Qt::blue));
    painter->drawRect(QRectF(0, 0, 15, 15));
}
