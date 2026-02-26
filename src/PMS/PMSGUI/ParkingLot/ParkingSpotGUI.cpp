//
// Created by Eliud Garcia on 2/24/26.
//

#include "ParkingSpotGUI.h"

#include <QGraphicsScene>
#include <QPainter>


ParkingSpotGUI::ParkingSpotGUI(QGraphicsScene& scene, InitializationPackage& initPackage, SpotId spotId, WidgetMeta widgetMeta) :
    wm(widgetMeta){
    // set visual data
    resize(wm.width, wm.height);
    // setPos(wm.x, wm.y);
    setZValue(wm.zPos); // hard coded, needs to be underneath ALL

    scene.addItem(this);

}

// REQUIRED FOR GRAPHICS ITEM
QRectF ParkingSpotGUI::boundingRect() const {
    return QRectF(wm.x, wm.y, // this is BETTER
                  wm.width, wm.height);
}

// REQUIRED FOR GRAPHICS ITEM
void ParkingSpotGUI::paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option,
    QWidget *widget) {
    // painter->setBackground(Qt::transparent);
    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->setPen(QPen(Qt::black));
    painter->setBrush(QBrush(wm.color));
    // painter->setBrush(QBrush(Qt::transparent));
    painter->drawRect(boundingRect());
}