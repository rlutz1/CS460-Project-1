//
// Created by Eliud Garcia on 2/24/26.
//

#include "CentralGateController.h"
#include "../ParkingManagementController.h"
#include <iostream>

CentralGateController::CentralGateController() = default;

//TODO: implement logic for GateController <-> PMC communication.

void CentralGateController::moveGate(GateId gateId, bool toOpen) {
	if (gateId.type == ENTRANCE) {
		if (entranceGateController) {
			if (toOpen) entranceGateController->open();
			else entranceGateController->close();
		}
	} else if (gateId.type == EXIT) {
		if (exitGateController) {
			if (toOpen) exitGateController->open();
			else exitGateController->close();
		}
	}
}


void CentralGateController::notifyVehicleSensed(GateId gateId) {
    // tell PMS about car at gate.
    // EXPECTED SIDE EFFECT: pms signals open request to gate.
	// Here is the way I implemented it (Feel free to change)
	if (pmc) pmc->vehicleSensed(gateId);
}
void CentralGateController::notifyVehicleAbsent(GateId gateId) {
    // tell PMS about car passed gate.
    // EXPECTED SIDE EFFECT: PMS calls door to close.
    // EXPECTED SIDE EFFECT 2: PMS called for successful entry/exit.
	// Here is the way I implemented it (Feel free to change)
	if (pmc) pmc->vehicleAbsent(gateId);
}

void CentralGateController::notifySuccessfulEntry(GateId gateId) {
    // TODO: tell PMS to increment in-transit by 1.
	// Here is the way I implemented it (Feel free to change)
	if (pmc) pmc->successfulEntry(gateId);
}

void CentralGateController::notifySuccessfulExit(GateId gateId) {
    // TODO: tell PMS to decrement in-transit by 1.
	// Here is the way I implemented it (Feel free to change)
	if (pmc) pmc->successfulExit(gateId);
}


// CentralGateController
void CentralGateController::setEntranceGate(GateController& newEntranceGateController) {
    //*entranceGateController = newEntranceGateController;
	// I think you want to assign the address, not the dereference null (I could be so wrong,
	// uncomment the other one if I am)
	entranceGateController = &newEntranceGateController;
}

void CentralGateController::setExitGate(GateController& newExitGateController) {
    //*exitGateController = newExitGateController;
	// I think you want to assign the address, not the dereference null (I could be so wrong,
	// uncomment the other one if I am)
	exitGateController = &newExitGateController;
}

void CentralGateController::setPMC(ParkingManagementController& newPMC) {
    //*pmc = newPMC;
	// I think you want to assign the address, not the dereference null (I could be so wrong,
	// uncomment the other one if I am)
	pmc = &newPMC;
}
