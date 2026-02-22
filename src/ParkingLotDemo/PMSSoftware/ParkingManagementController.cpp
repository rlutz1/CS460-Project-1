//
// Created by lutzr on 2/22/2026.
//

#include "ParkingManagementController.h"
#include <iostream>
#include <string>
// #include "../ParkingLot/ParkingLot.h"

#define NULL 0 // may remove if bad practice

namespace PMS {
    ParkingManagementController::ParkingManagementController() = default;

    void ParkingManagementController::add_output_stream(const ParkingLot::ParkingLot pl) {
        hardware_output_stream = pl;
    } // end method

    // TODO: only point of this right now is to print something out to confirm comms
    void ParkingManagementController::send_directive(std::string update) {
        (hardware_output_stream).hardware_update(update);
    } // end method

    void ParkingManagementController::receive_signal(std::string str) {
        std::cout << "PMC: Received Signal: \n";
        std::cout << str;
        send_directive("FROM PMC: Received the signal.");
    } // end method
} // PMS