//
// Created by Eliud Garcia on 2/24/26.
//

#include "ParkingSpotGUI.h"

#include <QGraphicsScene>
#include <QPainter>


ParkingSpotGUI::ParkingSpotGUI(QGraphicsScene& scene, InitializationPackage& initPackage, SpotId spotId, WidgetMeta widgetMeta) :
    spotId(spotId),
    wm(widgetMeta)
    // led(
    //     scene,
    //     {.x = widgetMeta.x, .y = widgetMeta.y, .width = 25, .height = 25, .color = Qt::green, .zPos = (widgetMeta.zPos + 1)}
    //     ),
    // ultrasonicSensor(
    //     scene,
    //     spotId.ultrasonicId,
    //     {.x = widgetMeta.x + 10, .y = widgetMeta.y, .width = 10, .height = 10, .color = Qt::black, .zPos = (widgetMeta.zPos + 1)}
    //     ),
    // weightSensor(
    //     scene,
    //     spotId.weightId,
    //     {.x = widgetMeta.x + 20, .y = widgetMeta.y, .width = 10, .height = 10, .color = Qt::black, .zPos = (widgetMeta.zPos + 1)}
    //     )
    {
    // set visual data
    resize(wm.width, wm.height);
    setZValue(wm.zPos);

    // because of how parking spots are initialize, this is easier to do here.
    led = new LedGUI(
        scene,
        {.x = wm.x, .y = wm.y, .width = 25, .height = 25, .color = Qt::gray, .zPos = (wm.zPos + 1)}
    );
    scene.addItem(this);

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