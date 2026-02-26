//
// Created by Eliud Garcia on 2/24/26.
//

#include "ParkingFloorGUI.h"
#include <iostream>
#include <QGraphicsScene>
#include <QPainter>

using std::cout;

void initFirstFloor() {

}

void initFloor() {

}

ParkingFloorGUI::ParkingFloorGUI(QGraphicsScene& scene, InitializationPackage& initPackage, FloorId floorId, WidgetMeta widgetMeta) :
    floorId(floorId),
    wm(widgetMeta) {
    // visual data
    // setPos(wm.x, wm.y);
    setZValue(wm.zPos);
    resize(wm.width, wm.height);

    // init parking lots
    if (floorId.uniqueId.compare("floor1") == 0) {
        initFirstFloor();
    } else {
        initFloor();
    }

    scene.addItem(this);
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
