//
// Created by lutzr on 2/25/2026.
//

#ifndef CS460_PROJECT_1_RUN_DEMO_H
#define CS460_PROJECT_1_RUN_DEMO_H

#include <vector>
using std::vector;

#include "Definitions/Identifiers.h" // this works, but trying to avoid headers in headers
struct InitializationPackage;
struct NumParkingLotComponents;
class DemoManager;
class QWidget;

int run_demo(int argc, char *argv[]);
void initWindow(QWidget& mainWindow, DemoManager& manager);
InitializationPackage genInitPackage();
GateId initGateId(GateType type);
vector<SpotId> initSpotIds(NumParkingLotComponents numbers);
void initSpotIterator(vector<SpotId>& spotIds, string prefix, char numSpots, FloorId floorId, SpotType type);

#endif //CS460_PROJECT_1_RUN_DEMO_H