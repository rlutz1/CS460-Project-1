//
// Created by lutzr on 2/23/2026.
//

#include "Vehicle.h"
// #include "ParkingLot.h"
#include <iostream>
#include <QPainter>
#include <QPropertyAnimation>


// CustomPause::CustomPause(int msecs, QObject *parent) : QPauseAnimation(msecs, parent) {}
//     // CustomPause::test() {}
//
// void CustomPause::updateCurrentTime(int currentTime) {
//     // Custom logic during the pause
//     emit test();
//     QPauseAnimation::updateCurrentTime(currentTime);
// }




Vehicle::Vehicle(std::string vehicleId, ParkingLot* parent, std::string destId) {
    // setPos(0, 0);
    this -> vehicleId = vehicleId;
    this -> destId = destId;
    this -> parent = parent;
    setZValue(5);
    // setAttribute(Qt::WA_TranslucentBackground);
    setAutoFillBackground(false);

}

QSequentialAnimationGroup* Vehicle::gen_animation_group(float x_dest, float y_dest, int delay) {
    QSequentialAnimationGroup* group = new QSequentialAnimationGroup;

    QPropertyAnimation* enter_anim = new QPropertyAnimation(this, "pos");
    enter_anim->setDuration(delay);
    enter_anim-> setEasingCurve(QEasingCurve::InCubic);
    enter_anim->setStartValue(QPoint(-50, -50));
    enter_anim->setEndValue(QPoint(x_dest, -50));
    // enter_anim->start();

    QPropertyAnimation* park_anim = new QPropertyAnimation(this, "pos");
    park_anim->setDuration(delay);
    park_anim-> setEasingCurve(QEasingCurve::InCubic);
    park_anim->setStartValue(QPoint(x_dest, -50));
    park_anim->setEndValue(QPoint(x_dest, y_dest));
    // connect(park_anim, &QPropertyAnimation::finished, parent, &ParkingLot::trigger_vehicle_parked(this->vehicleId, true));
    connect(park_anim, &QPropertyAnimation::finished, parent, [this]() { parent->trigger_vehicle_parked(this->destId, true); });
    // enter_anim->start();

    // CustomPause pause(1000, this);
    // QObject::connect(&pause, &CustomPause::test, this, &Vehicle::simple);

    QPropertyAnimation* unpark_anim = new QPropertyAnimation(this, "pos");
    unpark_anim->setDuration(delay);
    unpark_anim-> setEasingCurve(QEasingCurve::InCubic);
    unpark_anim->setStartValue(QPoint(x_dest, y_dest));
    unpark_anim->setEndValue(QPoint(x_dest, -50));
    connect(unpark_anim, &QPropertyAnimation::finished, parent, [this]() { parent->trigger_vehicle_left(this->destId, true); });

    QPropertyAnimation* exit_anim = new QPropertyAnimation(this, "pos");
    exit_anim->setDuration(delay);
    exit_anim-> setEasingCurve(QEasingCurve::InCubic);
    exit_anim->setStartValue(QPoint(x_dest, -50));
    exit_anim->setEndValue(QPoint(-50, -50));
    // std::cout<<"vehicleId: "<<vehicleId<<std::endl;
    group->addAnimation(enter_anim);
    group->addAnimation(park_anim);
    group->addPause(delay);
    group->addAnimation(unpark_anim);
    group->addAnimation(exit_anim);
    // std::cout<<"vehicleId: "<<vehicleId<<std::endl;
    return group;
}

// REQUIRED FOR GRAPHICS ITEM
QRectF Vehicle::boundingRect() const {
    qreal penWidth = 1;
    return QRectF(0, 0, // this is BETTER
                  14, 14);
}



// REQUIRED FOR GRAPHICS ITEM
void Vehicle::paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option,
    QWidget *widget) {
    painter->setBackground(Qt::transparent);
    // painter->setRenderHint(QPainter::Antialiasing);
    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->setPen(QPen(Qt::black));
    painter->setBrush(QBrush(Qt::blue));
    painter->drawRect(QRectF(0, 0, 15, 15));
}


