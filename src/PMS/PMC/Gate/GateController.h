//
// Created by Eliud Garcia on 2/24/26.
//

#ifndef CS460_PROJECT_1_ENTRANCEGATE_H
#define CS460_PROJECT_1_ENTRANCEGATE_H

#include "../../PMSGUI/PMSGUIInterfaces/IInductionSensorDataSink.h"
#include "../PMCInterfaces/IGateInstructionSink.h"

class CentralGateController;


class GateController
{
public:
	GateController(IGateInstructionSink* gate);
    ~GateController() = default;

    // GateController
    void open();
    void close();
    void setGateHardware(IGateInstructionSink& gateHardware);

private:
    // TODO (Future for demo construction):
    // set/connect this manually after initializing hardware (gui) component.
    // many need to make sink(i.e. hardware) public.
    IGateInstructionSink* gateHardware = nullptr;
};



#endif //CS460_PROJECT_1_ENTRANCEGATE_H