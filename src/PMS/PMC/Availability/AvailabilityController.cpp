//
// Created by Eliud Garcia on 2/24/26.
//

#include "AvailabilityController.h"


// TODO: thought to return total availability since there's no inputs needed from availability display
void AvailabilityController::updateAvailabilityTracking(SpotType spotType, int floor, bool toIncrement) {
        if ( toIncrement ) {
                availabilityDisplay->increaseAvailabilityCount(spotType, floor);
        }else {
                availabilityDisplay->decreaseAvailabilityCount(spotType, floor);
        }
}

void AvailabilityController::updateLogMessage(const std::string& logMsg) {
        availabilityDisplay->setLogMsg(logMsg);
}

void AvailabilityController::updateInTransit(bool toIcrement) {
        if ( toIcrement ) {
                availabilityDisplay->increaseInTransitCount();
        }else {
                availabilityDisplay->decreaseInTransitCount();
        }
}

void AvailabilityController::setAvailabilityDisplay(IAvailabilityInstructionSink& newAvailabilityDisplay) {
        availabilityDisplay = &newAvailabilityDisplay;
}