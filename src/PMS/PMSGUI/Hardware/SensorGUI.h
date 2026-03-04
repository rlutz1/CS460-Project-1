//
// Created by Eliud Garcia on 2/24/26.
//

#ifndef CS460_PROJECT_1_SENSOR_H
#define CS460_PROJECT_1_SENSOR_H
#include <QGraphicsWidget>

#include "../../Definitions/Identifiers.h"
#include "../GUIStructs/GUIStructs.h"

class SensorGUI : public QGraphicsWidget{
    Q_OBJECT;
public:
    SensorGUI(QGraphicsScene& scene, SensorId id, WidgetMeta widgetMeta);

    WidgetMeta wm;
    SensorId sensorId;

    void reset();

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override;

};


#endif //CS460_PROJECT_1_SENSOR_H