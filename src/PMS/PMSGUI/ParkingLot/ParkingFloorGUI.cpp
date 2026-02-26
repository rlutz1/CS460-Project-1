//
// Created by Eliud Garcia on 2/24/26.
//

#include "ParkingFloorGUI.h"
#include <QPainter>

ParkingFloorGUI::ParkingFloorGUI(QGraphicsScene &scene, InitializationPackage &initPackage, FloorId floorId) :
    floorId(floorId) {
    setZValue(100);

}

// REQUIRED FOR GRAPHICS ITEM
QRectF ParkingFloorGUI::boundingRect() const {
    qreal penWidth = 1;
    return QRectF(0, 0, // this is BETTER
                  sl.width - penWidth, sl.height - penWidth);
}

// REQUIRED FOR GRAPHICS ITEM
void ParkingFloorGUI::paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option,
    QWidget *widget) {
    painter->setBackground(Qt::transparent);
    // painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->setPen(QPen(Qt::black));
    painter->setBrush(QBrush(Qt::darkBlue));
    painter->drawRect(QRectF(sl.x, sl.y, sl.width, sl.height));
}