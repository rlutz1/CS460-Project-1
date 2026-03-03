//
// Created by Eliud Garcia on 2/24/26.
//

#include "VehicleGUI.h"

VehicleGUI::VehicleGUI() {

}

// REQUIRED FOR GRAPHICS ITEM
QRectF Vehicle::boundingRect() const {
    qreal penWidth = 1;
    return QRectF(0, 0, // this is BETTER
                  14, 14);
}

// REQUIRED FOR GRAPHICS ITEM
void Vehicle::paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option,
    QWidget *widget) {
    painter->setBackground(Qt::transparent);
    // painter->setRenderHint(QPainter::Antialiasing);
    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->setPen(QPen(Qt::black));
    painter->setBrush(QBrush(Qt::blue));
    painter->drawRect(QRectF(0, 0, 15, 15));
}
