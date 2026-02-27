//
// Created by Eliud Garcia on 2/24/26.
//

#include "AvailabilityGUI.h"

#include <qgridlayout.h>

#include "../../Initialization.h"

// QLabel headerTotalAvail;
// QLabel headerFloor1Avail;
// QLabel ;
// QLabel ;
// QLabel ;
// QLabel ;
// QLabel ;
// QLabel ;
//
// QLabel ;
// QLabel ;
// QLabel ;
// QLabel ;
//
// QLabel ;
// QLabel ;
// QLabel ;
// QLabel ;
//
// QLabel ;
// QLabel ;
// QLabel ;
// QLabel ;
//
// QLabel ;

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

QSize AvailabilityGUI::sizeHint() const {
    return QSize(500, 500);
}