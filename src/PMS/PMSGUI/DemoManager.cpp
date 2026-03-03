//
// Created by Eliud Garcia on 2/24/26.
//

#include "DemoManager.h"

#include <iostream>

#include "../Initialization.h"
#include <QPoint>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
using std::cout;


#include "ParkingLot/ParkingLotGUI.h"
#include <random>


/**
 * this constructor initializes the parking lot, which is the wrapper
 * of the whole visual aspect of the demo.
 * this does not contain the availability display.
 */
DemoManager::DemoManager(
    QWidget* parent,
    InitializationPackage initPackage,
    int width,
    int height,
    AvailabilityGUI& availabilityDisplay
    ) :
    parkingLot(
        scene,
        initPackage,
        {.x = 0, .y = 0, .width = width, .height = height, .color = Qt::darkGray, .zPos = 0}
        ),
    availabilityDisplay(&availabilityDisplay),
    // initPackage(initPackage),
    QGraphicsView(parent)
{
    this->setMinimumSize(QSize(width, height));
    initScene();
    setScene(&scene);
} // end constructor

/**
 * run many vehicles in a cycle to showcase stability
 */
void DemoManager::runChaosDemo() {
    stopDemo(); // clean out whatever's there

    int numCars = 5;
    int delay = 0;

    for (int i = 0; i < numCars; i++) {

        VehicleGUI* vehicle = new VehicleGUI(
        scene,
        {.x = parkingLot.wm.x, .y = parkingLot.wm.y, .width = 25, .height = 25, .color = Qt::darkMagenta, .zPos = 100},
        {
            .entryDelay = delay,
            .movementType = QEasingCurve::OutCubic,
            .approachGateTime = 1000,
            .throughGateTime = 1000,
            .xFirstEntryGateSensor = parkingLot.gate.entranceGate.initOpenSensor.wm.x + 25,
            .xSecondEntryGateSensor = parkingLot.gate.entranceGate.stayOpenSensor.wm.x + 25,
            .xFirstExitGateSensor = parkingLot.gate.exitGate.initOpenSensor.wm.x - 25,
            .xSecondExitGateSensor = parkingLot.gate.exitGate.stayOpenSensor.wm.x - 25,
            .yEntryTrack = parkingLot.gate.entranceGate.wm.y + 50,
            .yExitTrack = parkingLot.gate.exitGate.wm.y + 50,
            .xSpot = parkingLot.parkingFloors[i % 2]->parkingSpots[i]->wm.x + 12, // NOTE: not maleable to num parking spots!
            .ySpot = parkingLot.parkingFloors[i % 2]->parkingSpots[i]->wm.y + 40,
            .generalMovementTime = 2000,
            .parkPauseTime = 4000,
            .parkTime = 1000
            },
            this,
            true
            ); // run the vehicle at a timing offset

        delay += 4000;
        activeVehicles.push_back(vehicle); // add to active vehicles`
        currAnimation.addAnimation(&vehicle->animationGroup); // add to the parallel parent animation
    } // end loop
    currAnimation.start();
} // end method

/**
 * run exactly 1 vehicle through entry, park, and exit.
 */
void DemoManager::runSimpleDemo() {
    stopDemo(); // clean out whatever's there

    VehicleGUI* vehicle = new VehicleGUI(
            scene,
            {.x = parkingLot.wm.x, .y = parkingLot.wm.y, .width = 25, .height = 25, .color = Qt::darkMagenta, .zPos = 100},
            {
                .entryDelay = 1000,
                .movementType = QEasingCurve::OutCubic,
                .approachGateTime = 1000,
                .throughGateTime = 1000,
                .xFirstEntryGateSensor = parkingLot.gate.entranceGate.initOpenSensor.wm.x + 25,
                .xSecondEntryGateSensor = parkingLot.gate.entranceGate.stayOpenSensor.wm.x + 25,
                .xFirstExitGateSensor = parkingLot.gate.exitGate.initOpenSensor.wm.x - 25,
                .xSecondExitGateSensor = parkingLot.gate.exitGate.stayOpenSensor.wm.x - 25,
                .yEntryTrack = parkingLot.gate.entranceGate.wm.y + 50,
                .yExitTrack = parkingLot.gate.exitGate.wm.y + 50,
                .xSpot = parkingLot.parkingFloors[1]->parkingSpots[1]->wm.x + 12,
                .ySpot = parkingLot.parkingFloors[1]->parkingSpots[1]->wm.y + 40,
                .generalMovementTime = 2000,
                .parkPauseTime = 1000,
                .parkTime = 1000
            },
            this,
            false
            ); // single vehicle

    activeVehicles.push_back(vehicle); // add to active vehicles
    // vehicle->animationGroup.setLoopCount(1);// single iteration (this is default)
    currAnimation.addAnimation(&(vehicle->animationGroup)); // get this animation
    currAnimation.start(); // start animation
    // TODO: need to clean up on full finish!
}

// stop all animations, clear to initial state.
void DemoManager::stopDemo() {
    currAnimation.stop(); // stop the animation (should be controlling with button enables, however)
    // currAnimation.clear(); // clear the vehicle animations, only when dynamically allocated
    for (VehicleGUI* vehicle : activeVehicles) { // cleanup our end.
        ((QObject*)vehicle)->deleteLater();
    }
    activeVehicles.clear(); // clear out the vector
    parkingLot.reset();
    availabilityDisplay->reset();
    // TODO: reset lot components to initial state.
    // reset all lot components
    // reset the availability display
}

/**
 * add the pmc receiver to all sensors that emit signals during process.
 * @param pmc top level pmc to receive signals from sensors
 */
void DemoManager::addSignalReceiver(ParkingManagementController *pmc) {
    parkingLot.gate.entranceGate.addSignalReceiver(pmc);
    parkingLot.gate.exitGate.addSignalReceiver(pmc);
} // end method

/**
 * metadata things for smoothing animations/painting
 */
void DemoManager::initGraphicsMetadata() {
    setRenderHint(QPainter::Antialiasing);
    scene.setBackgroundBrush(Qt::transparent);
    setAttribute(Qt::WA_TranslucentBackground);
} // end method

/**
 * add all items necessary to the scene of the
 * graphics view.
 */
void DemoManager::initScene() {
    scene.addItem(&parkingLot);
    for (ParkingFloorGUI* floor : parkingLot.parkingFloors) {
        scene.addItem(floor);
        for (ParkingSpotGUI* spot : floor->parkingSpots) {
            scene.addItem(spot);
            scene.addItem(spot->led);
            scene.addItem(spot->ultrasonicSensor);
            scene.addItem(spot->weightSensor);
        } // end loop
    } // end loop
    scene.addItem(&parkingLot.gate);
    scene.addItem(&parkingLot.gate.entranceGate);
    scene.addItem(&parkingLot.gate.entranceGate.led);
    scene.addItem(&parkingLot.gate.entranceGate.initOpenSensor);
    scene.addItem(&parkingLot.gate.entranceGate.stayOpenSensor);
    scene.addItem(&parkingLot.gate.entranceGate.spikes);
    scene.addItem(&parkingLot.gate.exitGate);
    scene.addItem(&parkingLot.gate.exitGate.led);
    scene.addItem(&parkingLot.gate.exitGate.initOpenSensor);
    scene.addItem(&parkingLot.gate.exitGate.stayOpenSensor);
    scene.addItem(&parkingLot.gate.exitGate.spikes);
} // end method

// TODO
// // potential override for final cleanups
// void DemoManager::closeEvent(QCloseEvent *event) {
//     event->accept();
//     cout << "closing.." << std::endl;
//     stopDemo();
// }

// for testing that i can change the values from here on anim finished
// void DemoManager::test() {
//     availabilityDisplay->floor1AvailEv.setText("blah");
// }