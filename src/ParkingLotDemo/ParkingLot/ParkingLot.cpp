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
#include <QStackedLayout>

#include "ParkingSpot.h"

// namespace ParkingLot {
ParkingLot::ParkingLot(QWidget *parent) : QGraphicsView(parent) {

    scene = new QGraphicsScene;
    // myPopulateScene(&scene);
    // QGraphicsRectItem *rect = scene.addRect(QRectF(0, 0, 100, 100));
    // QGraphicsItem *item = scene.itemAt(50, 50, QTransform());
    scene -> addRect(QRectF(50, 50, 100, 200), QPen(Qt::black), QBrush(Qt::green));
    // QGraphicsView view(&scene);
    setScene(scene);
    // view.show();

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

void ParkingLot::hardware_update(std::string str) {
    // std::cout << "PL: Received Update to Hardware: "<< str << "\n";
    // if (str == "1") {
    //     this -> button -> setStyleSheet("background-color: red; color: white;");
    // } else {
    //     this -> button -> setStyleSheet("");
    // }
} // end method

// void ParkingLot::add_component(void* component) {
//     this -> button = (QPushButton*) component;
// }

void ParkingLot::send_signal() {
    this -> mediator -> send_to_PMC("FROM PL: signal triggered!");
} // end method

QSize ParkingLot::sizeHint() const {
    return QSize(500, 400);
}

// } // ParkingLot
