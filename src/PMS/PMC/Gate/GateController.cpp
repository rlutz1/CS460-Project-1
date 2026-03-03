//
// Created by Eliud Garcia on 2/24/26.
//

#include "GateController.h"

#include "../PMCInterfaces/IGateInstructionSink.h"

#include "CentralGateController.h"




void GateController::open() {
    gateHardware->signalGateOpen();
}

void GateController::close() {
    gateHardware->signalGateClose();
}

void GateController::setGateHardware(IGateInstructionSink& newGateHardware) {
    *gateHardware = newGateHardware;
}


void GateController::setGateId(GateId newGateId) {
    gateId = newGateId;
}

