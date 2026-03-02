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
DemoManager::DemoManager(QWidget* parent, InitializationPackage initPackage, int width, int height, AvailabilityGUI& availabilityDisplay) :
    parkingLot(
        scene,
        initPackage,
        {.x = 0, .y = 0, .width = width, .height = height, .color = Qt::darkGray, .zPos = 0}
        ),
    availabilityDisplay(&availabilityDisplay),
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
    stopDemo();
    VehicleGUI* vehicle = new VehicleGUI(
            scene,
            {.x = parkingLot.wm.x, .y = parkingLot.wm.y, .width = 25, .height = 25, .color = Qt::darkMagenta, .zPos = 100},
            {
                .movementType = QEasingCurve::OutCubic,
                .approachGateTime = 1000,
                .throughGateTime = 1000,
                .xFirstEntryGateSensor = parkingLot.gate.entranceGate.initOpenSensor.wm.x + 25,
                .xSecondEntryGateSensor = parkingLot.gate.entranceGate.stayOpenSensor.wm.x + 25,
                .xFirstExitGateSensor = parkingLot.gate.exitGate.initOpenSensor.wm.x - 25,
                .xSecondExitGateSensor = parkingLot.gate.exitGate.stayOpenSensor.wm.x - 25,
                .yEntryTrack = parkingLot.gate.entranceGate.wm.y + 50,
                // .yEntryTrack = 400,
                .yExitTrack = parkingLot.gate.exitGate.wm.y + 50,
                // .yExitTrack = 200,
                .xSpot = parkingLot.parkingFloors[1]->parkingSpots[1]->wm.x + 12,
                .ySpot = parkingLot.parkingFloors[1]->parkingSpots[1]->wm.y + 40,
                .generalMovementTime = 2000,
                .parkPauseTime = 1000,
                .parkTime = 1000
            },
            this
            ); // single vehicle
    // cout << parkingLot.parkingFloors[1]->parkingSpots[15]->wm.y << std::endl;
    activeVehicles.push_back(vehicle); // add to active vehicles
    currAnimation.addAnimation(vehicle->animationGroup); // get this animation
    // vehicle->ani
    currAnimation.setLoopCount(1); // single iteration (this is default)
    currAnimation.start(); // start animation
    // TODO: need to clean up on full finish!
}

// stop all animations, clear to initial state.
void DemoManager::stopDemo() {
    currAnimation.stop(); // stop the animation (should be controlling with button enables, however)
    currAnimation.clear(); // clear the vehicle animations
    for (VehicleGUI* vehicle : activeVehicles) { // cleanup our end.
        ((QObject*)vehicle)->deleteLater();
    }
    activeVehicles.clear(); // clear out the vector
    // TODO: reset lot components to initial state.
}

// metadata things for smoothing animations/painting
void DemoManager::initGraphicsMetadata() {
    setRenderHint(QPainter::Antialiasing);
    scene.setBackgroundBrush(Qt::transparent);
    setAttribute(Qt::WA_TranslucentBackground);
}

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