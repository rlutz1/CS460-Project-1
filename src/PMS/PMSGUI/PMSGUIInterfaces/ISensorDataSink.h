//
// Created by Eliud Garcia on 2/25/26.
//

#ifndef CS460_PROJECT_1_ISENSORDATASINK_H
#define CS460_PROJECT_1_ISENSORDATASINK_H
#include <string>
#include "../../Definitions/Identifiers.h"

using std::string;

/**
 * ISensorDataSink - abstract class:
 *      For Non-hardware component to derive (i.e. implement interface).
 */
class ISensorDataSink {
public:
    ~ISensorDataSink() = default;
    virtual void SensedVehicle(SensorId sensorID) = 0;
    virtual void NotSensedVehicled(SensorId sensorID) = 0;
};

#endif //CS460_PROJECT_1_ISENSORDATASINK_H