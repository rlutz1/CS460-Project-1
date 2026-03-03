//
// Created by Eliud Garcia on 2/24/26.
//

#include "GateController.h"
#include "../PMCInterfaces/IGateInstructionSink.h"
#include "CentralGateController.h"

void GateController::SensedVehicle(SensorId sensorID) {
    if ( sensorID.uniqueId == "entranceGateInitOpen" || sensorID.uniqueId == "exitGateInitOpen" ) {
        // signal to central gate controller about the sensor sensing vehicle -> open entrance/exit
        centralGateController->notifyVehicleSensed(gateId);
    } else if ( sensorID.uniqueId == "entranceGateStayOpen" || sensorID.uniqueId == "exitGateStayOpen" ) {
        vehicleWasAtInteriorSensor = true;
    }
}
void GateController::NotSensedVehicled(SensorId sensorID) {
    // TODO: further implementation for actual sensor Ids for gates.
    if ( vehicleWasAtInteriorSensor
        && (sensorID.uniqueId == "entranceGateStayOpen" || sensorID.uniqueId == "exitGateStayOpen") ) {
        // signal to central gate controller about the exterior sensor not sensed anymore, i.e. passed -> close entrance/exit.
        centralGateController->notifyVehicleAbsent(gateId);
        vehicleWasAtInteriorSensor = false;
    }
}

void GateController::open() {
	if (gateHardware) {
		gateHardware->signalGateOpen();
	}
}

void GateController::close() {
	if (gateHardware) {
		gateHardware->signalGateClose();
	}
	// Notify central controller of successful entry/exit
	if (centralGateController) {
		if (gateId.type == ENTRANCE) {
			centralGateController->notifySuccessfulEntry(gateId);
		} else if (gateId.type == EXIT) {
			centralGateController->notifySuccessfulExit(gateId);
		}
	}
}

void GateController::setGateHardware(IGateInstructionSink& newGateHardware) {
    //*gateHardware = newGateHardware;
	// I think you want to assign the address, not the dereference null (I could be so wrong,
	// uncomment the other one if I am)
	gateHardware = &newGateHardware;
}

void GateController::setCentralGateController(CentralGateController& newCentGateController) {
   // *centralGateController = newCentGateController;
   // I think you want to assign the address, not the dereference null (I could be so wrong,
   // uncomment the other one if I am)
	centralGateController = &newCentGateController;
}

void GateController::setGateId(GateId newGateId) {
    gateId = newGateId;
}

