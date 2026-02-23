//
// Created by lutzr on 2/22/2026.
//

#include "ParkingLot.h"
#include "../Mediator/Mediator.h"
#include <iostream>

#include "ParkingSpot.h"

// namespace ParkingLot {
ParkingLot::ParkingLot() = default;

ParkingLot::ParkingLot(Mediator* m) {
    this -> mediator = m;
    // TODO hardcoded to test
    ParkingSpot spot1("Vehicle 1"); ParkingSpot spot2("Vehicle 2"); ParkingSpot spot3("Vehicle 3");
    this -> parking_spots = {&spot1, &spot2, &spot3};
} // end constructor

void ParkingLot::add_output_stream(Mediator* m) {
    this -> mediator = m;
} // end method

void ParkingLot::hardware_update(std::string str) {
    // std::cout << "PL: Received Update to Hardware: "<< str << "\n";
    // if (str == "1") {
    //     this -> button -> setStyleSheet("background-color: red; color: white;");
    // } else {
    //     this -> button -> setStyleSheet("");
    // }
} // end method

// void ParkingLot::add_component(void* component) {
//     this -> button = (QPushButton*) component;
// }

void ParkingLot::send_signal() {
    this -> mediator -> send_to_PMC("FROM PL: signal triggered!");
} // end method

QSize ParkingLot::sizeHint() const {
    return QSize(500, 400);
}

// } // ParkingLot
