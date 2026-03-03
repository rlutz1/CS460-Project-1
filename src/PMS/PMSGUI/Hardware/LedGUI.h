//
// Created by Eliud Garcia on 2/24/26.
//

#ifndef CS460_PROJECT_1_LEDGUI_H
#define CS460_PROJECT_1_LEDGUI_H
#include <QGraphicsWidget>

#include "../GUIStructs/GUIStructs.h"

class LedGUI : QGraphicsWidget {
    Q_OBJECT;

public:
    LedGUI(QGraphicsScene& scene, WidgetMeta widgetMeta);

    WidgetMeta wm;

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override;
};


#endif //CS460_PROJECT_1_LEDGUI_H