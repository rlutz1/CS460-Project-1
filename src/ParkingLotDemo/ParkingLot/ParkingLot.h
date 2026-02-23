//
// Created by lutzr on 2/22/2026.
//

#ifndef CS460_PROJECT_1_PARKINGLOT_H
#define CS460_PROJECT_1_PARKINGLOT_H

#include <string>
// #include "../Mediator/Mediator.h"
class Mediator;

// namespace ParkingLot {
class ParkingLot {

public:
    ParkingLot();
    ParkingLot(Mediator* pmc);

    void add_output_stream(Mediator* pmc);
    void hardware_update(std::string str);
    void send_signal();
private:
    Mediator* mediator;
};
// } // ParkingLot

#endif //CS460_PROJECT_1_PARKINGLOT_H