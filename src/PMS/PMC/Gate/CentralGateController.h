//
// Created by Eliud Garcia on 2/24/26.
//

#ifndef CS460_PROJECT_1_GATECONTROLLER_H
#define CS460_PROJECT_1_GATECONTROLLER_H
#include "GateController.h"
#include "../ParkingManagementController.h"
#include "../../Definitions/Identifiers.h"


class CentralGateController
{
public:
    CentralGateController();
    ~CentralGateController() = default;
    // for the gates to be notified
    void moveGate(GateId gateId, bool toOpen);

    // for PMS notifying
    void notifyVehicleSensed(GateId gateId);
    void notifyVehicleAbsent(GateId gateId);
    void notifySuccessfulEntry(GateId gateId);
    void notifySuccessfulExit(GateId gateId);

    // CentralGateController
    void setEntranceGate(GateController& newEntranceGateController);
    void setExitGate(GateController& newExitGateController);
    void setPMC(ParkingManagementController& newPMC);

private:
    GateController* entranceGateController = nullptr;
    GateController* exitGateController = nullptr;
    ParkingManagementController* pmc = nullptr;
};


#endif //CS460_PROJECT_1_GATECONTROLLER_H