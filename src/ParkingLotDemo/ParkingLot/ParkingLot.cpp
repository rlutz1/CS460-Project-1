//
// Created by lutzr on 2/22/2026.
//

#include "ParkingLot.h"

namespace ParkingLot {
    ParkingLot::ParkingLot() = default;

    ParkingLot::ParkingLot(PMS::ParkingManagementController pmc) {
        signal_output_stream = pmc;
    } // end constructor

    void ParkingLot::add_output_stream(PMS::ParkingManagementController pmc) {
        signal_output_stream = pmc;
    } // end method

    void ParkingLot::hardware_update(std::string str) {

    } // end method

    void ParkingLot::send_signal() {
        signal_output_stream.receive_signal("FROM PL: signal triggered!");
    } // end method
} // ParkingLot