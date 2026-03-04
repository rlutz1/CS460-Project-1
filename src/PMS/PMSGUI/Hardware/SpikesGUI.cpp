//
// Created by Eliud Garcia on 2/24/26.
//

#include "SpikesGUI.h"

#include <QGraphicsOpacityEffect>
#include <QGraphicsScene>
#include <QPainter>

SpikesGUI::SpikesGUI(QGraphicsScene& scene, WidgetMeta widgetMeta) :
    wm(widgetMeta)
{
    resize(wm.width, wm.height);
    setZValue(wm.zPos);

    QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(this);
    opacityEffect->setOpacity(0.5);
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

void SpikesGUI::reset() {
    QGraphicsOpacityEffect* opacityEffect = new QGraphicsOpacityEffect(this);
    opacityEffect->setOpacity(0.5);
    setGraphicsEffect(opacityEffect);
}
