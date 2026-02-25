#include <iostream>
#include <QApplication>
// #include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QObject>
// #include <QSequentialAnimationGroup>
#include "run_demo.h"
// #include "Mediator/Mediator.h"
#include "PMSGUI/DemoManager.h"
#include "Definitions/Identifiers.h"
#include "Initialization.h"
// #include "PMSSoftware/ParkingManagementController.h"
// #include "ParkingLot/ParkingSpot.h"

// main access point to boot up the demo -- gui and backend both
int run_demo(int argc, char *argv[]) {

    QApplication a(argc, argv);
    InitializationPackage initPackage = initConfig(); // initialize config info for both front and backend
    // initialize the front end
    // initialize the backend
    // initialize sink? or unnecessary step
    // initWindow(); // initialize the window

    return QApplication::exec();
}

void initWindow(DemoManager &manager) {
    // setup main window layout
    QWidget mainLayout;
    QVBoxLayout layout(&mainLayout);
    mainLayout.setLayout(&layout);
    // todo: add mainLayout as parent layout to gui container for lot

    QPushButton button("Start Demo", &mainLayout);
    // TODO: next line
    // QObject::connect(&button, &QPushButton::clicked, &parking_lot, &ParkingLot::run_demo);

    // layout.addWidget(manager); // TODO: ensure this works, giving me type grief
    layout.addWidget(&button);
    mainLayout.show();
}

InitializationPackage initConfig() {
    // CONSTANTS, DO NOT CHANGE
    ParkingLotConfiguration lotConfig{
        .normalSpots = 28,
        .handicapSpots = 4,
        .evSpots = 4,
        .motorcycleSpots = 2,
        .entranceGates = 1,
        .exitGates = 1
    };

    InitializationPackage initPackage{};
    return initPackage;


}