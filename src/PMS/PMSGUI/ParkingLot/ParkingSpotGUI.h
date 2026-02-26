//
// Created by Eliud Garcia on 2/24/26.
//

#ifndef CS460_PROJECT_1_PARKINGSPOT_H
#define CS460_PROJECT_1_PARKINGSPOT_H
#include <QGraphicsWidget>

class ParkingSpotGUI : QGraphicsWidget {
    Q_OBJECT;
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override;
};


#endif //CS460_PROJECT_1_PARKINGSPOT_H