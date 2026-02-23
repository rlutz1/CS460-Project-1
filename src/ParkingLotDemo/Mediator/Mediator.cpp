//
// Created by lutzr on 2/22/2026.
//

#include "../PMSSoftware/ParkingManagementController.h"
#include "../ParkingLot/ParkingLot.h"
#include "Mediator.h"

#include <string>

Mediator::Mediator() = default;

Mediator::Mediator(ParkingLot *hardware_update_stream, ParkingManagementController *signal_stream) {
    this -> hardware_update_stream = hardware_update_stream;
    this -> signal_stream = signal_stream;
}

void Mediator::send_to_PL(std::string update) {
    hardware_update_stream -> hardware_update(update);
}

void Mediator::send_to_PMC(std::string update) {
    signal_stream -> receive_signal(update);
}
