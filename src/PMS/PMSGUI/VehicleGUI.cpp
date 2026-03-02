//
// Created by Eliud Garcia on 2/24/26.
//

#include "VehicleGUI.h"

#include <QPainter>
#include <QPropertyAnimation>
#include <QGraphicsScene>
#include <QObject>

#include "DemoManager.h"

#define ACTION_PAUSE 1000

VehicleGUI::VehicleGUI(QGraphicsScene& scene, WidgetMeta widgetMeta, AnimationMeta animationMeta, DemoManager* demoManager) :
    demoManager(demoManager),
    wm(widgetMeta)
{
    resize(wm.width, wm.height);
    setZValue(wm.zPos);

    initAnimation(animationMeta);
    scene.addItem(this);
}

// VehicleGUI::~VehicleGUI() {
//     animationGroup->stop();
//     animationGroup->clear();
//     // animationGroup->deleteLater();
// }

void VehicleGUI::initAnimation(AnimationMeta animMeta) {
    QSequentialAnimationGroup* group = new QSequentialAnimationGroup;

    approachEntryGate = new QPropertyAnimation(this, "pos");
    approachEntryGate->setDuration(animMeta.approachGateTime);
    approachEntryGate-> setEasingCurve(animMeta.movementType);
    approachEntryGate->setStartValue(QPoint(0, animMeta.yEntryTrack));
    approachEntryGate->setEndValue(QPoint(animMeta.xFirstEntryGateSensor, animMeta.yEntryTrack));
    // QObject::connect(approachEntryGate, &QPropertyAnimation::finished, demoManager, &DemoManager::test);

    passSecondEntrySensor = new QPropertyAnimation(this, "pos");
    passSecondEntrySensor->setDuration(animMeta.throughGateTime);
    passSecondEntrySensor-> setEasingCurve(animMeta.movementType);
    passSecondEntrySensor->setStartValue(QPoint(animMeta.xFirstEntryGateSensor, animMeta.yEntryTrack));
    passSecondEntrySensor->setEndValue(QPoint(animMeta.xSecondEntryGateSensor, animMeta.yEntryTrack));
    // connect(park_anim, &QPropertyAnimation::finished, parent, &ParkingLot::trigger_vehicle_parked(this->vehicleId, true));
    // connect(park_anim, &QPropertyAnimation::finished, parent, [this]() { parent->trigger_vehicle_parked(this->destId, true); });

    findSpot = new QPropertyAnimation(this, "pos");
    findSpot->setDuration(animMeta.generalMovementTime);
    findSpot-> setEasingCurve(animMeta.movementType);
    findSpot->setStartValue(QPoint(animMeta.xSecondEntryGateSensor, animMeta.yEntryTrack));
    findSpot->setEndValue(QPoint(animMeta.xSpot, animMeta.yEntryTrack));

    park = new QPropertyAnimation(this, "pos");
    park->setDuration(animMeta.parkTime);
    park-> setEasingCurve(animMeta.movementType);
    park->setStartValue(QPoint(animMeta.xSpot, animMeta.yEntryTrack));
    park->setEndValue(QPoint(animMeta.xSpot, animMeta.ySpot));

    unpark = new QPropertyAnimation(this, "pos");
    unpark->setDuration(animMeta.parkTime);
    unpark-> setEasingCurve(animMeta.movementType);
    unpark->setStartValue(QPoint(animMeta.xSpot, animMeta.ySpot));
    unpark->setEndValue(QPoint(animMeta.xSpot, animMeta.yExitTrack));

    approachExitGate = new QPropertyAnimation(this, "pos");
    approachExitGate->setDuration(animMeta.generalMovementTime);
    approachExitGate-> setEasingCurve(animMeta.movementType);
    approachExitGate->setStartValue(QPoint(animMeta.xSpot, animMeta.yExitTrack));
    approachExitGate->setEndValue(QPoint(animMeta.xFirstExitGateSensor, animMeta.yExitTrack));

    passSecondExitSensor = new QPropertyAnimation(this, "pos");
    passSecondExitSensor->setDuration(animMeta.throughGateTime);
    passSecondExitSensor-> setEasingCurve(animMeta.movementType);
    passSecondExitSensor->setStartValue(QPoint(animMeta.xFirstExitGateSensor, animMeta.yExitTrack));
    passSecondExitSensor->setEndValue(QPoint(animMeta.xSecondExitGateSensor, animMeta.yExitTrack));

    exit = new QPropertyAnimation(this, "pos");
    exit->setDuration(animMeta.generalMovementTime);
    exit-> setEasingCurve(animMeta.movementType);
    exit->setStartValue(QPoint(animMeta.xSecondExitGateSensor, animMeta.yExitTrack));
    exit->setEndValue(QPoint(0, animMeta.yExitTrack));

    // group all animations
    group->addAnimation(approachEntryGate);
    group->addPause(ACTION_PAUSE);
    group->addAnimation(passSecondEntrySensor);
    group->addPause(ACTION_PAUSE);
    group->addAnimation(findSpot);
    group->addAnimation(park);
    group->addPause(animMeta.parkPauseTime);
    group->addAnimation(unpark);
    group->addPause(ACTION_PAUSE);
    group->addAnimation(approachExitGate);
    group->addPause(ACTION_PAUSE);
    group->addAnimation(passSecondExitSensor);
    group->addPause(ACTION_PAUSE);
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
