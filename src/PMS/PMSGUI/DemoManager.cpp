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

#define Y_ENTRY_TRACK 400
#define Y_EXIT_TRACK 200

// this constructor initializes the parking lot, which is the wrapper
// of the whole visual.
DemoManager::DemoManager(QWidget* parent, InitializationPackage initPackage, int width, int height) :
    parkingLot(
        scene,
        initPackage,
        {.x = 0, .y = 0, .width = width, .height = height, .color = Qt::darkGray, .zPos = 0}
        ),
    QGraphicsView(parent) {
    this->setMinimumSize(QSize(width, height));
    setScene(&scene);
}

// run many vehicles with pseudorandomness
void DemoManager::runChaosDemo() {
    // TODO: below is copied from old code for ref
    // std::cout << "running demo..." << std::endl;
    //
    // QParallelAnimationGroup* group = new QParallelAnimationGroup;
    // Vehicle* vehicle = nullptr; bool assigned;
    // for (int i = 1; i <= n_vehicles; i++) { // quick and dirty, better ways
    //     assigned = false;
    //     for (ParkingSpot* ps : parent->get_parking_spots()) {
    //         if (ps->available) {
    //             vehicle = new Vehicle("Vehicle " + std::to_string(i), parent, ps->spotId);
    //             // std::cout << "here1" << std::endl;
    //             ps->available = false;
    //             // std::cout << "here2" << std::endl;
    //             group->addAnimation(vehicle -> gen_animation_group(ps->pos.x(), ps->pos.y(), i * 1000));
    //             // std::cout << "here3" << std::endl;
    //             // std::cout << ps->x() << ps->y() << std::endl;
    //             assigned = true;
    //             break;
    //         }
    //     }
    //     if (assigned && vehicle) {
    //         parent->add_to_scene(vehicle);
    //         // std::cout << "here4" << std::endl;
    //     }
    //
    // }
    //
    // group->setLoopCount(-1);
    // group->start();
    // std::cout << "here5" << std::endl;
    // group.duration(-1);
    // ParkingSpot dest = parking_spots.remove([](ParkingSpot* ps){ return ps->available; });
}

// run exactly 1 vehicle through entry, park, and exit.
void DemoManager::runSimpleDemo() {
    currAnimation.stop(); // stop the animation (should be controlling with button enables, however)
    currAnimation.clear(); // remove and delete all animations in group
    for (VehicleGUI* vehicle : activeVehicles) { // cleanup our end.
        delete vehicle;
    }
    activeVehicles.clear(); // clear out the vector
    VehicleGUI* vehicle = new VehicleGUI(
            scene,
            {.x = 0, .y = parkingLot.gate.entranceGate.wm.x, .width = 25, .height = 25, .color = Qt::darkMagenta, .zPos = 100},
            {
                .movementType = QEasingCurve::OutCubic,
                .approachGateTime = 1000,
                .throughGateTime = 1000,
                .xFirstEntryGateSensor = parkingLot.gate.entranceGate.initOpenSensor.wm.x,
                .xSecondEntryGateSensor = parkingLot.gate.entranceGate.stayOpenSensor.wm.x,
                .xFirstExitGateSensor = parkingLot.gate.exitGate.initOpenSensor.wm.x, // TODO: somethings off here
                .xSecondExitGateSensor = parkingLot.gate.exitGate.stayOpenSensor.wm.x,
                .yEntryTrack = parkingLot.gate.entranceGate.wm.x,
                .yExitTrack = parkingLot.gate.exitGate.wm.x,
                .xSpot = parkingLot.parkingFloors[1]->parkingSpots[0]->wm.x,
                .ySpot = parkingLot.parkingFloors[1]->parkingSpots[0]->wm.y,
                .generalMovementTime = 2000,
                .parkPauseTime = 1000,
                .parkTime = 1000
            }
            ); // single vehicle
    activeVehicles.push_back(vehicle); // add to active vehicles
    currAnimation.addAnimation(vehicle->animationGroup); // get this animation
    // vehicle->ani
    currAnimation.setLoopCount(1); // single iteration (this is default)
    currAnimation.start(); // start animation
    // TODO: need to clean up on full finish!
}

// stop all animations, clear to initial state.
void DemoManager::stopDemo() {
    // TODO
    // clean up task. need to test, but putting here for the moment.
    // closing window will also take care of this since they are
    // items in the scene.
    currAnimation.stop(); // stop the animation (should be controlling with button enables, however)
    currAnimation.clear(); //
    for (VehicleGUI* vehicle : activeVehicles) {
        delete vehicle;
    }
    // TODO: reset lot components to initial state.
}

// metadata things for smoothing animations/painting
void DemoManager::initGraphicsMetadata() {
    setRenderHint(QPainter::Antialiasing);
    scene.setBackgroundBrush(Qt::transparent);
    setAttribute(Qt::WA_TranslucentBackground);
}