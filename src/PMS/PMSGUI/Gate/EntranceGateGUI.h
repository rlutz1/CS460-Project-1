//
// Created by lutzr on 2/25/2026.
//

#ifndef CS460_PROJECT_1_ENTRANCEGATEGUI_H
#define CS460_PROJECT_1_ENTRANCEGATEGUI_H
#include <QGraphicsWidget>
#include "../../Initialization.h"
#include "../../Definitions/Identifiers.h"
#include "../../PMC/PMCInterfaces/IGateInstructionSink.h"
#include "../Hardware/LedGUI.h"
#include "../Hardware/SensorGUI.h"
#include "../Hardware/SpikesGUI.h"

#include "../GUIStructs/GUIStructs.h"
#include "../PMSGUIInterfaces/IInductionSensorDataSink.h"

#include <QPointer>

class ParkingManagementController;

class EntranceGateGUI : public QGraphicsWidget, public IGateInstructionSink {
    Q_OBJECT;

public:
    EntranceGateGUI(QGraphicsScene& scene, InitializationPackage& initPackage, GateId id, WidgetMeta widgetMeta);

    QColor currColor;
    QColor openGateIndicator;
    QColor closedGateIndicator;

    WidgetMeta wm;
    GateId id;
    QPointer<LedGUI> led;
    QPointer<SensorGUI> initOpenSensor;
    QPointer<SensorGUI> stayOpenSensor;
    QPointer<SpikesGUI> spikes;

    IInductionSensorDataSink* pmc;

    void addSignalReceiver(IInductionSensorDataSink* pmc);
    void reset();

    // IGateInstructionSink
    void signalGateClose() override;
    void signalGateOpen() override;

public slots:
    void vehicleOnEntranceGateInductionSensor();
    void vehiclePassedSecondEntranceGateSensor();


protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override;

private:

};


#endif //CS460_PROJECT_1_ENTRANCEGATEGUI_H