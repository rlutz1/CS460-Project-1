//
// Created by lutzr on 2/23/2026.
//

#ifndef CS460_PROJECT_1_PARKINGSPOTSENSOR_H
#define CS460_PROJECT_1_PARKINGSPOTSENSOR_H
#include <qwidget.h>
// class QWidget;
#include <string>


class ParkingSpotSensor : public QWidget {
public:
    std::string ID;
    bool enabled;
    ParkingSpotSensor(std::string id);

    void enable(); // from sad
    void disable(); // from sad
};


#endif //CS460_PROJECT_1_PARKINGSPOTSENSOR_H