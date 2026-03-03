//
// Created by Eliud Garcia on 2/24/26.
//

#include "ParkingFloorGUI.h"
#include <iostream>
#include <QGraphicsScene>
#include <QPainter>
#include <stack>
using std::cout;
using std::stack;





ParkingFloorGUI::ParkingFloorGUI(QGraphicsScene& scene, InitializationPackage& initPackage, FloorId floorId, WidgetMeta widgetMeta) :
    floorId(floorId),
    wm(widgetMeta) {
    // visual data
    setZValue(wm.zPos);
    resize(wm.width, wm.height);

    // init parking lots
    if (floorId.uniqueId == "floor1") {
        initFirstFloor(scene, initPackage);
    } else {
        initGenFloor(scene, initPackage);
    }

    // scene.addItem(this);
}

// REQUIRED FOR GRAPHICS ITEM
QRectF ParkingFloorGUI::boundingRect() const {
    qreal penWidth = 1;
    return QRectF(wm.x, wm.y, // this is BETTER
                  wm.width, wm.height);
}

// REQUIRED FOR GRAPHICS ITEM
void ParkingFloorGUI::paint(QPainter *painter,
                            const QStyleOptionGraphicsItem *option,
                            QWidget *widget) {
    // cout << floorId.uniqueId << " painting" << std::endl;
    // painter->setBackground(Qt::transparent);
    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->setPen(QPen(Qt::black));
    painter->setBrush(QBrush(wm.color));
    painter->drawRect(boundingRect());
}


// first floor initialization ONLY
void ParkingFloorGUI::initFirstFloor(QGraphicsScene& scene, InitializationPackage& initPackage) {
    // the following are for dev readability only, based on a hard design.
    // this is NOT intended for general purpose malleability.
    int spotWidth = 50; int widerSpotWidth = spotWidth * 2; int spotHeight = 100;
    stack<Point> motorcyclePlacements;
    stack<Point> normalPlacements;
    stack<Point> handicapPlacements;
    stack<Point> evPlacements;

    // TOP ROW MOTORCYCLES
    for (int i = 0; i < 2; i++) {
        Point point = {.x = wm.x + (spotWidth * i), .y = wm.y};
        // cout << point.x << " " << point.y << std::endl;
        motorcyclePlacements.push(point);
    }
    // TOP ROW NORMALS
    for (int i = 2; i < 6; i++) {
        Point point = {.x = wm.x + (spotWidth * i), .y = wm.y};
        // cout << point.x << " " << point.y << std::endl;
        normalPlacements.push(point);
    }
    // TOP ROW EV
    for (int i = 6; i < 8; i++) {
        Point point = {.x = wm.x + (spotWidth * i), .y = wm.y};
        evPlacements.push(point);
    }

    // BOTTOM ROW HANDICAP
    for (int i = 0; i < 4; i += 2) {
        Point point = {.x = wm.x + (spotWidth * i), .y = wm.y + 500};
        handicapPlacements.push(point);
    }
    // BOTTOM ROW NORMALS
    for (int i = 4; i < 8; i++) {
        Point point = {.x = wm.x + (spotWidth * i), .y = wm.y + 500};
        normalPlacements.push(point);
    }


    // generate the new spots
    for (SpotId id : initPackage.spotIds) {
        if (id.floorId.uniqueId == "floor1") { // for general floors
            WidgetMeta widgetMeta;

            if (id.type == MOTORCYCLE) {
                Point pt = motorcyclePlacements.top();
                motorcyclePlacements.pop();
                widgetMeta = {.x = pt.x, .y = pt.y, .width = spotWidth, .height = spotHeight, .color = Qt::gray, .zPos = wm.zPos + 1};
            }

            if (id.type == NORMAL) {
                Point pt = normalPlacements.top();
                normalPlacements.pop();
                widgetMeta = {.x = pt.x, .y = pt.y, .width = spotWidth, .height = spotHeight, .color = Qt::gray, .zPos = wm.zPos + 1};
            }

            if (id.type == EV) {
                Point pt = evPlacements.top();
                evPlacements.pop();
                widgetMeta = {.x = pt.x, .y = pt.y, .width = spotWidth, .height = spotHeight, .color = Qt::gray, .zPos = wm.zPos + 1};
            }

            if (id.type == HANDICAP) {
                Point pt = handicapPlacements.top();
                handicapPlacements.pop();
                widgetMeta = {.x = pt.x, .y = pt.y, .width = widerSpotWidth, .height = spotHeight, .color = Qt::gray, .zPos = wm.zPos + 1};
            }
            ParkingSpotGUI* parkingSpot = new ParkingSpotGUI(
                scene,
                initPackage,
                id,
                widgetMeta
            );
            parkingSpots.push_back(parkingSpot);
        }
    }
}


// general floor initialization, but for demo: floor 2
void ParkingFloorGUI::initGenFloor(QGraphicsScene& scene, InitializationPackage& initPackage) {
    // the following are for dev readability only, based on a hard design.
    // this is NOT intended for general purpose malleability.
    int spotWidth = 50; int widerSpotWidth = spotWidth * 2; int spotHeight = 100;
    stack<Point> normalPlacements;
    stack<Point> handicapPlacements;
    stack<Point> evPlacements;

    // TOP ROW NORMALS
    for (int i = 0; i < 12; i++) {
        Point point = {.x = wm.x + (spotWidth * i), .y = wm.y};
        // cout << point.x << " " << point.y << std::endl;
        normalPlacements.push(point);
    }
    // TOP ROW EV
    for (int i = 12; i < 14; i++) {
        Point point = {.x = wm.x + (spotWidth * i), .y = wm.y};
        evPlacements.push(point);
    }

    // BOTTOM ROW NORMALS
    for (int i = 0; i < 8; i++) {
        Point point = {.x = wm.x + (spotWidth * i), .y = wm.y + 500};
        normalPlacements.push(point);
    }
    // BOTTOM ROW HANDICAP
    for (int i = 10; i < 14; i += 2) {
        Point point = {.x = wm.x + (spotWidth * i), .y = wm.y + 500};
        handicapPlacements.push(point);
    }

    // generate the new spots
    for (SpotId id : initPackage.spotIds) {
        if (id.floorId.uniqueId != "floor1") { // for general floors
            WidgetMeta widgetMeta;

            if (id.type == NORMAL) {
                Point pt = normalPlacements.top();
                normalPlacements.pop();
                widgetMeta = {.x = pt.x, .y = pt.y, .width = spotWidth, .height = spotHeight, .color = Qt::gray, .zPos = wm.zPos + 1};
            }
            if (id.type == EV) {
                Point pt = evPlacements.top();
                evPlacements.pop();
                widgetMeta = {.x = pt.x, .y = pt.y, .width = spotWidth, .height = spotHeight, .color = Qt::gray, .zPos = wm.zPos + 1};
            }

            if (id.type == HANDICAP) {
                Point pt = handicapPlacements.top();
                handicapPlacements.pop();
                widgetMeta = {.x = pt.x, .y = pt.y, .width = widerSpotWidth, .height = spotHeight, .color = Qt::gray, .zPos = wm.zPos + 1};
            }

            ParkingSpotGUI* parkingSpot = new ParkingSpotGUI(
                scene,
                initPackage,
                id,
                widgetMeta
            );
            parkingSpots.push_back(parkingSpot);
        }
    }
}

void ParkingFloorGUI::reset() {
    for (ParkingSpotGUI* parkingSpot : parkingSpots) {
        parkingSpot->reset();
    }
}