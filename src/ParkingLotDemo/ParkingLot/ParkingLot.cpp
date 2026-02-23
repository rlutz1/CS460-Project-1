//
// Created by lutzr on 2/22/2026.
//

#include "ParkingLot.h"
#include "../Mediator/Mediator.h"
#include <iostream>
#include <QHBoxLayout>
#include <QStackedLayout>

#include "ParkingSpot.h"

// namespace ParkingLot {
ParkingLot::ParkingLot(QWidget *parent) : QWidget(parent) {
    // TODO hardcoded to test
    // ParkingSpot spot1("Vehicle 1", this); ParkingSpot spot2("Vehicle 2", this); ParkingSpot spot3("Vehicle 3", this);
    // this -> parking_spots = {&spot1, &spot2, &spot3};

    // changing this to a held value didn't help
    layout = new QHBoxLayout(this); // TODO: memory leaking...
    setStyleSheet("background-color: blue;");

    // for (ParkingSpot* spot : this -> parking_spots) {
    //     layout -> addWidget(spot);
    //
    //     // this -> stackUnder(spot);
    // }
    // layout -> addStretch();
    QPushButton button("testing", this);
    button.resize(QSize(200, 400));
    layout->addWidget(&button); // this is also not appearing!

    setMinimumSize(QSize(500, 400)); // this did nothing
    setLayout(layout);
    // this -> show();
    // button.show();
    // std::cout << this -> isVisible() << std::endl;
    // this -> show();
};

ParkingLot::ParkingLot(Mediator* m, QWidget *parent) : QWidget(parent) {
    // this -> mediator = m;
    // // TODO hardcoded to test
    // ParkingSpot spot1("Vehicle 1", this); ParkingSpot spot2("Vehicle 2", this); ParkingSpot spot3("Vehicle 3", this);
    // this -> parking_spots = {&spot1, &spot2, &spot3};
    //
    // QHBoxLayout* layout = new QHBoxLayout(); // TODO: memory leaking...
    // this -> setLayout(layout);
    //
    // for (ParkingSpot* spot : this -> parking_spots) {
    //     layout -> addWidget((QWidget*)spot);
    //     // this -> stackUnder(spot);
    // }
    // this -> setStyleSheet("background-color: grey;");
    // this -> show();
    // free(layout);

} // end constructor

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
