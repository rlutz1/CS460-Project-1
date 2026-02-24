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

ParkingSpot::ParkingSpot(std::string spotId, QPoint pos) {
    // setPos(0, -300);
    ultrasonic_sensor = new ParkingSpotSensor(spotId + "|Sensor 1", this);
    weight_sensor = new ParkingSpotSensor(spotId + "|Sensor 2", this);
    available = true; // TODO MAYBE
    this->spotId = spotId;
    this->pos = pos;
    setZValue(1);

    available_color = Qt::green;
    occupied_color = Qt::red;
    unavailable_color = Qt::darkYellow;

    brush = QBrush(available_color);
    // setStyleSheet("background-color: black; border: medium dashed blue;");
    // setMaximumSize(QSize(50, 100));

    // std::cout << pos().x() << pos().y() << std::endl;
}
//
// QSize ParkingSpot::sizeHint() const {
//     return QSize(50, 100);
// }

void ParkingSpot::update_led(std::string state) {
    if (state == "AVAILABLE") {
        brush = QBrush(available_color);
    } else if (state == "OCCUPIED") {
        brush = QBrush(occupied_color);
    } else if (state == "UNAVAILABLE") {
        brush = QBrush(unavailable_color);
    }

    // this -> update(); // updating entire scene seems to be the way.
}

// REQUIRED FOR GRAPHICS ITEM
QRectF ParkingSpot::boundingRect() const {
    qreal penWidth = 1;
    return QRectF(0 , 0,
                  49, 99);
}

// REQUIRED FOR GRAPHICS ITEM
void ParkingSpot::paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option,
    QWidget *widget) {
    painter->setPen(QPen(Qt::black));
    painter->setBrush(brush);
    painter->drawRect(QRectF(pos.x(), pos.y(), 50, 100));
}


