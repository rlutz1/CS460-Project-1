//
// Created by lutzr on 2/25/2026.
//

#ifndef CS460_PROJECT_1_IDENTIFIERS_H
#define CS460_PROJECT_1_IDENTIFIERS_H

#include <string>
using std::string;

// enumeration of spot types
enum SpotType {
    NORMAL,
    HANDICAP,
    EV,
    MOTORCYCLE
};

// enumeration of gate types
enum GateType {
    ENTRANCE,
    EXIT
};

// a floor identifier
struct FloorId {
    string uniqueId;
    // maybe for mapping...
    // constexpr bool operator()(FloorId a, FloorId b) const {
    //     return (a.uniqueId[) < (b.uniqueId);
    // }
};

// a sensor identifier
struct SensorId {
    string uniqueId;
    string parentSpotId;
};

// a spot identifier
struct SpotId {
    string uniqueId;
    enum SpotType type;
    FloorId floorId;
    SensorId ultrasonicId;
    SensorId weightId;
};

struct GateId {
    string uniqueId;
    GateType type;
    SensorId initOpenId;
    SensorId stayOpenId;
};

#endif //CS460_PROJECT_1_IDENTIFIERS_H