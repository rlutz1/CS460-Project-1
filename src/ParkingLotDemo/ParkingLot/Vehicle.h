//
// Created by lutzr on 2/23/2026.
//

#ifndef CS460_PROJECT_1_VEHICLE_H
#define CS460_PROJECT_1_VEHICLE_H
#include <qwidget.h>
#include <QGraphicsWidget>
#include <QPauseAnimation>
#include <QSequentialAnimationGroup>

#include "ParkingLot.h"


class Vehicle : public QGraphicsWidget {
public:
    std::string vehicleId;
    std::string destId;
    Vehicle(std::string vehicleId, ParkingLot* parent, std::string destId);
    QSequentialAnimationGroup* gen_animation_group(float x_dest, float y_dest);

protected:
    // QSize sizeHint() const override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override;

private:
    ParkingLot* parent;

};

// class CustomPause : public QPauseAnimation {
// public:
//     CustomPause(int msecs, QObject *parent);
//
//     signals:
//         void test();
//
// protected:
//     void updateCurrentTime(int currentTime) override;
// };


#endif //CS460_PROJECT_1_VEHICLE_H