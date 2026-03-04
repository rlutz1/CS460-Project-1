//
// Created by lutzr on 2/25/2026.
//

#include "ExitGateGUI.h"
#include <QGraphicsScene>
#include <QPainter>

ExitGateGUI::ExitGateGUI(QGraphicsScene& scene, InitializationPackage& initPackage, GateId id, WidgetMeta widgetMeta) :
    led( new LedGUI(
        scene,
        {.x = wm.x + (wm.width / 2), .y = wm.y, .width = 25, .height = 25, .color = Qt::gray, .zPos = (wm.zPos + 1)}
        )),
    initOpenSensor( new SensorGUI(
        scene,
        id.initOpenId,
        {.x = wm.x + wm.width + (wm.width / 2), .y = wm.y, .width = 25, .height = 25, .color = Qt::black, .zPos = (wm.zPos + 1)}
        )),
    stayOpenSensor( new SensorGUI(
        scene,
        id.stayOpenId,
        {.x = wm.x - 50, .y = wm.y, .width = 25, .height = 25, .color = Qt::black, .zPos = (wm.zPos + 1)}
        )),
    spikes( new SpikesGUI(
        scene,
        {.x = wm.x + wm.width + (wm.width / 2) + wm.width, .y = wm.y, .width = 25, .height = 100, .color = Qt::magenta, .zPos = (wm.zPos + 1)}
        )),
        id(id),
        wm(widgetMeta),
    currColor(Qt::red),
    openGateIndicator(Qt::green),
    closedGateIndicator(Qt::red)
{
    led->setParentItem(this);
    initOpenSensor->setParentItem(this);
    stayOpenSensor->setParentItem(this);
    spikes->setParentItem(this);

    resize(wm.width, wm.height);
    setZValue(wm.zPos);
}

void ExitGateGUI::addSignalReceiver(IInductionSensorDataSink* pmc) {
    // this->pmc = pmc;
}

void ExitGateGUI::signalGateClose() {
    // PMS said to lower spikes :
    // TODO: verify that opacity is the way to show that spikes are raised/lowered.
    // opacityEffect should last as long as `spikes` is alives
    QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(spikes);
    opacityEffect->setOpacity(0.5);
    spikes->setGraphicsEffect(opacityEffect);

    // PMS said to close gate:
    // same animation as open but backwards.
    currColor = closedGateIndicator;
    update();
    // end with giving PMS a successful Exit message (to be done at the finsih of the animation after it has passed 2nd sensor)
}

void ExitGateGUI::signalGateOpen() {
    // PMS said to raise spikes:
    // TODO: verify that opacity is the way to show that spikes are raised/lowered.
    // opacityEffect should last as long as `spikes` is alives
    QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(spikes);
    opacityEffect->setOpacity(1);
    spikes->setGraphicsEffect(opacityEffect);
    // PMS said to open gate:
    currColor = openGateIndicator;
    update();
    // TODO: figure out issue with Signal 11:SIGSEV on my computer for gui debugging) & test car frame signals with this.
    // start LED flashing for the gate lights
    // slide gate (y position) slowly upwards.
}

// sequence of "probing" events (where we probe our "devices" to see that our PMC backend works correctly)
// FOLLOWS the vehicle animation sequence so far.
void ExitGateGUI::vehicleOnExitGateInductionSensor() {
    pmc->vehicleSensed(id);
}

// sequence of "probing" events (where we probe our "devices" to see that our PMC backend works correctly)
// FOLLOWS the vehicle animation sequence so far.
void ExitGateGUI::vehiclePassedSecondExitGateSensor() {
    // should do nothing (here for consistency)
    pmc->vehicleAbsent(id);
    pmc->successfulExit();
}

// REQUIRED FOR GRAPHICS ITEM
QRectF ExitGateGUI::boundingRect() const {
    return QRectF(wm.x, wm.y, // this is BETTER
                  wm.width, wm.height);
}

// REQUIRED FOR GRAPHICS ITEM
void ExitGateGUI::paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option,
    QWidget *widget) {
    // painter->setBackground(Qt::transparent);
    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->setPen(QPen(Qt::black));
    painter->setBrush(QBrush(currColor));
    // painter->setBrush(QBrush(Qt::transparent));
    painter->drawRect(boundingRect());
}

void ExitGateGUI::reset() {
    currColor = closedGateIndicator;
    update();
    spikes->reset();
}