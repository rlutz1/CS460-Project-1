//
// Created by lutzr on 2/23/2026.
//

#ifndef CS460_PROJECT_1_PARKINGSPOT_H
#define CS460_PROJECT_1_PARKINGSPOT_H
#include <qwidget.h>
#include <QGraphicsItem>
#include <QGraphicsWidget>

#include "ParkingLot.h"

class ParkingSpotSensor;

class ParkingSpot : public QGraphicsWidget {// TODO REMOVE QOBJECT! TESTING ONLY!

public:
    ParkingSpot();
    // ParkingSpot(std::string spotId, QWidget *parent);
    ParkingSpot(std::string spotId, QPoint pos);
    ParkingSpotSensor* ultrasonic_sensor;
    ParkingSpotSensor* weight_sensor;
    bool available; // TODO MAYBE
    std::string spotId;
    QPoint pos;

protected:
    // QSize sizeHint() const override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override;
};


#endif //CS460_PROJECT_1_PARKINGSPOT_H