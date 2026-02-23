//
// Created by lutzr on 2/23/2026.
//

#include "ParkingSpotSensor.h"

#include <qpainter.h>

ParkingSpotSensor::ParkingSpotSensor(std::string id, QGraphicsWidget *parent) : QGraphicsWidget(parent) {
    // setParentItem(parent);
    this -> sensorId = id;
    this -> enabled = true;
    // setPos(parent->pos().x(), parent->pos().y()); // this makes it's orgin relative to the parent
}

void ParkingSpotSensor::enable() {
    this -> enabled = true;
}

void ParkingSpotSensor::disable() {
    this -> enabled = false;
}

// REQUIRED FOR GRAPHICS ITEM
QRectF ParkingSpotSensor::boundingRect() const {
    qreal penWidth = 1;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2,
                  20 + penWidth, 20 + penWidth);
}

// REQUIRED FOR GRAPHICS ITEM
void ParkingSpotSensor::paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option,
    QWidget *widget) {
    painter->setPen(QPen(Qt::black));
    painter->setBrush(QBrush(Qt::black));
    painter->drawEllipse(QRectF(20, 0, 10, 10));
}
