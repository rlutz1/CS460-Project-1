//
// Created by Eliud Garcia on 2/24/26.
//

#ifndef CS460_PROJECT_1_DEMOMANAGER_H
#define CS460_PROJECT_1_DEMOMANAGER_H

#include <QGraphicsView>
struct InitializationPackage;

class DemoManager : QGraphicsView {
public:
    DemoManager(InitializationPackage initPackage);
};


#endif //CS460_PROJECT_1_DEMOMANAGER_H