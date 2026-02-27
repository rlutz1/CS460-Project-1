//
// Created by Eliud Garcia on 2/24/26.
//

#include "ParkingManagementController.h"
#include "../Initialization.h"

ParkingManagementController::ParkingManagementController(InitializationPackage initPackage) : lot(initPackage),
	totalSpots(0), vehiclesInside(0)
{
	// This should calculate the total spots from the initialization numbers
	const auto& nums = initPackage.numbers;
	totalSpots = nums.totalNormalSpots + nums.totalHandicapSpots + nums.totalEvSpots + nums.totalMotorcycleSpots;

	// This is how the gate controllers are set up (Trying to go of the way the gates are written)

	// This is where the individual gate controllers are created
	GateController entranceGate;
	GateController exitGate;

	// This is where the gate IDs are set which is provided by initPackage
	entranceGate.setGateId(initPackage.entranceGateId);
	exitGate.setGateId(initPackage.exitGateId);

	// This is where the hardware sinks are set
	entranceGate.setGateHardware(entranceHardware);
	exitGate.setGateHardware(exitHardware);

	// This is where the central controller reference is set in each gate
	entranceGate.setCentralGateController(centralGate);
	exitGate.setCentralGateController(centralGate);

	// This is where the gates are registered with the central controller
	centralGate.setEntranceGate(entranceGate);
	centralGate.setExitGate(exitGate);

	// TODO:This is where the PMC is set as the central controller's callback target (Need to fix later)
	//centralGate.setPMC(*this);

	// TODO: Availability controller NEEDS to be implemented and referenced here

	// TODO: Gate event handlers NEEDS to be implemented and called by the CentralGateController
}
