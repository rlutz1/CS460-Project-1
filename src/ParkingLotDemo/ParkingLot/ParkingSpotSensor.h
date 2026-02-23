//
// Created by lutzr on 2/23/2026.
//

#ifndef CS460_PROJECT_1_PARKINGSPOTSENSOR_H
#define CS460_PROJECT_1_PARKINGSPOTSENSOR_H
#include <qwidget.h>
// class QWidget;
#include <QGraphicsItem>
#include <string>


class ParkingSpotSensor : public QGraphicsItem {
public:
    std::string sensorId;
    bool enabled;
    ParkingSpotSensor(std::string id, QGraphicsItem *parent);

    void enable(); // from sad
    void disable(); // from sad

protected:
    // QSize sizeHint() const override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override;
};


#endif //CS460_PROJECT_1_PARKINGSPOTSENSOR_H