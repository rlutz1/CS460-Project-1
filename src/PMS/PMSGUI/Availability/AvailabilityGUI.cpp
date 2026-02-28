//
// Created by Eliud Garcia on 2/24/26.
//

#include "AvailabilityGUI.h"

#include <qgridlayout.h>

#include "../../Initialization.h"


AvailabilityGUI::AvailabilityGUI(QWidget* parent, InitializationPackage initPackage) :
    QWidget(parent),
    // these are headers for readability
    headerTotalAvail("LOT", this),
    headerFloor1Avail("FLOOR 1", this),
    headerFloor2Avail("FLOOR 2", this),
    headerNormalType("GENERAL", this),
    headerHandicapType("HANDICAP", this),
    headerEvType("EV", this),
    headerMotorcycleType("MOTORCYCLE", this),
    headerLog("MESSAGE", this),
    headerInTransit("IN TRANSIT", this),

    // these are for the count updates
    totalAvailNormal(QString::number(initPackage.numbers.totalNormalSpots), this),
    totalAvailHandicap(QString::number(initPackage.numbers.totalHandicapSpots), this),
    totalAvailEv(QString::number(initPackage.numbers.totalEvSpots), this),
    totalAvailMotorcycle(QString::number(initPackage.numbers.totalMotorcycleSpots), this),

    floor1AvailNormal(QString::number(initPackage.numbers.normalSpotsFloor1), this),
    floor1AvailHandicap(QString::number(initPackage.numbers.handicapSpotsFloor1), this),
    floor1AvailEv(QString::number(initPackage.numbers.evSpotsFloor1), this),
    floor1AvailMotorcycle(QString::number(initPackage.numbers.motorcycleSpotsFloor1), this),

    floor2AvailNormal(QString::number(initPackage.numbers.normalSpotsFloor2), this),
    floor2AvailHandicap(QString::number(initPackage.numbers.handicapSpotsFloor2), this),
    floor2AvailEv(QString::number(initPackage.numbers.evSpotsFloor2), this),
    floor2AvailMotorcycle(QString::number(initPackage.numbers.motorcycleSpotsFloor2), this),

    inTransit(QString::number(0), this),

    log("LOT OPEN", this),

    layout(this)
{

    this->setLayout(&layout);

    layout.addWidget(&headerTotalAvail, 1, 0);
    layout.addWidget(&headerFloor1Avail, 2, 0);
    layout.addWidget(&headerFloor2Avail, 3, 0);
    layout.addWidget(&headerInTransit, 4, 0);

    layout.addWidget(&headerNormalType, 0, 1);
    layout.addWidget(&headerHandicapType, 0, 2);
    layout.addWidget(&headerEvType, 0, 3);
    layout.addWidget(&headerMotorcycleType, 0, 4);

    layout.addWidget(&totalAvailNormal, 1, 1);
    layout.addWidget(&totalAvailHandicap, 1, 2);
    layout.addWidget(&totalAvailEv, 1, 3);
    layout.addWidget(&totalAvailMotorcycle, 1, 4);

    layout.addWidget(&floor1AvailNormal, 2, 1);
    layout.addWidget(&floor1AvailHandicap, 2, 2);
    layout.addWidget(&floor1AvailEv, 2, 3);
    layout.addWidget(&floor1AvailMotorcycle, 2, 4);

    layout.addWidget(&floor2AvailNormal, 3, 1);
    layout.addWidget(&floor2AvailHandicap, 3, 2);
    layout.addWidget(&floor2AvailEv, 3, 3);
    layout.addWidget(&floor2AvailMotorcycle, 3, 4);

    layout.addWidget(&inTransit, 4, 1);

    layout.addWidget(&headerLog, 5, 0);
    layout.addWidget(&log, 5, 1);
}

void AvailabilityGUI::increaseCount(QLabel& countLabel) {
    QString newCount(countLabel.text());
    int tempCount = newCount.toInt();
    tempCount++;
    newCount.setNum(tempCount);
    countLabel.setText(newCount);
}

void AvailabilityGUI::decreaseCount(QLabel& countLabel) {
    QString newCount(countLabel.text());
    int tempCount = newCount.toInt();
    tempCount--;
    newCount.setNum(tempCount);
    countLabel.setText(newCount);
}

void AvailabilityGUI::increaseInTransitCount() {
    increaseCount(inTransit);
}

void AvailabilityGUI::decreaseInTransitCount() {
    decreaseCount(inTransit);
}

void AvailabilityGUI::increaseAvailabilityCount(SpotType spotType, int floor) {
    switch (spotType) {
        case NORMAL:
            if (floor == 1) {
                increaseCount(floor1AvailNormal);
            }else if (floor == 2) {
                increaseCount(floor2AvailNormal);
            }
            increaseCount(totalAvailNormal);
            break;
        case EV:
            if (floor == 1) {
                increaseCount(floor1AvailEv);
            }else if (floor == 2) {
                increaseCount(floor2AvailEv);
            }
            increaseCount(totalAvailEv);
            break;
        case HANDICAP:
            if (floor == 1) {
                increaseCount(floor1AvailHandicap);
            }else if (floor == 2) {
                increaseCount(floor2AvailHandicap);
            }
            increaseCount(totalAvailHandicap);
            break;
        case MOTORCYCLE:
            if (floor == 1) {
                increaseCount(floor1AvailMotorcycle);
            }else if (floor == 2) {
                increaseCount(floor2AvailMotorcycle);
            }
            increaseCount(totalAvailMotorcycle);
            break;
    }
}

void AvailabilityGUI::decreaseAvailabilityCount(SpotType spotType, int floor) {
    switch (spotType) {
        case NORMAL:
            if (floor == 1) {
                decreaseCount(floor1AvailNormal);
            }else if (floor == 2) {
                decreaseCount(floor2AvailNormal);
            }
            decreaseCount(totalAvailNormal);
            break;
        case EV:
            if (floor == 1) {
                decreaseCount(floor1AvailEv);
            }else if (floor == 2) {
                decreaseCount(floor2AvailEv);
            }
            decreaseCount(totalAvailEv);
            break;
        case HANDICAP:
            if (floor == 1) {
                decreaseCount(floor1AvailHandicap);
            }else if (floor == 2) {
                decreaseCount(floor2AvailHandicap);
            }
            decreaseCount(totalAvailHandicap);
            break;
        case MOTORCYCLE:
            if (floor == 1) {
                decreaseCount(floor1AvailMotorcycle);
            }else if (floor == 2) {
                decreaseCount(floor2AvailMotorcycle);
            }
            decreaseCount(totalAvailMotorcycle);
            break;
    }
}



void AvailabilityGUI::setLogMsg(std::string newLogMsg) {
    QString qnewLogMsg;
    qnewLogMsg.append(newLogMsg);

    log.setText(qnewLogMsg);
}

QSize AvailabilityGUI::sizeHint() const {
    return QSize(500, 500);
}