#include <iostream>
#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QObject>
#include <QSequentialAnimationGroup>
#include "../run_demo.h"
#include "Mediator/Mediator.h"
#include "ParkingLot/ParkingLot.h"
#include "PMSSoftware/ParkingManagementController.h"

int run_parking_lot(int argc, char *argv[]) {

    QApplication a(argc, argv);

    QMainWindow* mainWindow = new QMainWindow();
    QWidget* mainLayout = new QWidget(mainWindow);
    QVBoxLayout* layout = new QVBoxLayout(mainLayout);
    mainLayout -> setLayout(layout);

    // ParkingLot parking_lot;
    // layout -> addWidget((QWidget*) &parking_lot);


    QPushButton button("Sensor Trigger", nullptr);
    button.resize(200, 100);
    layout -> addWidget(&button);

    // ParkingManagementController pmc;
    // Mediator mediator(&parking_lot, &pmc);
    // std::cout << "Parking Lot Making\n";
    // parking_lot.add_output_stream(&mediator);
    // parking_lot.add_component(&button);
    // pmc.add_output_stream(&mediator);

    // pl.send_signal();
    // QSequentialAnimationGroup group;

    // QObject::connect(&button, &QPushButton::clicked, &parking_lot, &ParkingLot::send_signal);

    // mainWindow
    // button.show();
    mainWindow -> setCentralWidget(mainLayout);
    mainWindow -> show();



    // return 0;

    return QApplication::exec();
}