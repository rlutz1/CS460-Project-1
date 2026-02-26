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
    setPos(wm.x, wm.y);
    setZValue(1);
    resize(wm.width, wm.height);
    // setVisible(true);
    // this->show();
    scene.addItem(this);
    // this->update();




}

// REQUIRED FOR GRAPHICS ITEM
QRectF ParkingFloorGUI::boundingRect() const {
    qreal penWidth = 1;
    return QRectF(wm.x, wm.y, // this is BETTER
                  wm.width, wm.height);
}

// REQUIRED FOR GRAPHICS ITEM
void ParkingFloorGUI::paint(QPainter *painter,
                            const QStyleOptionGraphicsItem *option,
                            QWidget *widget) {
    cout << floorId.uniqueId << " painting" << std::endl;
    // painter->setBackground(Qt::transparent);
    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->setPen(QPen(Qt::black));
    painter->setBrush(QBrush(wm.color));
    painter->drawRect(boundingRect());
}
