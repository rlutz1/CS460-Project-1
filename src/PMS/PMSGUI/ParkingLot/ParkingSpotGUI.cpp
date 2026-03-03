//
// Created by Eliud Garcia on 2/24/26.
//

#include "ParkingSpotGUI.h"

#include <QGraphicsScene>
#include <QPainter>


ParkingSpotGUI::ParkingSpotGUI(QGraphicsScene& scene, InitializationPackage& initPackage, SpotId spotId, WidgetMeta widgetMeta) :
    spotId(spotId),
    wm(widgetMeta),
    occupiedColor(Qt::red),
    unavailableColor(Qt::gray)
    {
    // set visual data
    resize(wm.width, wm.height);
    setZValue(wm.zPos);

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

    // because of how parking spots are initialize, this is easier to do here.
    // also, getting grief from
    led = new LedGUI(
        scene,
        {.x = wm.x + (wm.width / 2) - 5, .y = wm.y, .width = 10, .height = 10, .color = availableColor, .zPos = (wm.zPos + 1)}
    );

    ultrasonicSensor = new SensorGUI(
        scene,
        spotId.ultrasonicId,
        {.x = wm.x + (wm.width / 2) - 5, .y = wm.y + (wm.height / 2), .width = 10, .height = 10, .color = Qt::black, .zPos = (widgetMeta.zPos + 1)}
        );
    weightSensor = new SensorGUI(
        scene,
        spotId.weightId,
        {.x = wm.x + (wm.width / 2) - 5, .y = wm.y + wm.height - 10, .width = 10, .height = 10, .color = Qt::black, .zPos = (widgetMeta.zPos + 1)}
        );
    // scene.addItem((QGraphicsWidget*)&led);
    // scene.addItem(this);

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
    // painter->setBackground(Qt::transparent);
    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->setPen(QPen(Qt::black));
    painter->setBrush(QBrush(wm.color));
    // painter->setBrush(QBrush(Qt::transparent));
    painter->drawRect(boundingRect());
}

void ParkingSpotGUI::reset() {
    led->reset(availableColor);
    ultrasonicSensor->reset();
    weightSensor->reset();
}