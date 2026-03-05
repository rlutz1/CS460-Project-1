/**
 * these are useful definitions, following SAD mentions
 * of ids, types, etc that are useful in the back and
 * front end logic.
 */

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
};

// a sensor identifier
struct SensorId {
    string uniqueId;
    string parentId;
};

// a spot identifier
struct SpotId {
    string uniqueId;
    SpotType type;
    FloorId floorId;
    SensorId ultrasonicId;
    SensorId weightId;
};

// a gate identifier
struct GateId {
    string uniqueId;
    GateType type;
    SensorId initOpenId;
    SensorId stayOpenId;
};

#endif //CS460_PROJECT_1_IDENTIFIERS_H