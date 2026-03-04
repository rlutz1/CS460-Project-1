//
// Created by Eliud Garcia on 2/24/26.
//

#include "CentralGateController.h"
#include "../ParkingManagementController.h"
#include <iostream>

CentralGateController::CentralGateController(IGateInstructionSink* entranceGate, IGateInstructionSink* exitGate) :
	entranceGateController(entranceGate),
	exitGateController(exitGate)
{
}

//TODO: implement logic for GateController <-> PMC communication.

void CentralGateController::moveGate(GateId gateId, bool toOpen) {
	if (gateId.type == ENTRANCE) {
		if (toOpen) entranceGateController.open();
		else entranceGateController.close();
	} else if (gateId.type == EXIT) {
		if (toOpen) exitGateController.open();
		else exitGateController.close();
	}
}
