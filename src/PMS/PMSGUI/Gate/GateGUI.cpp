//
// Created by Eliud Garcia on 2/24/26.
//

#include "GateGUI.h"

#include <QGraphicsScene>
#include <QGraphicsWidget>



GateGUI::GateGUI(QGraphicsScene &scene, InitializationPackage &initPackage) :
    entranceGate(scene, initPackage.entranceGateId),
    exitGate(scene, initPackage.exitGateId)
    {

    scene.addItem((QGraphicsWidget*) &exitGate);
    scene.addItem((QGraphicsWidget*) &entranceGate);
}

