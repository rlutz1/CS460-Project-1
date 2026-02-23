//
// Created by lutzr on 2/22/2026.
//

#ifndef CS460_PROJECT_1_MEDIATOR_H
#define CS460_PROJECT_1_MEDIATOR_H

// #include "../PMSSoftware/ParkingManagementController.h"
// #include "../ParkingLot/ParkingLot.h"

class ParkingLot;
class ParkingManagementController;

class Mediator {

public:
    ParkingLot* hardware_update_stream;
    ParkingManagementController* signal_stream;

    Mediator();
    Mediator(ParkingLot* hardware_update_stream, ParkingManagementController* signal_stream);

    void send_to_PMC(std::string update);
    void send_to_PL(std::string update);

private:

};


#endif //CS460_PROJECT_1_MEDIATOR_H