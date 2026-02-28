//
// Created by Eliud Garcia on 2/24/26.
//

#include "AvailabilityController.h"


void AvailabilityController::updateAvailabilityTracking(SpotType spotType, int floor, bool toIncrement) {
        bool lotGotFull = false;
        if ( toIncrement ) {
                availabilityDisplay->increaseAvailabilityCount(spotType, floor);
        }else {
                lotGotFull = availabilityDisplay->decreaseAvailabilityCount(spotType, floor);
        }

        if ( lotGotFull ) {
                // signal to PMC : to change log message to FULL.
                // otherwise so it can keep changing it to AVAILABLE (to reset previous FULL messages).
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