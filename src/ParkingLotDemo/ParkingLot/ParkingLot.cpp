//
// Created by lutzr on 2/22/2026.
//

#include "ParkingLot.h"
#include "../Mediator/Mediator.h"
#include <iostream>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QStackedLayout>
#include <QParallelAnimationGroup>

#include "ParkingSpot.h"
#include "Vehicle.h"

// namespace ParkingLot {
ParkingLot::ParkingLot(QWidget *parent) : QGraphicsView(parent) {

    scene = new QGraphicsScene;
    ParkingSpot* parking_spot_1 = new ParkingSpot("Spot 1", QPoint(0, 0));
    ParkingSpot* parking_spot_2 = new ParkingSpot("Spot 2", QPoint(60, 0));
    ParkingSpot* parking_spot_3 = new ParkingSpot("Spot 3", QPoint(120, 0));
    parking_spots = {parking_spot_1, parking_spot_2, parking_spot_3};
    for (ParkingSpot* parking_spot : parking_spots) {
        scene -> addItem(parking_spot);
    }
    setScene(scene);

    // WITH HBOX AS QWIDGET:
    // layout = new QHBoxLayout(this);
    // setLayout(layout);
    // // QPushButton *button = new QPushButton("testing", this);
    // // button->resize(200, 200); // this is not necessary
    // ParkingSpot* parking_spot_1 = new ParkingSpot("Spot 1", this);
    // ParkingSpot* parking_spot_2 = new ParkingSpot("Spot 2", this);
    // ParkingSpot* parking_spot_3 = new ParkingSpot("Spot 3", this);
    // parking_spots = {parking_spot_1, parking_spot_2, parking_spot_3};
    // for (ParkingSpot* parking_spot : parking_spots) {
    //     layout->addWidget(parking_spot);
    // }
    //
    // std::cout << parking_spot_3->x();

};

void ParkingLot::add_output_stream(Mediator* m) {
    this -> mediator = m;
} // end method

void ParkingLot::hardware_update(std::string update) {
    // std::cout << "PL: Received Update to Hardware: "<< str << "\n";
    // TESTING ONLY
    std::string delimiter = "|"; // hardcoded
    std::string notification = update.substr(1, update.find(delimiter)); // notification is special key
    if (notification == "OCCUPIED_CHANGE_COLOR") {
        // update LED to red

    } else if (notification == "AVAILABLE_CHANGE_COLOR") {
        // update LED to available color
    }
} // end method

// void ParkingLot::add_component(void* component) {
//     this -> button = (QPushButton*) component;
// }

void ParkingLot::send_signal(std::string update) {
    this -> mediator -> send_to_PMC(update);
} // end method

void ParkingLot::run_demo() {
    demo_manager = new DemoManager(this);
    demo_manager -> init();
    demo_manager -> run(3);
}

void ParkingLot::stop_demo() {
    demo_manager -> stop();
    // free(demo_manager);
}

void ParkingLot::trigger_vehicle_parked(std::string spotId, bool vehicle_detected) {
    std::cout << spotId << " was parked in." << std::endl;
    this->send_signal(spotId + "|PARKED");
}

void ParkingLot::trigger_vehicle_left(std::string spotId, bool vehicle_detected) {
    std::cout << spotId << " is no longer occupied in." << std::endl;
    this->send_signal(spotId + "|UNPARKED");
}

QSize ParkingLot::sizeHint() const {
    return QSize(500, 400);
}

/// ============================================================
/// DEMO MANAGER
/// ============================================================

DemoManager::DemoManager(ParkingLot* parent) {
    this -> parent = parent;
}

void DemoManager::init() {
    // initialization tasks, empty for now
}

void DemoManager::run(int n_vehicles) {
    std::cout << "running demo..." << std::endl;

    QParallelAnimationGroup* group = new QParallelAnimationGroup;
    Vehicle* vehicle; bool assigned;
    for (int i = 0; i < n_vehicles; i++) { // quick and dirty, better ways
        assigned = false;
        for (ParkingSpot* ps : parent->get_parking_spots()) {
            if (ps->available) {
                vehicle = new Vehicle("Vehicle " + std::to_string(i), parent, ps->spotId);
                // std::cout << "here1" << std::endl;
                ps->available = false;
                // std::cout << "here2" << std::endl;
                group->addAnimation(vehicle -> gen_animation_group(ps->pos.x(), ps->pos.y()));
                // std::cout << "here3" << std::endl;
                // std::cout << ps->x() << ps->y() << std::endl;
                assigned = true;
                break;
            }
        }
        if (assigned) {
            parent->get_scene()->addItem(vehicle);
            // std::cout << "here4" << std::endl;
        }

    }


    group->start();
    // std::cout << "here5" << std::endl;
    // group.duration(-1);
    // ParkingSpot dest = parking_spots.remove([](ParkingSpot* ps){ return ps->available; });
}

void DemoManager::stop() {
}

// } // ParkingLot
