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
#include "../GUIStructs/GUIStructs.h"
#include <QGraphicsScene>

class GateGUI : QGraphicsWidget {
    Q_OBJECT;

public:
    GateGUI(QGraphicsScene& scene, InitializationPackage& initPackage, WidgetMeta widgetMeta);

    WidgetMeta wm;
    EntranceGateGUI entranceGate;
    ExitGateGUI exitGate;

private:


protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override;

};


#endif //CS460_PROJECT_1_GATE_H