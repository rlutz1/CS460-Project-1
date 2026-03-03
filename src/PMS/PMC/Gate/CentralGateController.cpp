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