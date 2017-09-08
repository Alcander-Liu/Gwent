#ifndef DECKCONTROL_H
#define DECKCONTROL_H

#include <QWidget>
#include <QObject>

namespace Ui {
class Form;
}

class DeckControl : public QWidget
{
    Q_OBJECT
public:
    explicit DeckControl(QWidget *parent = 0);
    ~DeckControl();

signals:

private:
    Ui::Form *ui;

public slots:

public:
    void run();

};

#endif // DECKCONTROL_H
