//
// Created by Eliud Garcia on 2/24/26.
//

#include "ParkingSpotGUI.h"

#include <QGraphicsScene>
#include <QPainter>


ParkingSpotGUI::ParkingSpotGUI(QGraphicsScene& scene, SpotId spotId, WidgetMeta widgetMeta) :
    spotId(spotId),
    wm(widgetMeta),
    led (new LedGUI(
        scene,
        {.x = widgetMeta.x + (widgetMeta.width / 2) - 5, .y = widgetMeta.y, .width = 10, .height = 10, .color = availableColor, .zPos = (widgetMeta.zPos + 1)}
    )),
    ultrasonicSensor( new SensorGUI(
       scene,
       spotId.ultrasonicId,
       {.x = widgetMeta.x + (widgetMeta.width / 2) - 5, .y = widgetMeta.y + (widgetMeta.height / 2), .width = 10, .height = 10, .color = Qt::black, .zPos = (widgetMeta.zPos + 1)}
    )),
    weightSensor ( new SensorGUI(
        scene,
        spotId.weightId,
        {.x = widgetMeta.x + (widgetMeta.width / 2) - 5, .y = widgetMeta.y + widgetMeta.height - 10, .width = 10, .height = 10, .color = Qt::black, .zPos = (widgetMeta.zPos + 1)}
    )),
    occupiedColor(Qt::red),
    unavailableColor(Qt::gray)
    {
    // set visual data
    resize(wm.width, wm.height);
    setZValue(wm.zPos);

    led->setParentItem(this);
    ultrasonicSensor->setParentItem(this);
    weightSensor->setParentItem(this);

    // TODO move to function initAvailableColor()
    switch (spotId.type) {
        case EV:
            availableColor = Qt::yellow;
            break;
        case HANDICAP:
            availableColor = Qt::blue;
            break;
        case MOTORCYCLE:
            availableColor = Qt::white;
            break;
        case NORMAL:
        default:
            availableColor = Qt::green;
    }
    led->currColor = availableColor;
}

// REQUIRED FOR GRAPHICS ITEM
QRectF ParkingSpotGUI::boundingRect() const {
    return QRectF(wm.x, wm.y, // this is BETTER
                  wm.width, wm.height);
}

// REQUIRED FOR GRAPHICS ITEM
void ParkingSpotGUI::paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option,
    QWidget *widget) {
    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->setPen(QPen(Qt::black));
    painter->setBrush(QBrush(wm.color));
    painter->drawRect(boundingRect());
}

void ParkingSpotGUI::reset() {
    led->reset(availableColor);
    ultrasonicSensor->reset();
    weightSensor->reset();
}