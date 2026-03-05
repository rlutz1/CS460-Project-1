/**
 * this is primarily a visual container class for parking spot widgets.
 */

#ifndef CS460_PROJECT_1_PARKINGFLOOR_H
#define CS460_PROJECT_1_PARKINGFLOOR_H

#include "ParkingSpotGUI.h"
#include <QPointer>
#include <QVector>
#include "../../Initialization.h"
#include "../../Definitions/Identifiers.h"
#include "../GUIStructs/GUIStructs.h"

class ParkingFloorGUI : public QGraphicsWidget {
    Q_OBJECT;
public:
    ParkingFloorGUI(QGraphicsScene& scene, InitializationPackage& initPackage, FloorId floorId, WidgetMeta widgetMeta);

    FloorId floorId;
    WidgetMeta wm;
    QVector<QPointer<ParkingSpotGUI>> parkingSpots; // TODO: try unique_ptr

    void reset();

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override;

private:
    void initGenFloor(QGraphicsScene& scene, InitializationPackage& initPackage);
    void initFirstFloor(QGraphicsScene& scene, InitializationPackage& initPackage);
};

#endif //CS460_PROJECT_1_PARKINGFLOOR_H