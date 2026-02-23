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

void ParkingManagementController::receive_signal(std::string str) {
    std::cout << "PMC: Received Signal: " << str << "\n";
    send_directive(this -> update);
    this -> update = "2";
} // end method
// } // PMS