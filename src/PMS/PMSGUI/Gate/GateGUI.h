//
// Created by Eliud Garcia on 2/24/26.
//

#ifndef CS460_PROJECT_1_GATE_H
#define CS460_PROJECT_1_GATE_H
#include <QGraphicsWidget>
#include "EntranceGateGUI.h"
#include "ExitGateGUI.h"
#include "../../Initialization.h"
#include "../../Definitions/Identifiers.h"
class QGraphicsScene;

class GateGUI : QGraphicsWidget {
    Q_OBJECT;

public:
    GateGUI(QGraphicsScene& scene, InitializationPackage& initPackage);

private:
    EntranceGateGUI entranceGate;
    ExitGateGUI exitGate;

};


#endif //CS460_PROJECT_1_GATE_H