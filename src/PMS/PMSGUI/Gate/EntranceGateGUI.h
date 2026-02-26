//
// Created by lutzr on 2/25/2026.
//

#ifndef CS460_PROJECT_1_ENTRANCEGATEGUI_H
#define CS460_PROJECT_1_ENTRANCEGATEGUI_H
#include <QGraphicsWidget>
#include "../../Initialization.h"
#include "../../Definitions/Identifiers.h"

class EntranceGateGUI : QGraphicsWidget {

public:
    EntranceGateGUI(QGraphicsScene& scene, GateId id);

    GateId id;
};


#endif //CS460_PROJECT_1_ENTRANCEGATEGUI_H