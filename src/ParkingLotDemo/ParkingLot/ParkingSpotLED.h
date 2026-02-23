//
// Created by lutzr on 2/23/2026.
//

#ifndef CS460_PROJECT_1_PARKINGSPOTLED_H
#define CS460_PROJECT_1_PARKINGSPOTLED_H
#include <QGraphicsItem>
#include <qwidget.h>


class ParkingSpotLED : public QGraphicsItem {


protected:
    // QSize sizeHint() const override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override;
};


#endif //CS460_PROJECT_1_PARKINGSPOTLED_H