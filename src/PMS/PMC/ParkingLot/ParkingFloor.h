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



class ParkingFloor {
	public:
		enum class State
		{
			OPEN,
			FULL
		};
	ParkingFloor(const FloorId& id, ParkingLot& lot);

	// This should get the number of available spots of a given type on this floor outlined in the SAD
	int getCurrentAvailableCount(SpotType type) const;

	// This should be called by a spot when its stage changes (i.e. AVAILABLE -> OCCUPIED or UNAVAILABLE)
	void notifyFloorStateChanged(SpotType type, ParkingSpotController::State oldState,
		ParkingSpotController::State newState);

	// State Getter
	State getState() const
	{
		return state;
	}
	private:
		State state;
		std::vector<std::unique_ptr<ParkingFloor>> floors;
		// Contains the overall available per parking spot type
		std::map<SpotType, int> totalAvailableCounts;
		// This should reconfigure the parking spot state (i.e. OPEN/FULL)
		void updateState();


};


#endif //CS460_PROJECT_1_PARKINGFLOOR_H