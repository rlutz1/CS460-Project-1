//
// Created by Eliud Garcia on 2/24/26.
//

#ifndef CS460_PROJECT_1_PARKINGMANAGEMENTCONTROLLER_H
#define CS460_PROJECT_1_PARKINGMANAGEMENTCONTROLLER_H


#include <iostream>
#include "../Initialization.h"
#include "../PMC/ParkingLot/ParkingLot.h"
#include "../PMC/Gate/GateController.h"
#include "../PMC/Gate/CentralGateController.h"
#include "../PMC/Availability/AvailabilityController.h"

// A simple hardware sink that prints to console (for demo purposes)
class ConsoleGateHardware : public IGateInstructionSink
{
public:
	void signalGateOpen() override
	{
		std::cout << "[HARDWARE] Gate open signal sent.\n";
	}

	void signalGateClose() override
	{
		std::cout << "[HARDWARE] Gate close signal sent.\n";
	}
};

// Added a simple display sink that prints availability updates
class ConsoleDisplaySink : public IAvailabilityInstructionSink {
public:
	void increaseAvailabilityCount(SpotType type, int floor) override {
		std::cout << "[DISPLAY] Floor " << floor << " " << spotTypeToString(type)
				  << " availability increased.\n";
	}
	void decreaseAvailabilityCount(SpotType type, int floor) override {
		std::cout << "[DISPLAY] Floor " << floor << " " << spotTypeToString(type)
				  << " availability decreased.\n";
	}
	// This should match the interface by value
	void setLogMsg(std::string msg) override {
		std::cout << "[DISPLAY] Message: " << msg << "\n";
	}
	void increaseInTransitCount() override {
		std::cout << "[DISPLAY] In‑transit count increased.\n";
	}
	void decreaseInTransitCount() override {
		std::cout << "[DISPLAY] In‑transit count decreased.\n";
	}
private:
	std::string spotTypeToString(SpotType t) {
		switch(t) {
		case NORMAL: return "Normal";
		case HANDICAP: return "Handicap";
		case EV: return "EV";
		case MOTORCYCLE: return "Motorcycle";
		default: return "Unknown";
		}
	}
};

class ParkingManagementController
{
public:
	ParkingManagementController(const InitializationPackage& initPackage);
	ParkingManagementController(InitializationPackage initPackage);
	// This should be called by the CentralGateController when the gate events occur
	// When a vehicle us detected at gate (entry or exit)
	void vehicleSensed(GateId gateId);
	// When a vehicle has passed through gate
	void vehicleAbsent(GateId gateId);
	// The entry gate is closed after vehicle passed
	void successfulEntry(GateId gateId);
	// The exit gate is closed after vehicle passed
	void successfulExit(GateId gateId);
	void handleSensorTrigger(const SensorId& sensor, bool detected);

	void updateLogMessage(const std::string& msg);

	// The necessary getters
	int getTotalAvailable(SpotType type) const;
	int getVehiclesInside() const { return vehiclesInside; }
	int getTotalSpots() const { return totalSpots; }
	ParkingLot::State getLotState() const;

private:
	ParkingLot lot;
	CentralGateController centralGate;
	AvailabilityController availabilityDisplay;

	// This is for the gate hardware instances (one per gate)
	ConsoleGateHardware entranceHardware;
	ConsoleGateHardware exitHardware;

	// This is the counters
	// From the initialization
	int totalSpots;
	// The vehicles that have entered and not yet exited
	int vehiclesInside;

	// This is a helper to locate a spot by sensor (TODO: Might need implementation in ParkingLot)
	ParkingSpotController* findSpotBySensor(const SensorId& sensor);
};

#endif //CS460_PROJECT_1_PARKINGMANAGEMENTCONTROLLER_H
