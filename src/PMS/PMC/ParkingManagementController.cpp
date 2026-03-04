//
// Created by Eliud Garcia on 2/24/26.
//

#include "ParkingManagementController.h"
#include "../Initialization.h"
#include "../PMSGUI/DemoManager.h"
#include "../PMSGUI/Availability/AvailabilityGUI.h"

ParkingManagementController::ParkingManagementController(
	const InitializationPackage& initPackage,
	const IAvailabilityInstructionSink& availPtr,
	const DemoManager& demoManager
	)
	: lot(initPackage, demoManager),
      totalSpots(0),
      vehiclesInside(0),
	  centralGate(demoManager.parkingLot->gate->entranceGate, demoManager.parkingLot->gate->exitGate),
      availabilityDisplay((IAvailabilityInstructionSink*) &availPtr)
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

void ParkingManagementController::successfulEntry() {
	vehiclesInside++;
	availabilityDisplay.updateInTransit(true);
	int remaining = totalSpots - vehiclesInside;
	availabilityDisplay.updateLogMessage(remaining > 0 ? "LOT OPEN" : "FULL");
}

void ParkingManagementController::successfulExit() {
	vehiclesInside--;
	availabilityDisplay.updateInTransit(false);
	int remaining = totalSpots - vehiclesInside;
	availabilityDisplay.updateLogMessage(remaining > 0 ? "LOT OPEN" : "FULL");
}

void ParkingManagementController::vehicleParked(SpotId spotId) {
	availabilityDisplay.updateInTransit(false);

	// hardcoded values based on run_demo.cpp constraint of 2 floors.
	int floorNum;
	if (spotId.floorId.uniqueId == "floor1") {
		floorNum = 1;
	}else if (spotId.floorId.uniqueId == "floor1"){
		floorNum = 2;
	}
	availabilityDisplay.updateAvailabilityTracking(spotId.type, floorNum, false);
	// signal spotId parking spot to be UNavailable.
	lot.markParkingSpotAvailability(spotId, floorNum, false); // false === unavailable
}

void ParkingManagementController::vehicleUnparked(SpotId spotId) {
	availabilityDisplay.updateInTransit(true);

	// hardcoded values based on run_demo.cpp constraint of 2 floors.
	int floorNum;
	if (spotId.floorId.uniqueId == "floor1") {
		floorNum = 1;
	}else if (spotId.floorId.uniqueId == "floor1"){
		floorNum = 2;
	}
	availabilityDisplay.updateAvailabilityTracking(spotId.type, floorNum, true);
	// signal spotId parking spot to be available.
	lot.markParkingSpotAvailability(spotId, floorNum, true); // true === available
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




