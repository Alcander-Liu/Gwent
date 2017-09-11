#ifndef TURNPAGEBUTTON_H
#define TURNPAGEBUTTON_H

#include <QObject>
#include <QGraphicsRectItem>

class TurnPageButton : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit TurnPageButton(QObject *parent = nullptr);

signals:
    void buttonPressed();

public slots:

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event){emit buttonPressed();}

};

#endif // TURNPAGEBUTTON_H
