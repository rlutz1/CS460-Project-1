#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QObject>
#include "../run_demo.h"
#include "Mediator/Mediator.h"
#include "ParkingLot/ParkingLot.h"
#include "PMSSoftware/ParkingManagementController.h"

int run_parking_lot(int argc, char *argv[]) {

    ParkingManagementController pmc;
    ParkingLot parker;
    Mediator mediator(&parker, &pmc);
    std::cout << "Parking Lot Making\n";
    parker.add_output_stream(&mediator);
    pmc.add_output_stream(&mediator);
    // pl.send_signal();

    QApplication a(argc, argv);
    QPushButton button("Sensor Trigger", nullptr);
    button.resize(200, 100);
    QObject::connect(&button, &QPushButton::clicked, &parker, &ParkingLot::send_signal);

    button.show();




    // return 0;

    return QApplication::exec();
}