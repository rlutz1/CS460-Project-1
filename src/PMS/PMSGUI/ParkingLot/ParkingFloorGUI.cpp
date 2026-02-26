//
// Created by Eliud Garcia on 2/24/26.
//

#include "ParkingFloorGUI.h"
#include <iostream>
#include <QGraphicsScene>
#include <QPainter>

using std::cout;

ParkingFloorGUI::ParkingFloorGUI(QGraphicsScene& scene, InitializationPackage& initPackage, FloorId floorId) :
    floorId(floorId) {
    if (!&scene) {
        cout << "what the fuck" << std::endl;
    }
    cout << floorId.uniqueId << std::endl;
    setPos(sl.x, sl.y);
    setZValue(1);
    resize(sl.width, sl.height);
    // setVisible(true);
    // this->show();
    scene.addItem(this);
    // this->update();




}

// REQUIRED FOR GRAPHICS ITEM
QRectF ParkingFloorGUI::boundingRect() const {
    qreal penWidth = 1;
    return QRectF(0, 0, // this is BETTER
                  sl.width, sl.height);
}

// REQUIRED FOR GRAPHICS ITEM
void ParkingFloorGUI::paint(QPainter *painter,
                            const QStyleOptionGraphicsItem *option,
                            QWidget *widget) {
    cout << floorId.uniqueId << " painting" << std::endl;
    // painter->setBackground(Qt::transparent);
    // painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->setPen(QPen(Qt::black));
    painter->setBrush(QBrush(Qt::darkBlue));
    // painter->drawRect(QRectF(sl.x, sl.y, sl.width, sl.height));
    painter->drawRect(boundingRect());
}
