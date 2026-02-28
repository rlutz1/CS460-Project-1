//
// Created by Eliud Garcia on 2/24/26.
//

#include "ParkingFloor.h"
#include "ParkingLot.h"

ParkingFloor::ParkingFloor(const FloorId& id, ParkingLot& lot)
	: id(id), lot(lot), state(State::OPEN) {
	// This should initialize all type counts to zero
	availableCounts[NORMAL] = 0;
	availableCounts[HANDICAP] = 0;
	availableCounts[EV] = 0;
	availableCounts[MOTORCYCLE] = 0;
}

