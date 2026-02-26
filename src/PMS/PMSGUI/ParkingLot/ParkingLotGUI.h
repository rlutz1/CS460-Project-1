//
// Created by lutzr on 2/25/2026.
//

#ifndef CS460_PROJECT_1_PARKINGLOTGUI_H
#define CS460_PROJECT_1_PARKINGLOTGUI_H
#include <map>
#include <QGraphicsWidget>
#include "ParkingFloorGUI.h"
#include "../Gate/GateGUI.h"
#include "../Availability/AvailabilityGUI.h"
#include "../../Initialization.h"
#include "../../Definitions/Identifiers.h"
class QGraphicsScene;
using string = std::string;
using std::map; // this may not work, remove if so

// ParkingLot GUI has floors and gate. sets up those widgets
// and adds to the scene.
class ParkingLotGUI : QGraphicsWidget {

public:
    ParkingLotGUI(QGraphicsScene& scene, InitializationPackage& initPackage);
private:
    map<SpotId, ParkingFloorGUI*> parkingFloors; // TODO
    // map<string, GateGUI> gates;
    // vector<ParkingFloorGUI*> parkingFloors;
    GateGUI gate;
};



#endif //CS460_PROJECT_1_PARKINGLOTGUI_H