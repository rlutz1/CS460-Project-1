/**
 * this class is primarily for visualize a vehicle
 * driving through the lot, entering, exiting, and parking.
 * these are dynamically created by the demo manager.
 */

#ifndef CS460_PROJECT_1_VEHICLE_H
#define CS460_PROJECT_1_VEHICLE_H
#include <QGraphicsWidget>
#include <QSequentialAnimationGroup>
#include <QPropertyAnimation>
#include "DemoManager.h"
#include "../../PMS/Definitions/Identifiers.h"
#include "GUIStructs/GUIStructs.h"
#include <QPauseAnimation>
class DemoManager;

class VehicleGUI : public QGraphicsWidget {

public:
    VehicleGUI(
        QGraphicsScene& scene,
        WidgetMeta widgetMeta,
        AnimationMeta animMeta,
        DemoManager* demoManager,
        bool chaos,
        int floorToParkIn,
        int parkSpotIndexFromFloor
        );

    DemoManager* demoManager;
    QSequentialAnimationGroup animationGroup;
    QSequentialAnimationGroup initialAnimation;
    QSequentialAnimationGroup ongoingAnimation;

    QPauseAnimation offsetPause;
    QPropertyAnimation approachEntryGate;
    QPropertyAnimation passSecondEntrySensor;
    QPropertyAnimation findSpot;
    QPropertyAnimation park;
    QPropertyAnimation unpark;
    QPropertyAnimation approachExitGate;
    QPropertyAnimation passSecondExitSensor;
    QPropertyAnimation exit;

    // Cached location where parking spot is parked in during animation.
    int cachedFloorToParkIn;
    int cachedParkSpotIndexFromFloor;
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override;

private:
    WidgetMeta wm;

    void initAnimation(AnimationMeta animMeta, bool chaos);
    void initSignals();

};

#endif //CS460_PROJECT_1_VEHICLE_H