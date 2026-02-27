//
// Created by Eliud Garcia on 2/24/26.
//

#ifndef CS460_PROJECT_1_VEHICLE_H
#define CS460_PROJECT_1_VEHICLE_H
#include <QGraphicsWidget>
#include <QSequentialAnimationGroup>
#include <QEasingCurve>
#include "GUIStructs/GUIStructs.h"

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

    VehicleGUI(QGraphicsScene& scene, WidgetMeta widgetMeta, AnimationMeta animMeta);
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override;

private:
    WidgetMeta wm;

    void initAnimation(AnimationMeta animMeta);
};




#endif //CS460_PROJECT_1_VEHICLE_H