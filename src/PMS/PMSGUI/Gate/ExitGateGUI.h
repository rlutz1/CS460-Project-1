//
// Created by lutzr on 2/25/2026.
//

#ifndef CS460_PROJECT_1_EXITGATEGUI_H
#define CS460_PROJECT_1_EXITGATEGUI_H
#include <QGraphicsWidget>

#include "../../Initialization.h"
#include "../../Definitions/Identifiers.h"
#include "../Hardware/LedGUI.h"
#include "../Hardware/SensorGUI.h"
#include "../Hardware/SpikesGUI.h"

class ExitGateGUI : QGraphicsWidget {
    Q_OBJECT;
public:
    ExitGateGUI(QGraphicsScene& scene, GateId id);

    GateId id;
    LedGUI led;
    SensorGUI initOpenSensor;
    SensorGUI stayOpenSensor;
    SpikesGUI spikes;
};


#endif //CS460_PROJECT_1_EXITGATEGUI_H