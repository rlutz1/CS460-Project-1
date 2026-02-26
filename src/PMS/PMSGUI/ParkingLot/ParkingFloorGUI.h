//
// Created by Eliud Garcia on 2/24/26.
//

#ifndef CS460_PROJECT_1_PARKINGFLOOR_H
#define CS460_PROJECT_1_PARKINGFLOOR_H
#include <QGraphicsWidget>
#include "ParkingSpotGUI.h"

#include "../../Initialization.h"
#include "../../Definitions/Identifiers.h"

class ParkingFloorGUI : QGraphicsWidget {
public:
    ParkingFloorGUI(QGraphicsScene& scene, InitializationPackage& initPackage);
};


#endif //CS460_PROJECT_1_PARKINGFLOOR_H