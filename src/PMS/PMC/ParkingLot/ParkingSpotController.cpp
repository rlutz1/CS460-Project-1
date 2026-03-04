//
// Created by Eliud Garcia on 2/24/26.
//

#include "ParkingSpotController.h"
#include "ParkingFloor.h"
#include "../PMCInterfaces/IParkingSpotHardwareSink.h"

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
	else if (sensor.uniqueId == id.floorId.uniqueId)
	{
		weightDetected = vehicleDetected;
	}
	else
	{
		// The sensor doesn't belong to this spot (should ignore)
		return;
	}
	updateStateFromSensors();
}




/////////////////////////////////////// ///////////////////////////////////////
/**
 * this is coming from the "parking sensors".
 * we will cheat this just a little and assume both sensors trigger.
 * the update spot availabilities are here for a moment.
 * following todos: roxanne know's what to do
 */
void ParkingSpotController::markSpotAvailability(bool isAvailable) {
	if (isAvailable) {
		updateSpotAvailability(id.ultrasonicId, false); // TODO: this should really come from the sensors, if time
		updateSpotAvailability(id.weightId, false); // TODO: this should really come from the sensors, if time
		spotHardware->markSpotAvailable();
	} else {
		updateSpotAvailability(id.ultrasonicId, true); // TODO: this should really come from the sensors, if time
		updateSpotAvailability(id.weightId, true); // TODO: this should really come from the sensors, if time
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
		//floor.notifySpotStateChanged(id.type, oldState, newState);
	}
}

// TODO: Something for admin override forcing unavailable (might be useless)
void ParkingSpotController::forceUnavailable()
{
	if (state != State::UNAVAILABLE)
	{
		State oldState = state;
		state = State::UNAVAILABLE;
		//floor.notifySpotStateChanged(id.type, oldState, state);
	}
}

// Might need methods for configuring sensors here idkK


