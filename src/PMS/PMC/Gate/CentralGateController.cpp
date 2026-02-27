//
// Created by Eliud Garcia on 2/24/26.
//

#include "CentralGateController.h"

//TODO: implmeent logic for GateController <-> PMC communication.

void CentralGateController::moveGate(GateId gateId, bool toOpen) {
    if ( gateId.type == ENTRANCE ) {
        if ( toOpen ) {
            entranceGateController->open();
        }else {
            entranceGateController->close();
        }
    }else if ( gateId.type == EXIT ) {
        if ( toOpen ) {
            exitGateController->open();
        }else {
            exitGateController->close();
        }
    }
}


void CentralGateController::notifyVehicleSensed(GateId gateId) {
    // tell PMS about car at gate.
    // EXPECTED SIDE EFFECT: pms signals open request to gate.
}
void CentralGateController::notifyVehicleAbsent(GateId gateId) {
    // tell PMS about car passed gate.
    // EXPECTED SIDE EFFECT: PMS calls door to close.
    // EXPECTED SIDE EFFECT 2: PMS called for successful entry/exit.
}

void CentralGateController::notifySuccessfulEntry(GateId gateId) {
    // TODO: tell PMS to increment in-transit by 1.
}

void CentralGateController::notifySuccessfulExit(GateId gateId) {
    // TODO: tell PMS to decrement in-transit by 1.
}


// CentralGateController
void CentralGateController::setEntranceGate(GateController& newEntranceGateController) {
    *entranceGateController = newEntranceGateController;
}

void CentralGateController::setExitGate(GateController& newExitGateController) {
    *exitGateController = newExitGateController;
}

void CentralGateController::setPMC(ParkingManagementController& newPMC) {
    *pmc = newPMC;
}
