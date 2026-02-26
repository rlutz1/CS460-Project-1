//
// Created by Eliud Garcia on 2/24/26.
//

#include "ParkingSpotGUI.h"
#include <QPainter>

// REQUIRED FOR GRAPHICS ITEM
QRectF ParkingSpotGUI::boundingRect() const {
    qreal penWidth = 1;
    return QRectF(0, 0, // this is BETTER
                  14, 14);
}

// REQUIRED FOR GRAPHICS ITEM
void ParkingSpotGUI::paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option,
    QWidget *widget) {
    painter->setBackground(Qt::transparent);
    // painter->setRenderHint(QPainter::Antialiasing);
    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->setPen(QPen(Qt::black));
    painter->setBrush(QBrush(Qt::blue));
    painter->drawRect(QRectF(0, 0, 15, 15));
}