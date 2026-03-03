//
// Created by Eliud Garcia on 2/24/26.
//

#include "AvailabilityController.h"

AvailabilityController::AvailabilityController(IAvailabilityInstructionSink* ptr) :
        availabilityDisplaySink(ptr) { };

void AvailabilityController::updateAvailabilityTracking(SpotType spotType, int floor, bool toIncrement) {
        bool lotGotFull = false;
        if ( toIncrement ) {
                availabilityDisplaySink->increaseAvailabilityCount(spotType, floor);
        }else {
                lotGotFull = availabilityDisplaySink->decreaseAvailabilityCount(spotType, floor);
        }

        if ( lotGotFull ) {
                // signal to PMC : to change log message to FULL.
                // otherwise so it can keep changing it to AVAILABLE (to reset previous FULL messages).
        }
}

void AvailabilityController::updateLogMessage(const std::string& logMsg) {
        availabilityDisplaySink->setLogMsg(logMsg);
}

void AvailabilityController::updateInTransit(bool toIcrement) {
        if ( toIcrement ) {
                availabilityDisplaySink->increaseInTransitCount();
        }else {
                availabilityDisplaySink->decreaseInTransitCount();
        }
}

void AvailabilityController::setAvailabilityDisplay(IAvailabilityInstructionSink& newAvailabilityDisplay) {
        availabilityDisplaySink = &newAvailabilityDisplay;
}