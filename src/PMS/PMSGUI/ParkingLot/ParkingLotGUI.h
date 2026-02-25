//
// Created by lutzr on 2/25/2026.
//

#ifndef CS460_PROJECT_1_PARKINGLOTGUI_H
#define CS460_PROJECT_1_PARKINGLOTGUI_H
#include <map>
#include <QGraphicsWidget>
class ParkingSpotGUI;
class QGraphicsScene;
class GateGUI;
struct SpotId;
struct GateId;

using std::map;

class ParkingLotGUI : QGraphicsWidget {

public:
    // ParkingLotGUI();
    ParkingLotGUI(QGraphicsScene& scene);
private:
    // map<SpotId, ParkingSpotGUI> parkingSpots; // TODO
    // map<GateId, GateGUI> gates;
};


#endif //CS460_PROJECT_1_PARKINGLOTGUI_H