//
// Created by Eliud Garcia on 2/24/26.
//

#ifndef CS460_PROJECT_1_PARKINGSPOT_H
#define CS460_PROJECT_1_PARKINGSPOT_H
#include <QGraphicsWidget>
#include "../GUIStructs/GUIStructs.h"
#include "../../Initialization.h"
#include "../Hardware/LedGUI.h"
#include "../Hardware/SensorGUI.h"

class ParkingSpotGUI : QGraphicsWidget {
    Q_OBJECT;

public:
    ParkingSpotGUI(QGraphicsScene& scene, InitializationPackage& initPackage, SpotId spotId, WidgetMeta widgetMeta);

    QColor availableColor;
    QColor occupiedColor;
    QColor unavailableColor;
    LedGUI* led;
    SensorGUI* ultrasonicSensor;
    SensorGUI* weightSensor;
    SpotId spotId;
    WidgetMeta wm;

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override;
};


#endif //CS460_PROJECT_1_PARKINGSPOT_H