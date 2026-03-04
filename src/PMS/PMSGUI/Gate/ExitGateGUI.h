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

    WidgetMeta wm;
    GateId id;
    QPointer<LedGUI> led;
    QPointer<SensorGUI> initOpenSensor;
    QPointer<SensorGUI> stayOpenSensor;
    QPointer<SpikesGUI> spikes;
    std::shared_ptr<IInductionSensorDataSink> pmc;

    void addSignalReceiver(IInductionSensorDataSink* pmc);
    void reset();

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

};


#endif //CS460_PROJECT_1_EXITGATEGUI_H