//
// Created by lutzr on 2/25/2026.
//

#ifndef CS460_PROJECT_1_INITIALIZATION_H
#define CS460_PROJECT_1_INITIALIZATION_H

#include <vector>
#include "Definitions/Identifiers.h"
using std::vector;

struct SpotId;
struct GateId;

struct NumParkingLotComponents {
    char totalNormalSpots;
    char normalSpotsFloor1;
    char normalSpotsFloor2;
    char totalHandicapSpots;
    char handicapSpotsFloor1;
    char handicapSpotsFloor2;
    char totalEvSpots;
    char evSpotsFloor1;
    char evSpotsFloor2;
    char totalMotorcycleSpots;
    char motorcycleSpotsFloor1;
    char motorcycleSpotsFloor2;
    char entranceGates;
    char exitGates;
    char floors;
    char maxVehicles;
};

struct InitializationPackage {
    NumParkingLotComponents numbers;
    vector<SpotId> spotIds;
    GateId entranceGateId;
    GateId exitGateId;
};

#endif //CS460_PROJECT_1_INITIALIZATION_H