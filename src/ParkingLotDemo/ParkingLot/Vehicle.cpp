//
// Created by lutzr on 2/23/2026.
//

#include "Vehicle.h"

#include <QPainter>
#include <QPropertyAnimation>

Vehicle::Vehicle(std::string vehicleId) {
    this -> vehicleId = vehicleId;
}

QSequentialAnimationGroup* Vehicle::gen_animation_group(float x_dest, float y_dest) {
    QSequentialAnimationGroup* group = new QSequentialAnimationGroup;

    QPropertyAnimation* enter_anim = new QPropertyAnimation(this, "pos");
    enter_anim->setDuration(1000);
    enter_anim->setStartValue(QPoint(-200, 0));
    enter_anim->setEndValue(QPoint(x_dest, 0));
    enter_anim->start();
    return group;
}

// REQUIRED FOR GRAPHICS ITEM
QRectF Vehicle::boundingRect() const {
    qreal penWidth = 1;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2,
                  20 + penWidth, 20 + penWidth);
}

// REQUIRED FOR GRAPHICS ITEM
void Vehicle::paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option,
    QWidget *widget) {
    painter->setPen(QPen(Qt::black));
    painter->setBrush(QBrush(Qt::black));
    painter->drawEllipse(QRectF(20, 45, 10, 10));
}
