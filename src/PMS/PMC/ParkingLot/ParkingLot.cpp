//
// Created by Ayman Hassen on 2/25/26.
//

#include "ParkingLot.h"
#include "ParkingFloor.h"
#include <map>

#include "../../PMSGUI/ParkingLot/ParkingSpotGUI.h"
#include "../PMCInterfaces/IParkingSpotHardwareSink.h"

//Added to match call in header file
ParkingLot::~ParkingLot() = default;

ParkingLot::ParkingLot(
	const InitializationPackage &initPackage,
	QVector<QPointer<ParkingSpotGUI>> spotsFloor1,
	QVector<QPointer<ParkingSpotGUI>> spotsFloor2
)
{
	// This should collect the unique floor IDs from all the spots
	std::map<std::string, std::unique_ptr<ParkingFloor>> floorMap;
	for (const auto& spotId : initPackage.spotIds)
	{
		const auto& floorIdStr = spotId.floorId.uniqueId;
		if (floorMap.find(floorIdStr) == floorMap.end())
		{
			floorMap[floorIdStr] = std::make_unique<ParkingFloor>(spotId.floorId, *this);
		}
	}

	// This should create spots and add them to the appropriate floor
	for (const auto& spotId : initPackage.spotIds)
	{
		auto& floor = floorMap[spotId.floorId.uniqueId];
		auto spot = std::make_unique<ParkingSpotController>(spotId, *floor);

		// Add the hardware to the corresponding spot from the DemoManager:
		for (auto hardware : spotsFloor1) {
			if (hardware->spotId.uniqueId == spotId.uniqueId) {
				spot->spotHardware = hardware;
				break;
			} // end if
		}

		for (auto hardware : spotsFloor2) {
			if (hardware->spotId.uniqueId == spotId.uniqueId) {
				spot->spotHardware = hardware;
				break;
			} // end if
		} // end if
		// end adding of hardware

		floor->addSpot(std::move(spot));
	}

	// This should transfer the floors from map to vector
	for (auto& pair : floorMap)
	{
		floors.push_back(std::move(pair.second));
	}

	// This should initialize the total counts by summing up the floor counts
	for (SpotType type : {NORMAL, HANDICAP, EV, MOTORCYCLE})
	{
		totalAvailableCounts[type] = 0;
	}
	for (const auto& floor : floors)
	{
		for (SpotType type : {NORMAL, HANDICAP, EV, MOTORCYCLE})
		{
			totalAvailableCounts[type] += floor->getCurrentAvailableCount(type);
		}
	}
	updateState();
}

int ParkingLot::getCurrentAvailableCount(SpotType type) const
{
	auto it = totalAvailableCounts.find(type);
	return (it != totalAvailableCounts.end()) ? it->second : 0;
}

void ParkingLot::notifyFloorStateChanged(SpotType type, ParkingSpotController::State oldState,
                                         ParkingSpotController::State newState)
{
	// This should update the overall counts
	if (oldState == ParkingSpotController::State::AVAILABLE && newState != ParkingSpotController::State::AVAILABLE)
	{
		totalAvailableCounts[type]--;
	}
	else if (oldState != ParkingSpotController::State::AVAILABLE && newState ==
		ParkingSpotController::State::AVAILABLE)
	{
		totalAvailableCounts[type]++;
	}
	updateState();
}


void ParkingLot::updateParkingSpotAvailability(SpotId spotId, int floor, bool available) {
	// check which floor we will go to:
	floors[floor - 1]->updateParkingSpotAvailability(spotId, available);
}

void ParkingLot::updateState()
{
	// This says that the lot is FULL if the total available spots (all types) is zero
	int total = 0;
	for (const auto& pair : totalAvailableCounts)
	{
		total += pair.second;
	}
	State newState = (total == 0) ? State::FULL : State::OPEN;
	if (newState != state)
	{
		state = newState;
		// TODO: This is where it could notify higher-level controller but idk if that's needed
	}
}
