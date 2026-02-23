//
// Created by lutzr on 2/22/2026.
//

#ifndef CS460_PROJECT_1_PARKINGMANAGEMENTCONTROLLER_H
#define CS460_PROJECT_1_PARKINGMANAGEMENTCONTROLLER_H

#include <string>
class Mediator;

// namespace PMS {
    class ParkingManagementController {
    public:
        ParkingManagementController();

        void add_output_stream(Mediator* pl);
        void receive_signal(std::string str);
        void send_directive(std::string update); // TODO: this is TEMPORARY! for testing.
    private:
        Mediator* mediator;
        std::string update;
    };
// } // PMS


#endif //CS460_PROJECT_1_PARKINGMANAGEMENTCONTROLLER_H