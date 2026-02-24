//
// Created by lutzr on 2/22/2026.
//

#include "ParkingLot.h"
#include "../Mediator/Mediator.h"
#include <iostream>
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
    this -> setRenderHint(QPainter::Antialiasing);
    scene -> setBackgroundBrush(Qt::transparent);
    this -> setAttribute(Qt::WA_TranslucentBackground);
    setScene(scene);
};

void ParkingLot::add_output_stream(Mediator* m) {
    this -> mediator = m;
} // end method

void ParkingLot::hardware_update(std::string update) {
    std::cout << "PL: Received Update to Hardware. "<< "\n";
    // TESTING ONLY
    std::string delimiter = "|"; // hardcoded
    std::string notification = update.substr(update.find(delimiter) + 1, update.length()); // notification is special key
    std::string id = update.substr(0, update.find(delimiter));
    if (notification == "OCCUPIED_CHANGE_COLOR") {
        // update LED to red
        // this is some really stupid code, and i'm aware, for some demonstration of concept *sobs*
        for (ParkingSpot *ps: parking_spots) {
            std::cout << ps->spotId << " " << id << std::endl;
            if (ps->spotId == id) {
                ps->update_led("OCCUPIED");
                break;
            }
        }

    } else if (notification == "AVAILABLE_CHANGE_COLOR") {
        // update LED to available color
        for (ParkingSpot *ps: parking_spots) {
            if (ps->spotId == id) {
                ps->update_led("AVAILABLE");
                ps->available = true;
                break;
            }
        }
    }
    // this -> update();
    this -> scene -> update(); // NEEEEED! this to fully repaint components
} // end method

void ParkingLot::send_signal(std::string update) {
    this -> mediator -> send_to_PMC(update);
} // end method

void ParkingLot::run_demo() {
    demo_manager = new DemoManager(this);
    demo_manager -> init();
    demo_manager -> run(2);
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

void ParkingLot::add_to_scene(QGraphicsWidget* widget) {
    scene -> addItem(widget);
}

QSize ParkingLot::sizeHint() const {
    return QSize(1000, 500);
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
    Vehicle* vehicle = nullptr; bool assigned;
    for (int i = 1; i <= n_vehicles; i++) { // quick and dirty, better ways
        assigned = false;
        for (ParkingSpot* ps : parent->get_parking_spots()) {
            if (ps->available) {
                vehicle = new Vehicle("Vehicle " + std::to_string(i), parent, ps->spotId);
                // std::cout << "here1" << std::endl;
                ps->available = false;
                // std::cout << "here2" << std::endl;
                group->addAnimation(vehicle -> gen_animation_group(ps->pos.x(), ps->pos.y(), i * 1000));
                // std::cout << "here3" << std::endl;
                // std::cout << ps->x() << ps->y() << std::endl;
                assigned = true;
                break;
            }
        }
        if (assigned && vehicle) {
            parent->add_to_scene(vehicle);
            // std::cout << "here4" << std::endl;
        }

    }

    group->setLoopCount(-1);
    group->start();
    // std::cout << "here5" << std::endl;
    // group.duration(-1);
    // ParkingSpot dest = parking_spots.remove([](ParkingSpot* ps){ return ps->available; });
}

void DemoManager::stop() {
}

// } // ParkingLot
