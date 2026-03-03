//
// Created by Eliud Garcia on 2/25/26.
//

#ifndef CS460_PROJECT_1_ISENSORDATASINK_H
#define CS460_PROJECT_1_ISENSORDATASINK_H
#include <string>
#include "../../Definitions/Identifiers.h"

using std::string;

/**
 * IInductionSensorDataSink - abstract class:
 *      For PMC component to derive (i.e. implement interface).
 */
class IInductionSensorDataSink {
public:
    ~IInductionSensorDataSink() = default;
    virtual void vehicleSensed(GateId gateId) = 0;
    virtual void vehicleAbsent(GateId gateId) = 0;
    virtual void successfulEntry() = 0;
    virtual void successfulExit() = 0;
};

#endif //CS460_PROJECT_1_ISENSORDATASINK_H