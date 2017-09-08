#ifndef DECKCONTROL_H
#define DECKCONTROL_H

#include <QWidget>
#include <QMainWindow>
#include <QObject>
#include "Account.h"
#include "carddatabase.h"

namespace Ui {
class Form;
}

class DeckControl : public QWidget
{
    Q_OBJECT
public:
    explicit DeckControl(QMainWindow *mainWindow, Account *account, QWidget *parent = 0);
    ~DeckControl();

signals:

private:
    Ui::Form *ui;
    Account *account;
    QMainWindow *mainWindow;

public slots:
    void goBack();
    void loadDeck(int);
public:
    void run();
};

#endif // DECKCONTROL_H
