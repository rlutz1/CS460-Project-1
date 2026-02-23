//
// Created by lutzr on 2/22/2026.
//

#include "ParkingLot.h"
#include "../Mediator/Mediator.h"
#include <iostream>

// namespace ParkingLot {
ParkingLot::ParkingLot() = default;

ParkingLot::ParkingLot(Mediator* m) {
    this -> mediator = m;
} // end constructor

void ParkingLot::add_output_stream(Mediator* m) {
    this -> mediator = m;
} // end method

void ParkingLot::hardware_update(std::string str) {
    std::cout << "PL: Received Update to Hardware: "<< str << "\n";
    if (str == "1") {
        this -> button -> setStyleSheet("background-color: red; color: white;");
    } else {
        this -> button -> setStyleSheet("");
    }8i
} // end method

void ParkingLot::add_component(void* component) {
    this -> button = (QPushButton*) component;
}

void ParkingLot::send_signal() {
    this -> mediator -> send_to_PMC("FROM PL: signal triggered!");
} // end method
// } // ParkingLot