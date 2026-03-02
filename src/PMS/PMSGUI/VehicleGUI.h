//
// Created by Eliud Garcia on 2/24/26.
//

#ifndef CS460_PROJECT_1_VEHICLE_H
#define CS460_PROJECT_1_VEHICLE_H
#include <QGraphicsWidget>
#include <QSequentialAnimationGroup>
#include <QEasingCurve>
#include <QPropertyAnimation>

#include "DemoManager.h"
#include "GUIStructs/GUIStructs.h"
class DemoManager;

struct AnimationMeta {
    QEasingCurve movementType;
    int approachGateTime;
    int throughGateTime;
    int xFirstEntryGateSensor;
    int xSecondEntryGateSensor;
    int xFirstExitGateSensor;
    int xSecondExitGateSensor;

    int yEntryTrack;
    int yExitTrack;

    int xSpot;
    int ySpot;

    int generalMovementTime;
    int parkPauseTime;
    int parkTime;
    // int gateOpenDelay; // this should be constant
};

class VehicleGUI : QGraphicsWidget {

public:
    QSequentialAnimationGroup* animationGroup;
    DemoManager* demoManager;

    VehicleGUI(QGraphicsScene& scene, WidgetMeta widgetMeta, AnimationMeta animMeta, DemoManager* demoManager);
    // ~VehicleGUI() override;

    QPropertyAnimation* approachEntryGate;
    QPropertyAnimation* passSecondEntrySensor;
    QPropertyAnimation* findSpot;
    QPropertyAnimation* park;
    QPropertyAnimation* unpark;
    QPropertyAnimation* approachExitGate;
    QPropertyAnimation* passSecondExitSensor;
    QPropertyAnimation* exit;
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override;

private:
    WidgetMeta wm;

    void initAnimation(AnimationMeta animMeta);
};




#endif //CS460_PROJECT_1_VEHICLE_H