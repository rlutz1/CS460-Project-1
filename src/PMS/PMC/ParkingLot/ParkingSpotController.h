//
// Created by Eliud Garcia on 2/24/26.
//

#ifndef CS460_PROJECT_1_PARKINGSPOTCONTROLLER_H
#define CS460_PROJECT_1_PARKINGSPOTCONTROLLER_H

#include "../../Definitions/Identifiers.h"

class IParkingSpotHardwareSink;
// Hopefully will be a useful declaration for callback to floor
class ParkingFloor;

// TODO: I am going to leave this as a placeholder for the sensor configuration updates (might not need)
struct SensorUpdate
{
};


class ParkingSpotController
{
public:
	enum class State
	{
		AVAILABLE,
		UNAVAILABLE,
		OCCUPIED
	};

	// This is constructor should store the spot ID and the reference to the parent floor
	ParkingSpotController(const SpotId& id, ParkingFloor& floor);

	// This called when a sensor triggers (weight or ultrasonic) outlined in the SAD
	void updateSpotAvailability(const SensorId& sensor, bool vehicleDetected);

	// TODO: This is the administrative override that I think Roxanne want Gabriel to focus on
	void forceUnavailable();

	// The necessary Getters
	SpotType getSpotType() const
	{
		return id.type;
	}

	State getState() const
	{
		return state;
	}

	const SpotId& getSpotId() const
	{
		return id;
	}


	/////////////////////////////////////// ///////////////////////////////////////
	void markSpotAvailability(bool isAvailable);
	SpotId id;
	IParkingSpotHardwareSink* spotHardware;
private:
	State state;
	bool weightDetected;
	bool ultrasonicDetected;
	// This should hopefully notify the floor of any state changes
	ParkingFloor& floor;
	// This should reconfigure the overall state of the spot based on both of the sensor readings (TRUE or FALSE)
	void updateStateFromSensors();
};


#endif //CS460_PROJECT_1_PARKINGSPOTCONTROLLER_H
