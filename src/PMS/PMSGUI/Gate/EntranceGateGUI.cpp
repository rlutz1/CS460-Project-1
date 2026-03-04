#include "EntranceGateGUI.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsOpacityEffect> // only used in this class so far.

EntranceGateGUI::EntranceGateGUI(QGraphicsScene& scene, InitializationPackage& initPackage, GateId id, WidgetMeta widgetMeta) :
    led( new LedGUI(
        scene,
        {.x = wm.x, .y = wm.y, .width = 25, .height = 25, .color = Qt::gray, .zPos = (wm.zPos + 1)}
        )),
    initOpenSensor( new SensorGUI(
        scene,
        id.initOpenId,
        {.x = wm.x - wm.width, .y = wm.y, .width = 25, .height = 25, .color = Qt::black, .zPos = (wm.zPos + 1)}
        )),
    stayOpenSensor( new SensorGUI(
        scene,
        id.stayOpenId,
        {.x = wm.x + wm.width + (wm.width / 2), .y = wm.y, .width = 25, .height = 25, .color = Qt::black, .zPos = (wm.zPos + 1)}
        )),
    spikes( new SpikesGUI(
        scene,
        {.x = wm.x - wm.width - wm.width, .y = wm.y, .width = 25, .height = 100, .color = Qt::magenta, .zPos = (wm.zPos + 1)}
        )),
    id(id),
    wm(widgetMeta),
    currColor(Qt::red),
    openGateIndicator(Qt::green),
    closedGateIndicator(Qt::red),
    openGateLight(Qt::yellow),
    closedGateLight(Qt::gray)
{
    led->setParentItem(this);
    initOpenSensor->setParentItem(this);
    stayOpenSensor->setParentItem(this);
    spikes->setParentItem(this);

    resize(wm.width, wm.height);
    setZValue(wm.zPos);

    connect(initOpenSensor, &SensorGUI::triggerSend, this, &EntranceGateGUI::vehicleOnEntranceGateInductionSensor);
    connect(stayOpenSensor, &SensorGUI::triggerSend, this, &EntranceGateGUI::vehiclePassedSecondEntranceGateSensor);
}

// signal received from pmc to close the gate
void EntranceGateGUI::signalGateClose() {
    // need to close gate
    close();
    // need to lower spikes
    spikes->lower();
    // turn off "flashing" light
    flash(false);
}

// signal received from pmc to open the gate
void EntranceGateGUI::signalGateOpen() {
    // need to open gate
    open();
    // need to raise spikes
    spikes->raise();
    // turn on "flashing" light
    flash(true);
}


// sequence of "probing" events (where we probe our "devices" to see that our PMC backend works correctly)
// FOLLOWS the vehicle animation sequence so far.
void EntranceGateGUI::vehicleOnEntranceGateInductionSensor(bool sensorState, SensorId sensorId) {
    pmc->vehicleSensed(id);
}

// sequence of "probing" events (where we probe our "devices" to see that our PMC backend works correctly)
// FOLLOWS the vehicle animation sequence so far.
void EntranceGateGUI::vehiclePassedSecondEntranceGateSensor(bool sensorState, SensorId sensorId) {
    pmc->vehicleAbsent(id);
    pmc->successfulEntry();
}

// to signify a driver action of closing the gate signal
void EntranceGateGUI::close() {
    currColor = closedGateIndicator;
    update();
}

// to signify the opening of the gate via driver
void EntranceGateGUI::open() {
    currColor = openGateIndicator;
    update();
}

// to signify the flashing of the led on gate open
void EntranceGateGUI::flash(bool flashingOn) {
    if (flashingOn) {
        led->color(openGateLight);
    } else {
        led->color(closedGateLight);
    }
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
    painter->setBrush(QBrush(currColor));
    // painter->setBrush(QBrush(Qt::transparent));
    painter->drawRect(boundingRect());
}

void EntranceGateGUI::reset() {
    close();
    spikes->lower();
    flash(false);
}