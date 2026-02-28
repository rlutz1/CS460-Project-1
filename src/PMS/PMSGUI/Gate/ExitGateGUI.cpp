//
// Created by lutzr on 2/25/2026.
//

#include "ExitGateGUI.h"
#include <QGraphicsScene>
#include <QPainter>

ExitGateGUI::ExitGateGUI(QGraphicsScene& scene, InitializationPackage& initPackage, GateId id, WidgetMeta widgetMeta) :
led(
    scene,
    {.x = wm.x + (wm.width / 2), .y = wm.y, .width = 25, .height = 25, .color = Qt::gray, .zPos = (wm.zPos + 1)}
    ),
initOpenSensor(
    scene,
    id.initOpenId,
    {.x = wm.x + wm.width + (wm.width / 2), .y = wm.y, .width = 25, .height = 25, .color = Qt::black, .zPos = (wm.zPos + 1)}
    ),
stayOpenSensor(
    scene,
    id.stayOpenId,
    {.x = wm.x - 50, .y = wm.y, .width = 25, .height = 25, .color = Qt::black, .zPos = (wm.zPos + 1)}
    ),
spikes(
    scene,
    {.x = wm.x + wm.width + (wm.width / 2) + wm.width, .y = wm.y, .width = 25, .height = 100, .color = Qt::magenta, .zPos = (wm.zPos + 1)}
    ),
    id(id),
    wm(widgetMeta) {

    resize(wm.width, wm.height);
    setZValue(wm.zPos);

    scene.addItem(this);
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
    painter->setBrush(QBrush(wm.color));
    // painter->setBrush(QBrush(Qt::transparent));
    painter->drawRect(boundingRect());
}


void ExitGateGUI::signalGateClose() {
    // PMS said to lower spikes :
    // TODO: verify that opacity is the way to show that spikes are raised/lowered.
    // opacityEffect should last as long as `spikes` is alives
    QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(&spikes);
    opacityEffect->setOpacity(0.5);
    spikes.setGraphicsEffect(opacityEffect);

    // PMS said to close gate:

    // same animation as open but backwards.

    // end with giving PMS a successful Exit message (to be done at the finsih of the animation after it has passed 2nd sensor)
}

void ExitGateGUI::signalGateOpen() {
    // PMS said to raise spikes:
    // TODO: verify that opacity is the way to show that spikes are raised/lowered.
    // opacityEffect should last as long as `spikes` is alives
    QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(&spikes);
    opacityEffect->setOpacity(1);
    spikes.setGraphicsEffect(opacityEffect);
    // PMS said to open gate:

    // TODO: figure out issue with Signal 11:SIGSEV on my computer for gui debugging) & test car frame signals with this.
    // start LED flashing for the gate lights
    // slide gate (y position) slowly upwards.
}
