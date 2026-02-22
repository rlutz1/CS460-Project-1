//
// Created by lutzr on 2/22/2026.
//

#ifndef CS460_PROJECT_1_PARKINGLOT_H
#define CS460_PROJECT_1_PARKINGLOT_H

#include "../PMSSoftware/ParkingManagementController.h"

namespace ParkingLot {
    class ParkingLot {
    public:
        PMS::ParkingManagementController signal_output_stream;

        ParkingLot();
        ParkingLot(PMS::ParkingManagementController pmc);

        void add_output_stream(PMS::ParkingManagementController pmc);
        void hardware_update(std::string str);
    private:
        void send_signal();
    };
} // ParkingLot

#endif //CS460_PROJECT_1_PARKINGLOT_H