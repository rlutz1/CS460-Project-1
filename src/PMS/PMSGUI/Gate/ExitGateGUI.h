//
// Created by lutzr on 2/25/2026.
//

#ifndef CS460_PROJECT_1_EXITGATEGUI_H
#define CS460_PROJECT_1_EXITGATEGUI_H
#include <QGraphicsWidget>

#include "../../Initialization.h"
#include "../../Definitions/Identifiers.h"
#include "../Hardware/LedGUI.h"
#include "../Hardware/SensorGUI.h"
#include "../Hardware/SpikesGUI.h"

#include "../GUIStructs/GUIStructs.h"
#include "../../PMC/PMCInterfaces/IGateInstructionSink.h"
#include "../PMSGUIInterfaces/IInductionSensorDataSink.h"

#include <QGraphicsOpacityEffect> // only used in this class so far.

class ParkingManagementController;

class ExitGateGUI : public QGraphicsWidget, public IGateInstructionSink {
    Q_OBJECT;
public:
    ExitGateGUI(QGraphicsScene& scene, InitializationPackage& initPackage, GateId id, WidgetMeta widgetMeta);

    WidgetMeta wm;
    GateId id;
    LedGUI led;
    SensorGUI initOpenSensor;
    SensorGUI stayOpenSensor;
    SpikesGUI spikes;

    void addSignalReceiver(IInductionSensorDataSink* pmc);

    // IGateInstructionSink
    void signalGateClose() override;
    void signalGateOpen() override;

public slots:
    void vehicleOnExitGateInductionSensor();
    void vehiclePassedSecondExitGateSensor();

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override;
    IInductionSensorDataSink* pmc;
};


#endif //CS460_PROJECT_1_EXITGATEGUI_H