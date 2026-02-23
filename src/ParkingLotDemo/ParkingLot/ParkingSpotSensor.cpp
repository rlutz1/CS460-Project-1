//
// Created by lutzr on 2/23/2026.
//

#include "ParkingSpotSensor.h"

ParkingSpotSensor::ParkingSpotSensor(std::string id) {
    this -> sensorId = id;
    this -> enabled = true;
}

void ParkingSpotSensor::enable() {
    this -> enabled = true;
}

void ParkingSpotSensor::disable() {
    this -> enabled = false;
}
