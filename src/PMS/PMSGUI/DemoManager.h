/**
 * this class acts as a manger of the demos, and doubles
 * as the graphics view where the primary demonstration occurs.
 */

#ifndef CS460_PROJECT_1_DEMOMANAGER_H
#define CS460_PROJECT_1_DEMOMANAGER_H

#include <map>
#include <QGraphicsView>
#include <QParallelAnimationGroup>

#include "VehicleGUI.h"
#include "ParkingLot/ParkingLotGUI.h"
#include "../Initialization.h"
#include "../PMC/ParkingManagementController.h"
#include "Availability/AvailabilityGUI.h"

class QGraphicsScene;
class GateGUI;
class VehicleGUI;
struct SpotId;
struct GateId;

class DemoManager : public QGraphicsView {
    Q_OBJECT;
public:
    DemoManager(
        QWidget* parent,
        InitializationPackage initPackage,
        int width,
        int height,
        AvailabilityGUI& availabilityDisplay
        );

    // public for signal easier signal relaying between vehicle and different parking lot components
    QPointer<ParkingLotGUI> parkingLot;
    void addSignalReceiver(std::shared_ptr<ParkingManagementController> pmc) const;

public slots: // slots for signals to send to!
    void runSimpleDemo();
    void runChaosDemo();
    void stopDemo();
    // void test(); // testing animation connection

private:
    QGraphicsScene scene;
    QParallelAnimationGroup currAnimation;
    QVector<QPointer<VehicleGUI>> activeVehicles;
    AvailabilityGUI* availabilityDisplay;

    void initScene();
    void initGraphicsMetadata();
};


#endif //CS460_PROJECT_1_DEMOMANAGER_H