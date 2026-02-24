//
// Created by lutzr on 2/22/2026.
//

#include "ParkingManagementController.h"
#include "../Mediator/Mediator.h"
#include <iostream>
#include <string>



// namespace PMS {
ParkingManagementController::ParkingManagementController() {
    this -> update = "1";
};

void ParkingManagementController::add_output_stream(Mediator* m) {
    this -> mediator = m;
    this -> update = "1";
} // end method

// TODO: only point of this right now is to print something out to confirm comms
void ParkingManagementController::send_directive(std::string update) {
    this -> mediator -> send_to_PL(update);
} // end method

// ENTRY POINT FOR RECEIVING SIGNALS FROM "SENSORS"
void ParkingManagementController::receive_signal(std::string update) {
    std::cout << "PMC: Received Signal: " << update << "\n";
    // TESTING ONLY
    std::string delimiter = "|"; // hardcoded
    std::string notification = update.substr(1, update.find(delimiter)); // notification is special key
    if (notification == "PARKED") {
        // yada yada, do some checking, updating internal states.
        // effectively, we just received 2 sensor signals for someone occupying a spot
        send_directive(update.substr(0, update.find(delimiter)) + "|OCCUPIED_CHANGE_COLOR");
    } else if (notification == "UNPARKED") {
        send_directive(update.substr(0, update.find(delimiter)) + "|AVAILABLE_CHANGE_COLOR");
    }
    // this -> update = "2";
} // end method

// } // PMS