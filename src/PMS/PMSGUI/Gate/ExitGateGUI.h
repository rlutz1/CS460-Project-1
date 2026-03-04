//
// Created by lutzr on 2/25/2026.
//

#ifndef CS460_PROJECT_1_EXITGATEGUI_H
#define CS460_PROJECT_1_EXITGATEGUI_H

#include <QGraphicsOpacityEffect> // only used in this class so far.
#include <QPointer>

#include "../../Initialization.h"
#include "../../Definitions/Identifiers.h"
#include "../Hardware/LedGUI.h"
#include "../Hardware/SensorGUI.h"
#include "../Hardware/SpikesGUI.h"
#include "../GUIStructs/GUIStructs.h"
#include "../../PMC/PMCInterfaces/IGateInstructionSink.h"
#include "../PMSGUIInterfaces/IInductionSensorDataSink.h"



class ParkingManagementController;

class ExitGateGUI : public QGraphicsWidget, public IGateInstructionSink {
    Q_OBJECT;
public:
    ExitGateGUI(QGraphicsScene& scene, InitializationPackage& initPackage, GateId id, WidgetMeta widgetMeta);

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
    void vehicleOnExitGateInductionSensor(bool sensorState, SensorId sensorId);
    void vehiclePassedSecondExitGateSensor(bool sensorState, SensorId sensorId);

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override;

};


#endif //CS460_PROJECT_1_EXITGATEGUI_H