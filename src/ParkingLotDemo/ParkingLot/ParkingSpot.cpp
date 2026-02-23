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

ParkingSpot::ParkingSpot(std::string spotId, QWidget *parent) {
    this -> setParent(parent);
    this -> ultrasonic_sensor = new ParkingSpotSensor(spotId + "|Sensor 1");
    this -> weight_sensor = new ParkingSpotSensor(spotId + "|Sensor 2");
    this -> available = true; // TODO MAYBE
    this -> spotId = spotId;
    this -> setStyleSheet("background-color: red;");
    // this -> setMinimumWidth(300);
    // this -> setMinimumHeight(300);
    // this -> setGeometry(150, 150, 150, 150);
    std::cout << this -> x() << this -> y() << std::endl;
    // this -> show();
}

QSize ParkingSpot::sizeHint() const {
    return QSize(50, 100);
}
