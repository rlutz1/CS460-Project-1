//
// Created by Eliud Garcia on 2/24/26.
//

#ifndef CS460_PROJECT_1_PARKINGMANAGEMENTCONTROLLER_H
#define CS460_PROJECT_1_PARKINGMANAGEMENTCONTROLLER_H


#include "../Initialization.h"
#include "../PMC/ParkingLot/ParkingLot.h"
#include "../PMC/Gate/GateController.h"
#include "../PMC/Availability/AvailabilityController.h"

struct InitializationPackage;

class ParkingManagementController {
public:
	// This is a constructor that initializes all subsystems from the provided package (self note)
    ParkingManagementController(InitializationPackage initPackage);

	// This should handle the enternal interface: which is called by the sensor drivers when a hardware event occurs
	void handleSensorTrigger(const SensorId& sensor, bool detected);

	/* TODO: These are the administrative requests that are invoked by the ActionManager (Change if needed)
	 * Most likely won't need all or any of them put just putting them here just in case
	 */
	// Unlocks the entrance gate and updates the displays
	void openParkingLot();
	// Locks the entrance gate and shows FULL
	void closeParkingLot();
	void markSpotUnavailable(const SpotId& spot);
	void makeSpotAvailable(const SpotId& spot);
	void changeSpotType(const SpotId& spot, SpotType newType);
	void changeLEDDefault(const SpotId& spot, int r, int g, int b);
	void configureSensor(const SensorId& sensor, const SensorUpdate& update);
	void updateLogMessage(const std::string& msg);

	// This should be used to get the statues of the total available spots and floor
	int getTotalAvailable(SpotType type) const;
	int getFloorAvailable(const FloorId& floor, SpotType type) const;
	ParkingLot::State getLotState() const;

private:
	// This should manage the floors and spots
	ParkingLot lot;
	//TODO: Add gate stuff

	// Should locate a parking spot by its associated sensor ID
	ParkingSpotController* findSpotBySensor(const SensorId& sensor);
};


#endif //CS460_PROJECT_1_PARKINGMANAGEMENTCONTROLLER_H