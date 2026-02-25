//
// Created by lutzr on 2/25/2026.
//

#ifndef CS460_PROJECT_1_RUN_DEMO_H
#define CS460_PROJECT_1_RUN_DEMO_H

#include "Definitions/Identifiers.h" // this works, but trying to avoid headers in headers
struct InitializationPackage;


int run_demo(int argc, char *argv[]);
void initWindow();
InitializationPackage initConfig();
GateId initGateId(GateType type);

#endif //CS460_PROJECT_1_RUN_DEMO_H