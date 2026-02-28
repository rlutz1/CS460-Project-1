//
// Created by Eliud Garcia on 2/27/26.
//

#ifndef CS460_PROJECT_1_IAVAILABILITYINSTRUCTIONSINK_H
#define CS460_PROJECT_1_IAVAILABILITYINSTRUCTIONSINK_H
#include "../../Definitions/Identifiers.h"


/**
 * IAvailabilityInstructionSink (abstract class):
 *      Meant for Hardware(to implement) in order to handle the change of the labels for availability.
 */
class IAvailabilityInstructionSink{
    public:
    ~IAvailabilityInstructionSink() = default;

    virtual void increaseInTransitCount() = 0;
    virtual void decreaseInTransitCount() = 0;
    virtual void increaseAvailabilityCount(SpotType spotType, int floor) = 0;
    virtual void decreaseAvailabilityCount(SpotType spotType, int floor) = 0;

    virtual void setLogMsg(std::string) = 0;
};

#endif //CS460_PROJECT_1_IAVAILABILITYINSTRUCTIONSINK_H