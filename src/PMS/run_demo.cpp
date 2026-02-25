#include <iostream>
#include <QApplication>
// #include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QObject>
// #include <QSequentialAnimationGroup>
#include "run_demo.h"
// #include "Mediator/Mediator.h"
#include "PMSGUI/DemoManager.h"
#include "Definitions/Identifiers.h"
#include "Initialization.h"

#include <vector>
using std::vector;

// #include "PMSSoftware/ParkingManagementController.h"
// #include "ParkingLot/ParkingSpot.h"

// main access point to boot up the demo -- gui and backend both
int run_demo(int argc, char *argv[]) {

    QApplication a(argc, argv);
    InitializationPackage initPackage = initConfig(); // initialize config info for both front and backend
    // initialize the front end
    // initialize the backend
    // initialize sink? or unnecessary step
    // initWindow(); // initialize the window

    return QApplication::exec();
}

void initWindow(DemoManager &manager) {
    // setup main window layout
    QWidget mainLayout;
    QVBoxLayout layout(&mainLayout);
    mainLayout.setLayout(&layout);
    // todo: add mainLayout as parent layout to gui container for lot

    QPushButton button("Start Demo", &mainLayout);
    // TODO: next line
    // QObject::connect(&button, &QPushButton::clicked, &parking_lot, &ParkingLot::run_demo);

    // layout.addWidget(manager); // TODO: ensure this works, giving me type grief
    layout.addWidget(&button);
    mainLayout.show();
}



// char normalSpotsFloor2;
// char handicapSpotsFloor1;
// char handicapSpotsFloor2;
// char evSpotsFloor1;
// char evSpotsFloor2;
// char motorcycleSpotsFloor1;
// char motorcycleSpotsFloor2;

InitializationPackage initConfig() {
    // CONSTANTS, DO NOT CHANGE
    NumParkingLotComponents lotNumbers {
        .totalNormalSpots = 28,
        .normalSpotsFloor1 = 8,
        .normalSpotsFloor2 = 20,

        .totalHandicapSpots = 4,
        .handicapSpotsFloor1 = 2,
        .handicapSpotsFloor2 = 2,

        .totalEvSpots = 4,
        .evSpotsFloor1 = 2,
        .evSpotsFloor2 = 2,

        .totalMotorcycleSpots = 2,
        .motorcycleSpotsFloor1 = 2,
        .motorcycleSpotsFloor2 = 0,

        .entranceGates = 1,
        .exitGates = 1,

        .floors = 2,

        .maxVehicles = 38, // number of spots for now in case we don't cover gate logic fully
    };

    // init the gate ids
    enum GateType gate = ENTRANCE;
    GateId entranceGateId = initGateId(gate);
    gate = EXIT;
    GateId exitGateId = initGateId(gate);

    // init the spot ids
    vector<SpotId> spotIds = initSpotIds(lotNumbers);

    // wrap everything into a single package
    InitializationPackage initPackage{
        .numbers = lotNumbers,
        .entranceGateId = entranceGateId,
        .exitGateId = exitGateId,
    };
    return initPackage;
}

// some hardcoding, but initialize some basic
// identifiers to use for the 2 gates.
GateId initGateId(GateType type) {
    if (type == ENTRANCE) {
        SensorId firstSensor {
            .uniqueId = "entranceGateInitOpen"
        };
        SensorId secondSensor {
            .uniqueId = "entranceGateStayOpen"
        };
        return GateId {
            .uniqueId = "entranceGate",
            .type = type,
            .initOpenId = firstSensor,
            .stayOpenId = secondSensor
        };
    } else {
        SensorId firstSensor {
            .uniqueId = "exitGateInitOpen"
        };
        SensorId secondSensor {
            .uniqueId = "exitGateStayOpen"
        };
        return GateId {
            .uniqueId = "exitGate",
            .type = type,
            .initOpenId = firstSensor,
            .stayOpenId = secondSensor
        };
    }
}

// struct FloorId {
//     string uniqueId;
// };
//
// // a sensor identifier
// struct SensorId {
//     string uniqueId;
//     string parentSpotId;
// };
//
// // a spot identifier
// struct SpotId {
//     string uniqueId;
//     enum SpotType type;
//     FloorId floorId;
//     SensorId ultrasonicId;
//     SensorId weightId;
// };

vector<SpotId> initSpotIds(NumParkingLotComponents numbers) {
    // char totalNumSpots =
    //     numbers.normalSpots + numbers.handicapSpots + numbers.evSpots + numbers.motorcycleSpots;
    vector<SpotId> spotIds;
    // init floor ids
    FloorId floor1Id {.uniqueId = "floor1"};
    FloorId floor2Id {.uniqueId = "floor2"};

    // ready enums
    enum SpotType normalType = NORMAL;
    enum SpotType handicapType = HANDICAP;
    enum SpotType evType = EV;
    enum SpotType motorcycleType = MOTORCYCLE;

    for (int i = 1; i <= numbers.normalSpotsFloor1; i++) {
        string spotId = "N_" + floor1Id.uniqueId + "_spot" + std::to_string(i);
        spotIds.push_back(
          SpotId {
              .uniqueId = spotId,
              .type = normalType,
              .ultrasonicId = SensorId {.uniqueId = "ultrasonic", .parentSpotId = spotId},
              .weightId = SensorId {.uniqueId = "weight", .parentSpotId = spotId}
          }
        );
    }



}