//
// Created by Eliud Garcia on 2/24/26.
//

#ifndef CS460_PROJECT_1_LEDGUI_H
#define CS460_PROJECT_1_LEDGUI_H
#include <QGraphicsWidget>

#include "../GUIStructs/GUIStructs.h"

class LedGUI : public QGraphicsWidget {
    Q_OBJECT;

public:
    LedGUI(QGraphicsScene& scene, WidgetMeta widgetMeta);

    WidgetMeta wm;
    QColor currColor;

    void reset(QColor color);
    void color(QColor color);

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override;
};


#endif //CS460_PROJECT_1_LEDGUI_H