//
// Created by Eliud Garcia on 2/24/26.
//

#include "VehicleGUI.h"

#include <QPainter>
#include <QPropertyAnimation>
#include <QGraphicsScene>
#include <QObject>

#include "DemoManager.h"
#include "../run_demo.h"

#define ACTION_PAUSE 1000

VehicleGUI::VehicleGUI(
    QGraphicsScene& scene,
    WidgetMeta widgetMeta,
    AnimationMeta animationMeta,
    DemoManager* demoManager,
    bool chaos,
    int floorToParkIn,
    int parkSpotIndexFromFloor
    ) :
    demoManager(demoManager),
    wm(widgetMeta),
    animationGroup(this),
    initialAnimation(this),
    ongoingAnimation(this),
    offsetPause(this),
    approachEntryGate (this, "pos"),
    passSecondEntrySensor(this, "pos"),
    findSpot(this, "pos"),
    park(this, "pos"),
    unpark(this, "pos"),
    approachExitGate(this, "pos"),
    passSecondExitSensor(this, "pos"),
    exit(this, "pos"),
    cachedFloorToParkIn(floorToParkIn),
    cachedParkSpotIndexFromFloor(parkSpotIndexFromFloor)
{
    resize(wm.width, wm.height);
    setPos(0, animationMeta.yEntryTrack); // careful with this, enure it works every time! can cause issues!
    setZValue(wm.zPos);

    initAnimation(animationMeta, chaos);
    scene.addItem(this);
}

void VehicleGUI::initSignals() {
    // initialize the open entry gate signal connection
    connect(&approachEntryGate, &QPropertyAnimation::finished,
       &demoManager->parkingLot.gate.entranceGate, &EntranceGateGUI::vehicleOnEntranceGateInductionSensor);

    // initialize the vehicle has passed through the entry gate successfully signal
    connect(&passSecondEntrySensor, &QPropertyAnimation::finished,
        &demoManager->parkingLot.gate.entranceGate, &EntranceGateGUI::vehiclePassedSecondEntranceGateSensor);


    // initialize the vehicle parking in a spot ->vehicleParked signal
    connect(&park, &QPropertyAnimation::finished,
        demoManager->parkingLot.parkingFloors[cachedFloorToParkIn]
        ->parkingSpots[cachedParkSpotIndexFromFloor], &ParkingSpotGUI::signalVehicleParkedOnSpot);
    // initialize the vehicle leaving in a spot -> vehicleLeft signal
    connect(&park, &QPropertyAnimation::finished,
        demoManager->parkingLot.parkingFloors[cachedFloorToParkIn]
        ->parkingSpots[cachedParkSpotIndexFromFloor], &ParkingSpotGUI::signalVehicleLeftParkingSpot);

    // initialize the vehicle left a spot vehicleUnparked signal
    // connect(&unpark, &QPropertyAnimation::finished,
    //     );

    // initialize the open exit gate signal connection
    connect(&approachExitGate, &QPropertyAnimation::finished,
        &demoManager->parkingLot.gate.exitGate, &ExitGateGUI::vehicleOnExitGateInductionSensor);

    // initialize the vehicle has passed through the exit gate successfully signal
    connect(&passSecondExitSensor, &QPropertyAnimation::finished,
          &demoManager->parkingLot.gate.exitGate, &ExitGateGUI::vehiclePassedSecondExitGateSensor);
}

void VehicleGUI::initAnimation(AnimationMeta animMeta, bool chaos) {



    offsetPause.setDuration(animMeta.entryDelay); // for controlling start flow

    approachEntryGate.setDuration(animMeta.approachGateTime);
    approachEntryGate.setEasingCurve(animMeta.movementType);
    approachEntryGate.setStartValue(QPoint(0, animMeta.yEntryTrack));
    approachEntryGate.setEndValue(QPoint(animMeta.xFirstEntryGateSensor, animMeta.yEntryTrack));

    passSecondEntrySensor.setDuration(animMeta.throughGateTime);
    passSecondEntrySensor.setEasingCurve(animMeta.movementType);
    passSecondEntrySensor.setEndValue(QPoint(animMeta.xSecondEntryGateSensor, animMeta.yEntryTrack));

    findSpot.setDuration(animMeta.generalMovementTime);
    findSpot.setEasingCurve(animMeta.movementType);
    findSpot.setEndValue(QPoint(animMeta.xSpot, animMeta.yEntryTrack));

    park.setDuration(animMeta.parkTime);
    park.setEasingCurve(animMeta.movementType);
    park.setEndValue(QPoint(animMeta.xSpot, animMeta.ySpot));

    unpark.setDuration(animMeta.parkTime);
    unpark.setEasingCurve(animMeta.movementType);
    unpark.setEndValue(QPoint(animMeta.xSpot, animMeta.yExitTrack));

    approachExitGate.setDuration(animMeta.generalMovementTime);
    approachExitGate.setEasingCurve(animMeta.movementType);
    approachExitGate.setEndValue(QPoint(animMeta.xFirstExitGateSensor, animMeta.yExitTrack));

    passSecondExitSensor.setDuration(animMeta.throughGateTime);
    passSecondExitSensor.setEasingCurve(animMeta.movementType);
    passSecondExitSensor.setEndValue(QPoint(animMeta.xSecondExitGateSensor, animMeta.yExitTrack));

    exit.setDuration(animMeta.generalMovementTime);
    exit.setEasingCurve(animMeta.movementType);
    exit.setEndValue(QPoint(0, animMeta.yExitTrack));

    initSignals(); // initialize the signal connections to these animations

    // group all animations
    initialAnimation.addAnimation(&offsetPause);
    initialAnimation.addAnimation(&approachEntryGate);
    initialAnimation.addPause(ACTION_PAUSE);
    initialAnimation.addAnimation(&passSecondEntrySensor);
    initialAnimation.addPause(ACTION_PAUSE);
    initialAnimation.addAnimation(&findSpot);
    initialAnimation.addPause(ACTION_PAUSE);
    initialAnimation.addAnimation(&park);
    initialAnimation.addPause(animMeta.parkPauseTime);
    initialAnimation.addAnimation(&unpark);
    initialAnimation.addPause(ACTION_PAUSE);
    initialAnimation.addAnimation(&approachExitGate);
    initialAnimation.addPause(ACTION_PAUSE);
    initialAnimation.addAnimation(&passSecondExitSensor);
    initialAnimation.addPause(ACTION_PAUSE);
    initialAnimation.addAnimation(&exit);
    initialAnimation.setLoopCount(1);

    animationGroup.addAnimation(&initialAnimation);

    // if we're running through the vehicle without end
    if (chaos) {
        ongoingAnimation.addAnimation(&approachEntryGate);
        ongoingAnimation.addPause(ACTION_PAUSE);
        ongoingAnimation.addAnimation(&passSecondEntrySensor);
        ongoingAnimation.addPause(ACTION_PAUSE);
        ongoingAnimation.addAnimation(&findSpot);
        ongoingAnimation.addPause(ACTION_PAUSE);
        ongoingAnimation.addAnimation(&park);
        ongoingAnimation.addPause(animMeta.parkPauseTime);
        ongoingAnimation.addAnimation(&unpark);
        ongoingAnimation.addPause(ACTION_PAUSE);
        ongoingAnimation.addAnimation(&approachExitGate);
        ongoingAnimation.addPause(ACTION_PAUSE);
        ongoingAnimation.addAnimation(&passSecondExitSensor);
        ongoingAnimation.addPause(ACTION_PAUSE);
        ongoingAnimation.addAnimation(&exit);

        ongoingAnimation.setLoopCount(-1);
        animationGroup.addAnimation(&ongoingAnimation);
    } // end if

} // end method

// REQUIRED FOR GRAPHICS ITEM
QRectF VehicleGUI::boundingRect() const {
    return QRectF(wm.x, wm.y, // this is BETTER
                  wm.width, wm.height);
}

// REQUIRED FOR GRAPHICS ITEM
void VehicleGUI::paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option,
    QWidget *widget) {
    // painter->setBackground(Qt::transparent);
    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->setPen(QPen(Qt::black));
    painter->setBrush(QBrush(wm.color));
    // painter->setBrush(QBrush(Qt::transparent));
    painter->drawRect(boundingRect());
}
