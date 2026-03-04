//
// Created by Ayman Hassen on 2/25/26.
//

#ifndef CS460_PROJECT_1_PARKINGLOT_H
#define CS460_PROJECT_1_PARKINGLOT_H

#include "../../Definitions/Identifiers.h"
#include "../../../PMS/Initialization.h"
#include "ParkingSpotController.h"
#include <vector>
#include <map>
#include <memory>
#include <QPointer>
#include <QVector>

class ParkingSpotGUI;
class DemoManager;
class ParkingSpotController;

class ParkingFloor;


class ParkingLot
{
public:
	~ParkingLot();
	enum class State
	{
		OPEN,
		FULL
	};

	// This constructor should build entire lot from initialization package
	ParkingLot(
		const InitializationPackage &initPackage,
		QVector<QPointer<ParkingSpotGUI>> spotsFloor1,
		QVector<QPointer<ParkingSpotGUI>> spotsFloor2
		);

	// This should get total available spots of a given type across all floors
	int getCurrentAvailableCount(SpotType type) const;

	// This should be called by a floor when a spot's state changes
	void notifyFloorStateChanged(SpotType type, ParkingSpotController::State oldState,
	                             ParkingSpotController::State newState);

	// The necessary getter
	State getState() const
	{
		return state;
	}


	/////////////////////////////////// ///////////////////////////////////
	// assumed to always take in a parking spot id.
	void updateParkingSpotAvailability(SpotId parkingSpotId, int floor, bool available);


private:
	State state;
	std::vector<std::unique_ptr<ParkingFloor>> floors;
	// Contains the available spots per type
	std::map<SpotType, int> totalAvailableCounts;
	// This should reconfigure the floor state (i.e. OPEN/FULL)
	void updateState();
};

#endif //CS460_PROJECT_1_PARKINGLOT_H
