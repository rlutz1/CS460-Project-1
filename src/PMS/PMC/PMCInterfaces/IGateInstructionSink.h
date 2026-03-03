//
// Created by Eliud Garcia on 2/25/26.
//

#ifndef CS460_PROJECT_1_IGATERESPONSESINK_H
#define CS460_PROJECT_1_IGATERESPONSESINK_H

/**
 * IGateResponseSink - abstract class :
 *      For Hardware (GUI) component to derive (i.e. to implement interface).
 *      Premise is for GUI to handle drawing and animation of response.
 */
class IGateInstructionSink {
public:
    virtual ~IGateInstructionSink() = default;

    virtual void signalGateClose() = 0;
    virtual void signalGateOpen() = 0;
};

#endif //CS460_PROJECT_1_IGATERESPONSESINK_H