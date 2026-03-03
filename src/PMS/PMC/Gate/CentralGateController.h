//
// Created by Eliud Garcia on 2/24/26.
//

#ifndef CS460_PROJECT_1_GATECONTROLLER_H
#define CS460_PROJECT_1_GATECONTROLLER_H
#include "GateController.h"

#include "../../Definitions/Identifiers.h"


class ParkingManagementController;

class CentralGateController
{
public:
    CentralGateController();
    ~CentralGateController() = default;
    // for the gates to be notified
    void moveGate(GateId gateId, bool toOpen);

private:
    GateController entranceGateController;
    GateController exitGateController;
};


#endif //CS460_PROJECT_1_GATECONTROLLER_H