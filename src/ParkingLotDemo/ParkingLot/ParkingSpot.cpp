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
}

ParkingSpot::ParkingSpot(std::string spotId) {
    this -> ultrasonic_sensor = new ParkingSpotSensor(spotId + "|Sensor 1");
    this -> weight_sensor = new ParkingSpotSensor(spotId + "|Sensor 2");
    this -> available = true; // TODO MAYBE
    this -> spotId = spotId;
}

QSize ParkingSpot::sizeHint() const {
    return QSize(50, 100);
}
