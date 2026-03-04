//
// Created by Eliud Garcia on 2/24/26.
//

#ifndef CS460_PROJECT_1_PARKINGSPOT_H
#define CS460_PROJECT_1_PARKINGSPOT_H
#include <QGraphicsWidget>
#include "../GUIStructs/GUIStructs.h"
#include "../../Initialization.h"
#include "../Hardware/LedGUI.h"
#include "../Hardware/SensorGUI.h"

#include "../../PMC/PMCInterfaces//IParkingSpotHardwareSink.h"

class IParkingSpotSensorDataSink;

class ParkingSpotGUI : public QGraphicsWidget, public IParkingSpotHardwareSink {
    Q_OBJECT;

public:
    ParkingSpotGUI(QGraphicsScene& scene, SpotId spotId, WidgetMeta widgetMeta);

    QColor currColor;
    QColor availableColor;
    QColor occupiedColor;
    QColor unavailableColor;
    LedGUI* led;
    SensorGUI* ultrasonicSensor;
    SensorGUI* weightSensor;
    SpotId spotId;
    WidgetMeta wm;

    void reset();

    // IParkingSpotHardwareSink
    void markSpotAvailable() override;
    void markSpotUnavailable() override;

    std::shared_ptr<IParkingSpotSensorDataSink> pmc;
public slots:
    void signalVehicleParkedOnSpot();
    void signalVehicleLeftParkingSpot();

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override;
};


#endif //CS460_PROJECT_1_PARKINGSPOT_H