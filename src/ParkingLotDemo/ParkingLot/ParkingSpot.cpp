//
// Created by lutzr on 2/23/2026.
//

#include "ParkingSpot.h"

#include <iostream>

#include "ParkingSpotSensor.h"

ParkingSpot::ParkingSpot() {
    // this -> ultrasonic_sensor = new ParkingSpotSensor("Sensor 1");
    // this -> weight_sensor = new ParkingSpotSensor("Sensor 2");
    // this -> available = true; // TODO MAYBE
    // this -> spotId = "";
    // this -> setStyleSheet("background-color: black;");
    // this -> show();
}

ParkingSpot::ParkingSpot(std::string spotId, QWidget *parent) : QWidget(parent){
    ultrasonic_sensor = new ParkingSpotSensor(spotId + "|Sensor 1");
    weight_sensor = new ParkingSpotSensor(spotId + "|Sensor 2");
    available = true; // TODO MAYBE
    this -> spotId = spotId;
    setStyleSheet("background-color: black; border: medium dashed blue;");
    setMaximumSize(QSize(50, 100));
    // this -> setMinimumWidth(300);
    // this -> setMinimumHeight(300);
    // this -> setGeometry(150, 150, 150, 150);
    std::cout << pos().x() << pos().y() << std::endl;
    // this -> show();
}

QSize ParkingSpot::sizeHint() const {
    return QSize(50, 100);
}
