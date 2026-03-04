//
// Created by lutzr on 2/25/2026.
//

#ifndef CS460_PROJECT_1_ENTRANCEGATEGUI_H
#define CS460_PROJECT_1_ENTRANCEGATEGUI_H

#include <QPointer>
#include "../../Initialization.h"
#include "../../Definitions/Identifiers.h"
#include "../../PMC/PMCInterfaces/IGateInstructionSink.h"
#include "../Hardware/LedGUI.h"
#include "../Hardware/SensorGUI.h"
#include "../Hardware/SpikesGUI.h"
#include "../GUIStructs/GUIStructs.h"
#include "../PMSGUIInterfaces/IInductionSensorDataSink.h"


class ParkingManagementController;

class EntranceGateGUI : public QGraphicsWidget, public IGateInstructionSink {
    Q_OBJECT;

public:
    EntranceGateGUI(QGraphicsScene& scene, InitializationPackage& initPackage, GateId id, WidgetMeta widgetMeta);

    QColor currColor;
    QColor openGateIndicator;
    QColor closedGateIndicator;
    QColor openGateLight;
    QColor closedGateLight;

    WidgetMeta wm;
    GateId id;
    QPointer<LedGUI> led;
    QPointer<SensorGUI> initOpenSensor;
    QPointer<SensorGUI> stayOpenSensor;
    QPointer<SpikesGUI> spikes;

    std::shared_ptr<IInductionSensorDataSink> pmc;

    void close();
    void open();
    void flash(bool flashingOn);
    void reset();

    // IGateInstructionSink
    void signalGateClose() override;
    void signalGateOpen() override;

public slots:
    void vehicleOnEntranceGateInductionSensor(bool sensorState, SensorId sensorId);
    void vehiclePassedSecondEntranceGateSensor(bool sensorState, SensorId sensorId);


protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override;

private:

};


#endif //CS460_PROJECT_1_ENTRANCEGATEGUI_H