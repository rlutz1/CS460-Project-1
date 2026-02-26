//
// Created by Eliud Garcia on 2/24/26.
//

#include "DemoManager.h"

#include <iostream>

#include "../Initialization.h"
#include <QPoint>
using std::cout;


#include "ParkingLot/ParkingLotGUI.h"

#define Y_ENTRY_TRACK (-100)
#define Y_EXIT_TRACK 100

// this constructor initializes the parking lot, which is the wrapper
// of the whole visual.
DemoManager::DemoManager(QWidget* parent, InitializationPackage initPackage, int width, int height) :
    parkingLot(scene, initPackage),
    QGraphicsView(parent) {
    this->setMinimumSize(QSize(width, height));
    parkingLot.sl = {.x = 0, .y = 0, .width = width, .height = height};
    // scene.addItem((QGraphicsWidget*) &parkingLot);
    cout << "we got this far..." << std::endl;
    // for (ParkingFloorGUI* floor : parkingLot.parkingFloors) {
    //     cout << "something" << std::endl;
    //     // scene.addItem((QGraphicsWidget*) floor);
    // }
    // parkingFloors = &(parkingLot.parkingFloors);
    this -> show();
    setScene(&scene);
}

// void DemoManager::initParkingLot(QGraphicsScene& scene, QWidget& parent, )

// run many vehicles with pseudorandomness
void DemoManager::runChaosDemo() {
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
    // TODO
}

// stop all animations, clear to initial state.
void DemoManager::stopDemo() {
    // TODO
}

// metadata things for smoothing animations/painting
void DemoManager::initGraphicsMetadata() {
    setRenderHint(QPainter::Antialiasing);
    scene.setBackgroundBrush(Qt::transparent);
    setAttribute(Qt::WA_TranslucentBackground);
}