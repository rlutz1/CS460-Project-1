//
// Created by lutzr on 2/25/2026.
//

#ifndef CS460_PROJECT_1_ENTRANCEGATEGUI_H
#define CS460_PROJECT_1_ENTRANCEGATEGUI_H
#include <QGraphicsWidget>
#include "../../Initialization.h"
#include "../../Definitions/Identifiers.h"
#include "../Hardware/LedGUI.h"
#include "../Hardware/SensorGUI.h"
#include "../Hardware/SpikesGUI.h"

#include "../GUIStructs/GUIStructs.h"

class EntranceGateGUI : QGraphicsWidget {
    Q_OBJECT;

public:
    EntranceGateGUI(QGraphicsScene& scene, InitializationPackage& initPackage, GateId id, WidgetMeta widgetMeta);

    WidgetMeta wm;
    GateId id;
    LedGUI led;
    SensorGUI initOpenSensor;
    SensorGUI stayOpenSensor;
    SpikesGUI spikes;

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override;

};


#endif //CS460_PROJECT_1_ENTRANCEGATEGUI_H