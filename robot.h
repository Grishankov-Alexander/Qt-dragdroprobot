#ifndef ROBOT_H
#define ROBOT_H

#include <QGraphicsItem>

QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
class QParallelAnimationGroup;
QT_END_NAMESPACE

class RobotPart : public QGraphicsObject
{
public:
    RobotPart(QGraphicsItem *parent = 0);

protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override;
    void dropEvent(QGraphicsSceneDragDropEvent *event) override;

    QColor color;
    bool dragOver;
};


class RobotHead : public RobotPart
{
public:
    RobotHead(QGraphicsItem *parent = 0);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0) override;

protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
    void dropEvent(QGraphicsSceneDragDropEvent *event) override;

private:
    QPixmap pixmap;
};


class RobotTorso : public RobotPart
{
public:
    RobotTorso(QGraphicsItem *parent = 0);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *,
               QWidget *widget = 0) override;
};

class RobotLimb : public RobotPart
{
public:
    RobotLimb(QGraphicsItem *parent = 0);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *,
               QWidget *widget = 0) override;
};

class Robot : public RobotPart
{
public:
    Robot(QGraphicsItem *parent = 0);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = 0) override;
};

#endif // ROBOT_H
