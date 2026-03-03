//
// Created by Eliud Garcia on 2/24/26.
//

#ifndef CS460_PROJECT_1_AVAILABILITYCONTROLLER_H
#define CS460_PROJECT_1_AVAILABILITYCONTROLLER_H

#include <string>

#include "../../Definitions/Identifiers.h"
#include "../../PMC/PMCInterfaces/IAvailabilityInstructionSink.h"

class AvailabilityController {
    public:
    AvailabilityController();
    ~AvailabilityController() = default;
    void updateAvailabilityTracking(SpotType spotType, int floor, bool toIncrement);
    void updateLogMessage(const std::string& logMsg);
    void updateInTransit(bool toIcrement);

    void setAvailabilityDisplay(IAvailabilityInstructionSink& newAvailabilityDisplay);
private:
    IAvailabilityInstructionSink* availabilityDisplaySink;
};


#endif //CS460_PROJECT_1_AVAILABILITYCONTROLLER_H