//
// Created by Eliud Garcia on 2/24/26.
//

#include "VehicleGUI.h"

#include <QPainter>
#include <QPropertyAnimation>
#include <QGraphicsScene>

VehicleGUI::VehicleGUI(QGraphicsScene& scene, WidgetMeta widgetMeta, AnimationMeta animationMeta) :
    wm(widgetMeta) {
    initAnimation(animationMeta);
    scene.addItem(this);
}

void VehicleGUI::initAnimation(AnimationMeta animMeta) {
    QSequentialAnimationGroup* group = new QSequentialAnimationGroup;

    QPropertyAnimation* approachEntryGate = new QPropertyAnimation(this, "pos");
    approachEntryGate->setDuration(animMeta.approachGateTime);
    approachEntryGate-> setEasingCurve(animMeta.movementType);
    approachEntryGate->setStartValue(QPoint(0, animMeta.yEntryTrack));
    approachEntryGate->setEndValue(QPoint(animMeta.xFirstEntryGateSensor, animMeta.yEntryTrack));
    // enter_anim->start();

    QPropertyAnimation* passSecondEntrySensor = new QPropertyAnimation(this, "pos");
    passSecondEntrySensor->setDuration(animMeta.throughGateTime);
    passSecondEntrySensor-> setEasingCurve(animMeta.movementType);
    passSecondEntrySensor->setStartValue(QPoint(animMeta.xFirstEntryGateSensor, animMeta.yEntryTrack));
    passSecondEntrySensor->setEndValue(QPoint(animMeta.xSecondEntryGateSensor + 50, animMeta.yEntryTrack));
    // connect(park_anim, &QPropertyAnimation::finished, parent, &ParkingLot::trigger_vehicle_parked(this->vehicleId, true));
    // connect(park_anim, &QPropertyAnimation::finished, parent, [this]() { parent->trigger_vehicle_parked(this->destId, true); });

    QPropertyAnimation* findSpot = new QPropertyAnimation(this, "pos");
    findSpot->setDuration(animMeta.generalMovementTime);
    findSpot-> setEasingCurve(animMeta.movementType);
    findSpot->setStartValue(QPoint(animMeta.xSecondEntryGateSensor + 50, animMeta.yEntryTrack));
    findSpot->setEndValue(QPoint(animMeta.xSpot, animMeta.yEntryTrack));

    QPropertyAnimation* park = new QPropertyAnimation(this, "pos");
    park->setDuration(animMeta.parkTime);
    park-> setEasingCurve(animMeta.movementType);
    park->setStartValue(QPoint(animMeta.xSpot, animMeta.yEntryTrack));
    park->setEndValue(QPoint(animMeta.xSpot, animMeta.ySpot));

    QPropertyAnimation* unpark = new QPropertyAnimation(this, "pos");
    unpark->setDuration(animMeta.parkTime);
    unpark-> setEasingCurve(animMeta.movementType);
    unpark->setStartValue(QPoint(animMeta.xSpot, animMeta.ySpot));
    unpark->setEndValue(QPoint(animMeta.xSpot, animMeta.yEntryTrack));

    QPropertyAnimation* moveToExitTrack = new QPropertyAnimation(this, "pos");
    moveToExitTrack->setDuration(animMeta.generalMovementTime);
    moveToExitTrack-> setEasingCurve(animMeta.movementType);
    moveToExitTrack->setStartValue(QPoint(animMeta.xSpot, animMeta.yEntryTrack));
    moveToExitTrack->setEndValue(QPoint(animMeta.xSpot, animMeta.yExitTrack));

    QPropertyAnimation* approachExitGate = new QPropertyAnimation(this, "pos");
    approachExitGate->setDuration(animMeta.generalMovementTime);
    approachExitGate-> setEasingCurve(animMeta.movementType);
    approachExitGate->setStartValue(QPoint(animMeta.xSpot, animMeta.yExitTrack));
    approachExitGate->setEndValue(QPoint(animMeta.xFirstExitGateSensor, animMeta.yExitTrack));

    QPropertyAnimation* passSecondExitSensor = new QPropertyAnimation(this, "pos");
    passSecondExitSensor->setDuration(animMeta.throughGateTime);
    passSecondExitSensor-> setEasingCurve(animMeta.movementType);
    passSecondExitSensor->setStartValue(QPoint(animMeta.xFirstExitGateSensor, animMeta.yExitTrack));
    passSecondExitSensor->setEndValue(QPoint(animMeta.xSecondExitGateSensor + 50, animMeta.yExitTrack));

    QPropertyAnimation* exit = new QPropertyAnimation(this, "pos");
    exit->setDuration(animMeta.generalMovementTime);
    exit-> setEasingCurve(animMeta.movementType);
    exit->setStartValue(QPoint(animMeta.xSecondExitGateSensor + 50, animMeta.yExitTrack));
    exit->setEndValue(QPoint(0, animMeta.yExitTrack));

    // group all animations
    group->addAnimation(approachEntryGate);
    group->addPause(2000);
    group->addAnimation(passSecondEntrySensor);
    group->addPause(2000);
    group->addAnimation(findSpot);
    group->addAnimation(park);
    group->addPause(animMeta.parkPauseTime);
    group->addAnimation(unpark);
    group->addAnimation(moveToExitTrack);
    group->addAnimation(approachExitGate);
    group->addPause(2000);
    group->addAnimation(passSecondExitSensor);
    group->addPause(2000);
    group->addAnimation(exit);

    animationGroup = group;
}

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
