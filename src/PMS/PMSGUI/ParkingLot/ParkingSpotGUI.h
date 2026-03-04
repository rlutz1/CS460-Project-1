//
// Created by Eliud Garcia on 2/24/26.
//

#ifndef CS460_PROJECT_1_PARKINGSPOT_H
#define CS460_PROJECT_1_PARKINGSPOT_H
#include <QGraphicsWidget>
#include <QPointer>

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

    QColor availableColor;
    QColor occupiedColor;
    QColor unavailableColor;
    QPointer<LedGUI> led;
    QPointer<SensorGUI> ultrasonicSensor;
    QPointer<SensorGUI> weightSensor;
    SpotId spotId;
    WidgetMeta wm;

    void reset();

    // IParkingSpotHardwareSink
    void markSpotAvailable() override;
    void markSpotUnavailable() override;
    void markSpotOccupied() override;

    std::shared_ptr<IParkingSpotSensorDataSink> pmc;
public slots:
    void signalVehicleSensed(bool vehicleParked, SensorId sensorId);
    void signalVehicleParkedOnSpot(SensorId sensorId);
    void signalVehicleLeftParkingSpot(SensorId sensorId);

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override;
};


#endif //CS460_PROJECT_1_PARKINGSPOT_H