/**
 * these are strictly for ease of metadata passing when
 * positioning/coloring things on initialization
 * of the GUI.
 */

#ifndef CS460_PROJECT_1_GUISTRUCTS_H
#define CS460_PROJECT_1_GUISTRUCTS_H

#include <QEasingCurve>

// for ease of use to pass this to child widgets
// only for use on front end
struct WidgetMeta {
    int x;
    int y;
    int width;
    int height;
    QColor color;
    int zPos;
};

struct AnimationMeta {
    int entryDelay;

    QEasingCurve movementType;
    int approachGateTime;
    int throughGateTime;
    int xFirstEntryGateSensor;
    int xSecondEntryGateSensor;
    int xFirstExitGateSensor;
    int xSecondExitGateSensor;

    int yEntryTrack;
    int yExitTrack;

    int xSpot;
    int ySpot;

    int generalMovementTime;
    int parkPauseTime;
    int parkTime;
    // int gateOpenDelay; // this should be constant
};

// quick use only. may expand usage later.
struct Point {
    int x; int y;
};

#endif //CS460_PROJECT_1_GUISTRUCTS_H