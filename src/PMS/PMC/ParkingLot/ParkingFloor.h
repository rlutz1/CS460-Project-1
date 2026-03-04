//
// Created by Eliud Garcia on 2/24/26.
//

#ifndef CS460_PROJECT_1_PARKINGFLOOR_H
#define CS460_PROJECT_1_PARKINGFLOOR_H

#include "../../Definitions/Identifiers.h"
#include "ParkingSpotController.h"
#include <vector>
#include <map>
#include <memory>

class ParkingLot;


class ParkingFloor
{
public:
	enum class State
	{
		OPEN,
		FULL
	};

	ParkingFloor(const FloorId& id, ParkingLot& lot);
	// This should get the number of available spots of a give type on this floor which is stated in the SAD
	int getCurrentAvailableCount(SpotType type) const;

	// This should be called by a spot when its state changes (i.e. AVAILABLE <-> OCCUPIED/UNAVAILABLE)
	void notifySpotStateChanged(SpotType type, ParkingSpotController::State oldState,
	                            ParkingSpotController::State newState);

	// This is called when a spot's type changes, and it should adjust the counts
	void notifySpotTypeChanged(SpotType oldType, SpotType newType, ParkingSpotController::State currentState);

	// This should add a spot during the initialization
	void addSpot(std::unique_ptr<ParkingSpotController> spot);

	// The necessary Getters
	State getState() const
	{
		return state;
	}

	const FloorId& getId() const
	{
		return id;
	}


	void updateParkingSpotAvailability(SpotId spotId, bool available);
	FloorId id;
	std::vector<std::unique_ptr<ParkingSpotController>> spots;


private:
	ParkingLot& lot;
	State state;
	// Contains the available spots per type
	std::map<SpotType, int> availableCounts;

	// This should reconfigure the floor state (i.e. OPEN/FULL)
	void updateState();
};


#endif //CS460_PROJECT_1_PARKINGFLOOR_H
