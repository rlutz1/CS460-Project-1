//
// Created by Eliud Garcia on 2/24/26.
//

#include "GateController.h"
#include "../PMCInterfaces/IGateInstructionSink.h"
#include "CentralGateController.h"




void GateController::open() {
	if (gateHardware) {
		gateHardware->signalGateOpen();
	}
}

void GateController::close() {
    if (gateHardware) {
        gateHardware->signalGateClose();
    }
}

void GateController::setGateHardware(IGateInstructionSink& newGateHardware) {
    //*gateHardware = newGateHardware;
	// I think you want to assign the address, not the dereference null (I could be so wrong,
	// uncomment the other one if I am)
	gateHardware = &newGateHardware;
}


void GateController::setGateId(GateId newGateId) {
    gateId = newGateId;
}

