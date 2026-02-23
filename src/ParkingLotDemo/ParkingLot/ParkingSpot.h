//
// Created by lutzr on 2/23/2026.
//

#ifndef CS460_PROJECT_1_PARKINGSPOT_H
#define CS460_PROJECT_1_PARKINGSPOT_H

class ParkingSpotSensor;

class ParkingSpot {
public:
    ParkingSpotSensor* ultrasonic_sensor;
    ParkingSpotSensor* weight_sensor;
    bool available; // TODO MAYBE
};


#endif //CS460_PROJECT_1_PARKINGSPOT_H