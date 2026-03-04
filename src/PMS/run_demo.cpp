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
#include "PMC/ParkingManagementController.h"
#include <vector>

#include "PMSGUI/Availability/AvailabilityGUI.h"

using std::vector;

#define WINDOW_WIDTH 1400
#define WINDOW_HEIGHT 600

// main access point to boot up the demo -- gui and backend both
int run_demo(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget mainWindow;
    // layout for bottom part of window
    QWidget bottomContainer(&mainWindow);
    QHBoxLayout bottomLayout(&bottomContainer);


    InitializationPackage initPackage = genInitPackage(); // initialize config info for both front and backend

    // for displaying availability -> a vanilla widget
    AvailabilityGUI availabilityDisplay(&bottomContainer, initPackage);
    DemoManager demoManager(
        &mainWindow,
        initPackage,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        availabilityDisplay
        ); // initialize the front end

   // initialize sink? or unnecessary step -- leaving for eliud for now

    // init the main window
    // there are issues with scoping of the following,
    // so it's here to avoid leaking and crashing on exit
    mainWindow.setMinimumSize(QSize(WINDOW_WIDTH + 100, WINDOW_HEIGHT + 200));
    QVBoxLayout layout(&mainWindow);
    mainWindow.setLayout(&layout);


    // layout for stacking the bottons on left sid
    QWidget buttonContainer(&bottomContainer);
    QVBoxLayout buttonLayout(&buttonContainer);

    QPushButton startSimpleDemoButton("Start Simple Demo", &buttonContainer); // TODO disable both on click, enable stop
    QPushButton startChaosDemoButton("Start Chaos Demo", &buttonContainer); // TODO disable both on click, enable stop
    QPushButton stopDemoButton("Stop Demo", &buttonContainer);// TODO disable this, enable both demo buttons
    // TODO: next line, connections for all
    QObject::connect(&startSimpleDemoButton, &QPushButton::clicked, &demoManager, &DemoManager::runSimpleDemo);
    QObject::connect(&startChaosDemoButton, &QPushButton::clicked, &demoManager, &DemoManager::runChaosDemo);
    QObject::connect(&stopDemoButton, &QPushButton::clicked, &demoManager, &DemoManager::stopDemo);

    buttonLayout.addWidget(&startSimpleDemoButton);
    buttonLayout.addWidget(&startChaosDemoButton);
    buttonLayout.addWidget(&stopDemoButton);

    // add to the bottom layout: buttons and availbility display
    bottomLayout.addWidget(&buttonContainer);
    bottomLayout.addWidget((QWidget*) &availabilityDisplay);

    std::shared_ptr<ParkingManagementController> pmc = std::make_shared<ParkingManagementController>(initPackage, availabilityDisplay, demoManager); // initialize the backend
    demoManager.addSignalReceiver(pmc);
    // adding main two containers to the UI
    layout.addWidget(&demoManager);
    layout.addWidget(&bottomContainer);
    mainWindow.show();
    return QApplication::exec();
}

// generate the initialization package for both
// front and back end
InitializationPackage genInitPackage() {
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
    GateType gate = ENTRANCE;
    GateId entranceGateId = initGateId(gate);
    gate = EXIT;
    GateId exitGateId = initGateId(gate);

    // init floor ids
    FloorId floor1Id {.uniqueId = "floor1"}; // let roxanne know if you change this at all
    FloorId floor2Id {.uniqueId = "floor2"};
    vector<FloorId> floorIds;
    floorIds.push_back(floor1Id); floorIds.push_back(floor2Id);

    // init the spot ids
    vector<SpotId> spotIds = initSpotIds(lotNumbers, floor1Id, floor2Id);

    // wrap everything into a single package
    InitializationPackage initPackage{
        .numbers = lotNumbers,
        .spotIds = spotIds,
        .entranceGateId = entranceGateId,
        .exitGateId = exitGateId,
        .floorIds = floorIds
    };
    return initPackage;
}

// some hardcoding, but initialize some basic
// identifiers to use for the 2 gates.
GateId initGateId(GateType type) {
    if (type == ENTRANCE) {
        SensorId firstSensor {
            .uniqueId = "entranceGateInitOpen",
            .parentId = "entranceGate"
        };
        SensorId secondSensor {
            .uniqueId = "entranceGateStayOpen",
            .parentId = "entranceGate"
        };
        return GateId {
            .uniqueId = "entranceGate",
            .type = type,
            .initOpenId = firstSensor,
            .stayOpenId = secondSensor
        };
    } else {
        SensorId firstSensor {
            .uniqueId = "exitGateInitOpen",
            .parentId = "exitGate"
        };
        SensorId secondSensor {
            .uniqueId = "exitGateStayOpen",
            .parentId = "exitGate"
        };
        return GateId {
            .uniqueId = "exitGate",
            .type = type,
            .initOpenId = firstSensor,
            .stayOpenId = secondSensor
        };
    }
}

// initialize the spot ids into a simple vector for iteration
// by both back and front end
vector<SpotId> initSpotIds(NumParkingLotComponents numbers, const FloorId &floor1Id, const FloorId floor2Id) {
    vector<SpotId> spotIds;

    // ready enums
    SpotType normalType = NORMAL;
    SpotType handicapType = HANDICAP;
    SpotType evType = EV;
    SpotType motorcycleType = MOTORCYCLE;

    // INIT NORMALS -- FLOOR 1 & 2
    initSpotIterator(spotIds, "N", numbers.normalSpotsFloor1, floor1Id, normalType);
    initSpotIterator(spotIds, "N", numbers.normalSpotsFloor2, floor2Id, normalType);

    // INIT HANDICAP -- FLOOR 1 & 2
    initSpotIterator(spotIds, "H", numbers.handicapSpotsFloor1, floor1Id, handicapType);
    initSpotIterator(spotIds, "H", numbers.handicapSpotsFloor2, floor2Id, handicapType);

    // INIT EV -- FLOOR 1 & 2
    initSpotIterator(spotIds, "EV", numbers.evSpotsFloor1, floor1Id, evType);
    initSpotIterator(spotIds, "EV", numbers.evSpotsFloor2, floor2Id, evType);

    // INIT MOTORCYCLE -- FLOOR 1 & 2
    initSpotIterator(spotIds, "M", numbers.motorcycleSpotsFloor1, floor1Id, motorcycleType);
    initSpotIterator(spotIds, "M", numbers.motorcycleSpotsFloor2, floor2Id, motorcycleType);

    return spotIds;
}

// helper function to not have 20 copy pasted loops
void initSpotIterator
    (
    vector<SpotId>& spotIds,
    string prefix,
    char numSpots,
    FloorId floorId,
    SpotType type
    )
{

    for (int i = 1; i <= numSpots; i++) {
        string spotId = prefix + "_" + floorId.uniqueId + "_spot" + std::to_string(i);
        spotIds.push_back(
          SpotId {
              .uniqueId = spotId,
              .type = type,
              .floorId = floorId,
              .ultrasonicId = SensorId {.uniqueId = "ultrasonic", .parentId = spotId},
              .weightId = SensorId {.uniqueId = "weight", .parentId = spotId}
          }
        );
    }
}

// only used for confirmation
// void printInit(InitializationPackage package) {
//     for (SpotId id : package.spotIds) {
//         std::cout << id.uniqueId << std::endl;
//     }
//
//     std::cout << package.entranceGateId.uniqueId << std::endl;
//     std::cout << package.exitGateId.uniqueId << std::endl;
//     std::cout << package.exitGateId.initOpenId.uniqueId << std::endl;
// }