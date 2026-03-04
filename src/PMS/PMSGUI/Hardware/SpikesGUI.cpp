//
// Created by Eliud Garcia on 2/24/26.
//

#include "SpikesGUI.h"

#include <QGraphicsOpacityEffect>
#include <QPainter>

SpikesGUI::SpikesGUI(QGraphicsScene& scene, WidgetMeta widgetMeta) :
    wm(widgetMeta)
{
    resize(wm.width, wm.height);
    setZValue(wm.zPos);
    lower();

}

// method to "lower" the spikes
void SpikesGUI::lower() {
    QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(this);
    opacityEffect->setOpacity(0.5);
    setGraphicsEffect(opacityEffect);
}

// method to "raise" the spikes
void SpikesGUI::raise() {
    QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(this);
    opacityEffect->setOpacity(1);
    setGraphicsEffect(opacityEffect);
}

// REQUIRED FOR GRAPHICS ITEM
QRectF SpikesGUI::boundingRect() const {
    return QRectF(wm.x, wm.y, // this is BETTER
                  wm.width, wm.height);
}

// REQUIRED FOR GRAPHICS ITEM
void SpikesGUI::paint(QPainter *painter,
    const QStyleOptionGraphicsItem *option,
    QWidget *widget) {
    painter->setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter->setPen(QPen(Qt::black));
    painter->setBrush(QBrush(wm.color));
    painter->drawRect(boundingRect());
}

// simple method to reset the spikes to a lowered state
void SpikesGUI::reset() {
    lower();
}
