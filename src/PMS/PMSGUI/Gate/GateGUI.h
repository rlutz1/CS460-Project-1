/**
 * this class acts as a general container--primarily visual--
 * for the entrance and exit gates of demo.
 */

#ifndef CS460_PROJECT_1_GATE_H
#define CS460_PROJECT_1_GATE_H
#include "EntranceGateGUI.h"
#include "ExitGateGUI.h"
#include "../../Initialization.h"
#include "../GUIStructs/GUIStructs.h"
#include <QGraphicsScene>
#include <QPointer>

class GateGUI : public QGraphicsWidget {
    Q_OBJECT;

public:
    GateGUI(QGraphicsScene& scene, InitializationPackage& initPackage, WidgetMeta widgetMeta);

    WidgetMeta wm;
    QPointer<EntranceGateGUI> entranceGate;
    QPointer<ExitGateGUI> exitGate;

    void reset();

protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget) override;

};


#endif //CS460_PROJECT_1_GATE_H