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
#include <QPauseAnimation>
class DemoManager;

struct AnimationMeta {
    int entryDelay;

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

class VehicleGUI : public QGraphicsWidget {

public:
    VehicleGUI(
        QGraphicsScene& scene,
        WidgetMeta widgetMeta,
        AnimationMeta animMeta,
        DemoManager* demoManager,
        bool chaos
        );
    // ~VehicleGUI() override;
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
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override;

private:
    WidgetMeta wm;

    void initAnimation(AnimationMeta animMeta, bool chaos);
    void initSignals();
    void removePause(int x, int y);
};




#endif //CS460_PROJECT_1_VEHICLE_H