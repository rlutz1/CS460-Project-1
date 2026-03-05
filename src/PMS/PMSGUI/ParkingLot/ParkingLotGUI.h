/**
 * this class is primarily used as a container for all components of the lot
 */

#ifndef CS460_PROJECT_1_PARKINGLOTGUI_H
#define CS460_PROJECT_1_PARKINGLOTGUI_H

#include "ParkingFloorGUI.h"
#include "../Gate/GateGUI.h"
#include "../../Initialization.h"
#include "../GUIStructs/GUIStructs.h"
#include <QPointer>
#include <QVector>

class QGraphicsScene;
using string = std::string;

// ParkingLot GUI has floors and gate. sets up those widgets
// and adds to the scene.
class ParkingLotGUI : public QGraphicsWidget {
    Q_OBJECT;
public:
    ParkingLotGUI(QGraphicsScene& scene, InitializationPackage& initPackage, WidgetMeta widgetMeta);

    WidgetMeta wm;
    QVector<QPointer<ParkingFloorGUI>> parkingFloors;
    QPointer<GateGUI> gate;

    void reset();
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override;

};

#endif //CS460_PROJECT_1_PARKINGLOTGUI_H