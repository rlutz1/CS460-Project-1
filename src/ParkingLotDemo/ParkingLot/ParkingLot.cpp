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
ParkingLot::ParkingLot(QWidget *parent) : QWidget(parent) {

    layout = new QVBoxLayout(this);
    setLayout(layout);
    QPushButton *button = new QPushButton("testing", this);
    button->resize(200, 200);
    layout->addWidget(button);

};

ParkingLot::ParkingLot(Mediator* m, QWidget *parent) : QWidget(parent) {

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
