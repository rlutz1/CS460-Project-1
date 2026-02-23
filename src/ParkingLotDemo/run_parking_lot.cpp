#include <iostream>
#include <QApplication>
#include <QPushButton>
#include "../run_demo.h"
#include "Mediator/Mediator.h"
#include "ParkingLot/ParkingLot.h"
#include "PMSSoftware/ParkingManagementController.h"

int run_parking_lot(int argc, char *argv[]) {
    // QApplication a(argc, argv);
    // QPushButton button("I am the parking lot application driver.", nullptr);
    // button.resize(200, 100);
    // button.show();
    // return QApplication::exec();
    ParkingManagementController pmc;
    ParkingLot pl;
    Mediator mediator(&pl, &pmc);
    std::cout << "Parking Lot Making\n";
    pl.add_output_stream(&mediator);
    pmc.add_output_stream(&mediator);
    pl.send_signal();
    return 0;
}