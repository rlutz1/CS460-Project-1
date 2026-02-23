//
// Created by lutzr on 2/23/2026.
//

#include "ParkingSpot.h"

#include <iostream>
#include <qpainter.h>

#include "ParkingSpotSensor.h"

ParkingSpot::ParkingSpot() {
    // this -> ultrasonic_sensor = new ParkingSpotSensor("Sensor 1");
    // this -> weight_sensor = new ParkingSpotSensor("Sensor 2");
    // this -> available = true; // TODO MAYBE
    // this -> spotId = "";
    // this -> setStyleSheet("background-color: black;");
    // this -> show();
}

ParkingSpot::ParkingSpot(std::string spotId) {
    ultrasonic_sensor = new ParkingSpotSensor(spotId + "|Sensor 1");
    weight_sensor = new ParkingSpotSensor(spotId + "|Sensor 2");
    available = true; // TODO MAYBE
    this -> spotId = spotId;
    // setStyleSheet("background-color: black; border: medium dashed blue;");
    // setMaximumSize(QSize(50, 100));

    std::cout << pos().x() << pos().y() << std::endl;
}
//
// QSize ParkingSpot::sizeHint() const {
//     return QSize(50, 100);
// }

QRectF ParkingSpot::boundingRect() const {
    qreal penWidth = 1;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2,
                  20 + penWidth, 20 + penWidth);
}

void ParkingSpot::paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option,
    QWidget *widget) {
    painter->drawRoundedRect(-10, -10, 20, 20, 5, 5);
}
