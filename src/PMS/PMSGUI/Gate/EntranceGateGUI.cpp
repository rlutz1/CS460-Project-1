//
// Created by lutzr on 2/25/2026.
//

#include "EntranceGateGUI.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsOpacityEffect> // only used in this class so far.

EntranceGateGUI::EntranceGateGUI(QGraphicsScene& scene, InitializationPackage& initPackage, GateId id, WidgetMeta widgetMeta) :
    led(
        scene,
        {.x = wm.x, .y = wm.y, .width = 25, .height = 25, .color = Qt::gray, .zPos = (wm.zPos + 1)}
        ),
    initOpenSensor(
        scene,
        id.initOpenId,
        {.x = wm.x - wm.width, .y = wm.y, .width = 25, .height = 25, .color = Qt::black, .zPos = (wm.zPos + 1)}
        ),
    stayOpenSensor(
        scene,
        id.stayOpenId,
        {.x = wm.x + wm.width + (wm.width / 2), .y = wm.y, .width = 25, .height = 25, .color = Qt::black, .zPos = (wm.zPos + 1)}
        ),
    spikes(
        scene,
        {.x = wm.x - wm.width - wm.width, .y = wm.y, .width = 25, .height = 100, .color = Qt::magenta, .zPos = (wm.zPos + 1)}
        ),
    id(id),
    wm(widgetMeta)
{
    resize(wm.width, wm.height);
    setZValue(wm.zPos);
}

void EntranceGateGUI::addSignalReceiver(IInductionSensorDataSink* receiver) {
    pmc = receiver;
}

void EntranceGateGUI::signalGateClose() {
    // PMS said to lower spikes :
    // TODO: verify that opacity is the way to show that spikes are raised/lowered.
    // opacityEffect should last as long as `spikes` is alives
    QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(&spikes);
    opacityEffect->setOpacity(0.5);
    spikes.setGraphicsEffect(opacityEffect);

    // PMS said to close gate:

    // same animation as close but backwards.

    // end with giving PMS a successful Exit message (to be done at the finish of the animation after it has passed 2nd sensor).

}

void EntranceGateGUI::signalGateOpen() {
    // PMS said to raise spikes:
    // TODO: verify that opacity is the way to show that spikes are raised/lowered.
    // opacityEffect should last as long as `spikes` is alives
    QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(&spikes);
    opacityEffect->setOpacity(1);
    spikes.setGraphicsEffect(opacityEffect);
    // PMS said to open gate:

    // start LED flashing for the gate lights
    // slide gate (y position) slowly upwards.



}


// sequence of "probing" events (where we probe our "devices" to see that our PMC backend works correctly)
// FOLLOWS the vehicle animation sequence so far.
void EntranceGateGUI::vehicleOnEntranceGateInductionSensor() {
    pmc->vehicleSensed(id);
}


// sequence of "probing" events (where we probe our "devices" to see that our PMC backend works correctly)
// FOLLOWS the vehicle animation sequence so far.
void EntranceGateGUI::vehiclePassedSecondEntranceGateSensor() {
    pmc->vehicleAbsent(id);
    pmc->successfulEntry();
}

// REQUIRED FOR GRAPHICS ITEM
QRectF EntranceGateGUI::boundingRect() const {
    return QRectF(wm.x, wm.y, // this is BETTER
                  wm.width, wm.height);
}

// REQUIRED FOR GRAPHICS ITEM
void EntranceGateGUI::paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option,
    QWidget *widget) {
    // painter->setBackground(Qt::transparent);
    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->setPen(QPen(Qt::black));
    painter->setBrush(QBrush(wm.color));
    // painter->setBrush(QBrush(Qt::transparent));
    painter->drawRect(boundingRect());
}
