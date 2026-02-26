//
// Created by Eliud Garcia on 2/24/26.
//

#ifndef CS460_PROJECT_1_PARKINGFLOOR_H
#define CS460_PROJECT_1_PARKINGFLOOR_H
#include <QGraphicsWidget>
#include "ParkingSpotGUI.h"

#include "../../Initialization.h"
#include "../../Definitions/Identifiers.h"
#include "../GUIStructs/GUIStructs.h"

class ParkingFloorGUI : QGraphicsWidget {
    Q_OBJECT;
public:
    ParkingFloorGUI(QGraphicsScene& scene, InitializationPackage& initPackage, FloorId floorId);

    FloorId floorId;
    WidgetMeta wm;

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override;
};


#endif //CS460_PROJECT_1_PARKINGFLOOR_H