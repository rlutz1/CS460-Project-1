//
// Created by lutzr on 2/25/2026.
//

#include "EntranceGateGUI.h"
#include <QGraphicsScene>

EntranceGateGUI::EntranceGateGUI(QGraphicsScene& scene, GateId id) {
    this->id = id;
    scene.addItem((QGraphicsWidget*) &led);
    scene.addItem((QGraphicsWidget*) &initOpenSensor);
    scene.addItem((QGraphicsWidget*) &stayOpenSensor);
    scene.addItem((QGraphicsWidget*) &spikes);
}
