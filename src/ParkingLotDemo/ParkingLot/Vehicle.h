//
// Created by lutzr on 2/23/2026.
//

#ifndef CS460_PROJECT_1_VEHICLE_H
#define CS460_PROJECT_1_VEHICLE_H
#include <qwidget.h>
#include <QGraphicsWidget>
#include <QPauseAnimation>
#include <QSequentialAnimationGroup>


class Vehicle : public QGraphicsWidget {
public:
    std::string vehicleId;
    Vehicle(std::string vehicleId);
    QSequentialAnimationGroup* gen_animation_group(float x_dest, float y_dest);
public slots:
    void simple();
protected:
    // QSize sizeHint() const override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override;

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