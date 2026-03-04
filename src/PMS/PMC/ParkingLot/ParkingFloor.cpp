//
// Created by Eliud Garcia on 2/24/26.
//

#include "ParkingFloor.h"
#include "ParkingLot.h"

ParkingFloor::ParkingFloor(const FloorId& id, ParkingLot& lot)
	: id(id), lot(lot), state(State::OPEN)
{
	// This should initialize all type counts to zero
	availableCounts[NORMAL] = 0;
	availableCounts[HANDICAP] = 0;
	availableCounts[EV] = 0;
	availableCounts[MOTORCYCLE] = 0;
}

int ParkingFloor::getCurrentAvailableCount(SpotType type) const
{
	auto it = availableCounts.find(type);
	return (it != availableCounts.end()) ? it->second : 0;
}

void ParkingFloor::notifySpotStateChanged(SpotType type, ParkingSpotController::State oldState,
                                          ParkingSpotController::State newState)
{
	// This should update the available count based on the transition into/out of AVAILABLE
	if (oldState == ParkingSpotController::State::AVAILABLE && newState != ParkingSpotController::State::AVAILABLE)
	{
		availableCounts[type]--;
		if (id.uniqueId == "floor1") {
			lot.notifyFloorStateChanged(type, oldState, newState, 1);
		} else {
			lot.notifyFloorStateChanged(type, oldState, newState, 2);
		}
	}
	else if (oldState != ParkingSpotController::State::AVAILABLE && newState ==
		ParkingSpotController::State::AVAILABLE)
	{
		availableCounts[type]++;
		if (id.uniqueId == "floor1") {
			lot.notifyFloorStateChanged(type, oldState, newState, 1);
		} else {
			lot.notifyFloorStateChanged(type, oldState, newState, 2);
		}
	}
	// This should re-evaluate the floor state
	updateState();
	// This should notify the parking lot so it can update the overall counts
}

void ParkingFloor::notifySpotTypeChanged(SpotType oldType, SpotType newType, ParkingSpotController::State currentState)
{
	/* This should adjust the counts: if the spot was AVAILABLE, it contributed to the oldType;
	 * now it contributes to newType */
	if (currentState == ParkingSpotController::State::AVAILABLE)
	{
		availableCounts[oldType]--;
		availableCounts[newType]++;
	}
	// TODO: Maybe have something here that indicated that the lot is listening to the spot type changes...idk
}

void ParkingFloor::addSpot(std::unique_ptr<ParkingSpotController> spot)
{
	if (spot->getState() == ParkingSpotController::State::AVAILABLE)
	{
		availableCounts[spot->getSpotType()]++;
	}
	spots.push_back(std::move(spot));
}


void ParkingFloor::updateParkingSpotAvailability(SpotId spotId, SensorId sensorId, bool available) {
	for (auto& parkingSpot: spots ) {
		bool spotIdsMatch = parkingSpot->id.uniqueId == spotId.uniqueId;
		if (spotIdsMatch) {
			// this is a simulation only logic to ensure that the update is consistent.
			parkingSpot->updateSpotAvailability(sensorId, available);
			break;
		}
	}
}


void ParkingFloor::updateState()
{
	// The floor is FULL if no spots are AVAILABLE, not including the UNAVAILABLE spots
	int totalAvailable = 0;
	for (const auto& pair : availableCounts)
	{
		totalAvailable += pair.second;
	}
	State newState = (totalAvailable == 0) ? State::FULL : State::OPEN;
	if (newState != state)
	{
		state = newState;
	}
}
