//
// Created by Eliud Garcia on 2/24/26.
//

#ifndef CS460_PROJECT_1_SPIKES_H
#define CS460_PROJECT_1_SPIKES_H
#include <QGraphicsWidget>

#include "../GUIStructs/GUIStructs.h"

class SpikesGUI : public QGraphicsWidget {
    Q_OBJECT;
public:
    SpikesGUI(QGraphicsScene& scene, WidgetMeta widgetMeta);

    WidgetMeta wm;

    void reset();

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override;
};


#endif //CS460_PROJECT_1_SPIKES_H