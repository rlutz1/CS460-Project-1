//
// Created by lutzr on 2/23/2026.
//

#ifndef CS460_PROJECT_1_PARKINGSPOT_H
#define CS460_PROJECT_1_PARKINGSPOT_H
#include <qwidget.h>

class ParkingSpotSensor;

class ParkingSpot : public QWidget{
public:
    ParkingSpot();
    ParkingSpot(std::string spotId);
    ParkingSpotSensor* ultrasonic_sensor;
    ParkingSpotSensor* weight_sensor;
    bool available; // TODO MAYBE
    std::string spotId;

protected:
    QSize sizeHint() const override;
};


#endif //CS460_PROJECT_1_PARKINGSPOT_H