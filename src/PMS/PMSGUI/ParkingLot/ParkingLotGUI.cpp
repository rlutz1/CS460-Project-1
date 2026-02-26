//
// Created by lutzr on 2/25/2026.
//

#include "ParkingLotGUI.h"

#include <QGraphicsScene>

#include "ParkingFloorGUI.h"
#include "../Gate/GateGUI.h"
#include "../../Initialization.h"


#define Y_TOP_LOTS 300
#define Y_BOTTOM_LOTS (-200)
#define Y_GATE_CENTER 0



ParkingLotGUI::ParkingLotGUI(QGraphicsScene& scene, InitializationPackage& initPackage) : gate(scene, initPackage) {

    // init floors
    for (int i = 0; i < initPackage.numbers.floors; i++) {
        ParkingFloorGUI floor(scene, initPackage);
        parkingFloors.push_back(&floor);
        scene.addItem((QGraphicsWidget*) &floor);
    }

}
