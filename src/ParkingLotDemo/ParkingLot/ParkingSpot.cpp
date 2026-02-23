//
// Created by lutzr on 2/23/2026.
//

#include "ParkingSpot.h"
#include "ParkingSpotSensor.h"

ParkingSpot::ParkingSpot() {
    this -> ultrasonic_sensor = new ParkingSpotSensor("Sensor 1");
    this -> weight_sensor = new ParkingSpotSensor("Sensor 2");
    this -> available = true; // TODO MAYBE
    this -> spotId = "";
    this -> setStyleSheet("background-color: black; border: medium dashed green;min-width: 50px;");
    // this -> show();
}

ParkingSpot::ParkingSpot(std::string spotId) {
    this -> ultrasonic_sensor = new ParkingSpotSensor(spotId + "|Sensor 1");
    this -> weight_sensor = new ParkingSpotSensor(spotId + "|Sensor 2");
    this -> available = true; // TODO MAYBE
    this -> spotId = spotId;
    this -> setStyleSheet("background-color: black; border: medium dashed green; min-width: 50px;");
    // this -> show();
}

QSize ParkingSpot::sizeHint() const {
    return QSize(50, 100);
}
