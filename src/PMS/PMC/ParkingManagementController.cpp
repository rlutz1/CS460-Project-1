//
// Created by Eliud Garcia on 2/24/26.
//

#include "ParkingManagementController.h"
#include "../Initialization.h"

ParkingManagementController::ParkingManagementController(const InitializationPackage& initPackage)
	: lot(initPackage), totalSpots(0), vehiclesInside(0), centralGate(), availabilityDisplay()
{
	// This should calculate the total spots from the initialization numbers
	const auto& nums = initPackage.numbers;
	totalSpots = nums.totalNormalSpots + nums.totalHandicapSpots + nums.totalEvSpots + nums.totalMotorcycleSpots;

	// Using purely constructors to build them
	// (to avoid temporary objects that don't
	// live through the lifetime of the program).

	availabilityDisplay.updateLogMessage("System Ready");


	// TODO:This is where the PMC is set as the central controller's callback target (Need to fix later)



	// TODO: Availability controller NEEDS to be implemented and referenced here

	// TODO: Gate event handlers NEEDS to be implemented and called by the CentralGateController
}

void ParkingManagementController::vehicleSensed(GateId gateId) {
	if (gateId.type == ENTRANCE) {
		if (vehiclesInside < totalSpots) {
			centralGate.moveGate(gateId, true);
		} else {
			availabilityDisplay.updateLogMessage("FULL");
		}
	} else if (gateId.type == EXIT) {
		centralGate.moveGate(gateId, true);
	}
}

// These are the gate event handlers
void ParkingManagementController::vehicleAbsent(GateId gateId) {
	centralGate.moveGate(gateId, false);
}

void ParkingManagementController::successfulEntry(GateId) {
	vehiclesInside++;
	availabilityDisplay.updateInTransit(true);
	int remaining = totalSpots - vehiclesInside;
	availabilityDisplay.updateLogMessage(remaining > 0 ? "Spaces Available" : "FULL");
}

void ParkingManagementController::successfulExit(GateId) {
	vehiclesInside--;
	availabilityDisplay.updateInTransit(false);
	int remaining = totalSpots - vehiclesInside;
	availabilityDisplay.updateLogMessage(remaining > 0 ? "Spaces Available" : "FULL");
}

// This is where the parking spot sensor is handled
void ParkingManagementController::handleSensorTrigger(const SensorId& sensor, bool detected)
{
	ParkingSpotController* spot = findSpotBySensor(sensor);
	if (!spot) return;

	spot->updateSpotAvailability(sensor, detected);

	// TODO: Might need some more info from the ParkingSpotController
	// For now I'll just update the whole lot display for the type
	int available = lot.getCurrentAvailableCount(spot->getSpotType());
}

void ParkingManagementController::updateLogMessage(const std::string& msg) {
	availabilityDisplay.updateLogMessage(msg);
}

int ParkingManagementController::getTotalAvailable(SpotType type) const {
	return lot.getCurrentAvailableCount(type);
}

ParkingLot::State ParkingManagementController::getLotState() const {
	return lot.getState();
}

ParkingSpotController* ParkingManagementController::findSpotBySensor(const SensorId& sensor) {
	// TODO: This would need a lookup map in ParkingLot I think
	// For now, I'll return a nullptr
	return nullptr;
}

/**
 * TODO: change the old absent/present for these ones (merge them).
 */
// void ParkingManagementController::SensedVehicle(SensorId sensorID) {
//     if ( sensorID.uniqueId == "entranceGateInitOpen" || sensorID.uniqueId == "exitGateInitOpen" ) {
//         // signal to central gate controller about the sensor sensing vehicle -> open entrance/exit
//         centralGateController->notifyVehicleSensed(gateId);
//     } else if ( sensorID.uniqueId == "entranceGateStayOpen" || sensorID.uniqueId == "exitGateStayOpen" ) {
//         vehicleWasAtInteriorSensor = true;
//     }
// }
// void ParkingManagementController::NotSensedVehicled(SensorId sensorID) {
//     // TODO: further implementation for actual sensor Ids for gates.
//     if ( vehicleWasAtInteriorSensor
//         && (sensorID.uniqueId == "entranceGateStayOpen" || sensorID.uniqueId == "exitGateStayOpen") ) {
//         // signal to central gate controller about the exterior sensor not sensed anymore, i.e. passed -> close entrance/exit.
//         centralGateController->notifyVehicleAbsent(gateId);
//         vehicleWasAtInteriorSensor = false;
//     }
// }
