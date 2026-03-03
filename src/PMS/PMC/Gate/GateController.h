//
// Created by Eliud Garcia on 2/24/26.
//

#ifndef CS460_PROJECT_1_ENTRANCEGATE_H
#define CS460_PROJECT_1_ENTRANCEGATE_H

#include "../../PMSGUI/PMSGUIInterfaces/ISensorDataSink.h"
#include "../PMCInterfaces/IGateInstructionSink.h"

class CentralGateController;

class GateController : public ISensorDataSink
{
public:
	GateController() = default;
    ~GateController() = default;

    // IsensorDataSink
    void SensedVehicle(SensorId sensorID) override;
    void NotSensedVehicled(SensorId sensorID) override;

    // GateController
    void open();
    void close();
    void setGateHardware(IGateInstructionSink& gateHardware);
    void setCentralGateController(CentralGateController& centGateController);
    void setGateId(GateId gateId);

private:
    // TODO (Future for demo construction):
    // set/connect this manually after initializing hardware (gui) component.
    CentralGateController* centralGateController = nullptr;
    IGateInstructionSink* gateHardware = nullptr;
    GateId gateId;
    bool vehicleWasAtInteriorSensor = false;
};



#endif //CS460_PROJECT_1_ENTRANCEGATE_H