//
// Created by Eliud Garcia on 2/24/26.
//

#include "ParkingSpotController.h"
#include "ParkingFloor.h"
#include "../PMCInterfaces/IParkingSpotHardwareSink.h"
#include <iostream>

// Initializing a ParkingSpotController object
ParkingSpotController::ParkingSpotController(const SpotId& id, ParkingFloor& floor) : id(id), floor(floor),
	state(State::AVAILABLE), weightDetected(false), ultrasonicDetected(false)
{
}

void ParkingSpotController::updateSpotAvailability(const SensorId& sensor, bool vehicleDetected)
{
	// This should identify which sensor is triggered
	if (sensor.uniqueId == id.ultrasonicId.uniqueId)
	{
		ultrasonicDetected = vehicleDetected;
	}
	else if (sensor.uniqueId == id.weightId.uniqueId)
	{
		weightDetected = vehicleDetected;
	}
	else
	{
		// The sensor doesn't belong to this spot (should ignore)
		return;
	}
	updateStateFromSensors();

	if (state == State::AVAILABLE)
	{
		spotHardware->markSpotAvailable();
	} else if (state == State::OCCUPIED)
	{
		spotHardware->markSpotOccupied();
	}
}


void ParkingSpotController::updateStateFromSensors()
{
	// TODO: This can be for the admin override
	if (state == State::UNAVAILABLE) return;


	State newState = (weightDetected && ultrasonicDetected) ? State::AVAILABLE : State::OCCUPIED;


	if (newState != state)
	{
		State oldState = state;
		state = newState;
		// TODO: Make sure this is added correctly after finishing ParkingFloor
		floor.notifySpotStateChanged(id.type, oldState, newState);
	}

	if (state == State::AVAILABLE) {
		std::cout << "avail" << std::endl;
	} else if (state == State::OCCUPIED) {
		std::cout << "occupied" << std::endl;
	}

}

// TODO: Something for admin override forcing unavailable (might be useless)
void ParkingSpotController::forceUnavailable()
{
	if (state != State::UNAVAILABLE)
	{
		State oldState = state;
		state = State::UNAVAILABLE;
		spotHardware->markSpotUnavailable();
		floor.notifySpotStateChanged(id.type, oldState, state);
	}
}

// Might need methods for configuring sensors here idkK


