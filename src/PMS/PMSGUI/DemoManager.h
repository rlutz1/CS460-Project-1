//
// Created by Eliud Garcia on 2/24/26.
//

#ifndef CS460_PROJECT_1_DEMOMANAGER_H
#define CS460_PROJECT_1_DEMOMANAGER_H

#include <map>
#include <QGraphicsView>

#include "VehicleGUI.h"
#include "ParkingLot/ParkingLotGUI.h"
#include "../Initialization.h"

class QGraphicsScene;
class GateGUI;
struct SpotId;
struct GateId;


using std::map;

// demo manager -- container for the graphic view and initiating the
// stop and start of demos.
class DemoManager : public QGraphicsView {
    Q_OBJECT;
public:
    DemoManager(QWidget* parent, InitializationPackage initPackage, int width, int height);

public slots: // slots for signals to send to!
    void runSimpleDemo();
    void runChaosDemo();
    void stopDemo();

private:
    QGraphicsScene scene;
    ParkingLotGUI parkingLot;
    vector<ParkingFloorGUI*>* parkingFloors;
    vector<VehicleGUI*> vehicles;

    void initGraphicsMetadata();
};


#endif //CS460_PROJECT_1_DEMOMANAGER_H