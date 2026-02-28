//
// Created by lutzr on 2/25/2026.
// this is strictly for ease of metadata generation and passing
//

#ifndef CS460_PROJECT_1_GUISTRUCTS_H
#define CS460_PROJECT_1_GUISTRUCTS_H

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


// quick use only. may expand usage later.
struct Point {
    int x; int y;
};

#endif //CS460_PROJECT_1_GUISTRUCTS_H