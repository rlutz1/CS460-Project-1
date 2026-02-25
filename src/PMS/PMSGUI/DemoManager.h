//
// Created by Eliud Garcia on 2/24/26.
//

#ifndef CS460_PROJECT_1_DEMOMANAGER_H
#define CS460_PROJECT_1_DEMOMANAGER_H

#include <map>
#include <QGraphicsView>

#include "ParkingLot/ParkingLotGUI.h"
// class ParkingLotGUI;
class QGraphicsScene;

#include "ParkingLot/ParkingLotGUI.h"
// #include "ParkingLot/ParkingFloorGUI.h"
class GateGUI;
struct SpotId;
struct GateId;
#include "../Initialization.h";

using std::map;


// demo manager -- container for the graphic view and initiating the
// stop and start of demos.
class DemoManager : public QGraphicsView {
    Q_OBJECT;
public:
    DemoManager(QWidget* parent, InitializationPackage initPackage);

public slots: // slots for signals to send to!
    void runSimpleDemo();
    void runChaosDemo();
    void stopDemo();

private:
    QGraphicsScene scene;
    ParkingLotGUI parkingLot;


    void initGraphicsMetadata();
};


#endif //CS460_PROJECT_1_DEMOMANAGER_H