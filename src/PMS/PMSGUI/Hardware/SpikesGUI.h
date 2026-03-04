/**
 * this class acts as the spike driver for directional spikes.
 */

#ifndef CS460_PROJECT_1_SPIKES_H
#define CS460_PROJECT_1_SPIKES_H
#include <QGraphicsWidget>

#include "../GUIStructs/GUIStructs.h"

class SpikesGUI : public QGraphicsWidget {
    Q_OBJECT;
public:
    SpikesGUI(QGraphicsScene& scene, WidgetMeta widgetMeta);

    WidgetMeta wm;

    void lower();
    void raise();
    void reset();

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override;
};


#endif //CS460_PROJECT_1_SPIKES_H