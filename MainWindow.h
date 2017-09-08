#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Card.h"
#include "DeckControl.h"
#include "Field.h"
#include "Lane.h"
#include "Player.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public:
    Player player;
    Player opponent;

    int status;
    DeckControl deckControl;
//    MutiModeControl mutiModeControl;
//    MenuControl menuControl;
 //   AIModeControl aIModeControl;
 //   SettingControl settingControl;

public slots:
    void goToDeck();

};

#endif // MAINWINDOW_H
