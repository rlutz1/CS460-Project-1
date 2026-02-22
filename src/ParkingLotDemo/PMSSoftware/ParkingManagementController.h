//
// Created by lutzr on 2/22/2026.
//

#ifndef CS460_PROJECT_1_PARKINGMANAGEMENTCONTROLLER_H
#define CS460_PROJECT_1_PARKINGMANAGEMENTCONTROLLER_H

#include <string>
#include "../ParkingLot/ParkingLot.h"

namespace PMS {
    class ParkingManagementController {
    public:
        ParkingManagementController();

        void add_output_stream(ParkingLot::ParkingLot);
        void receive_signal(std::string str);
    private:
        ParkingLot::ParkingLot hardware_output_stream;

        void send_directive(std::string update); // TODO: this is TEMPORARY! for testing.
    };
} // PMS


#endif //CS460_PROJECT_1_PARKINGMANAGEMENTCONTROLLER_H