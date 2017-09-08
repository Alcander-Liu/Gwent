#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Card.h"
#include "DeckControll.h"
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
    DeckControl deckControl;
    int status;
//    MutiModeControl mutiModeControl;
//    MenuControl menuControl;
 //   AIModeControl aIModeControl;
 //   SettingControl settingControl;

public:
    goToDeck();

};

#endif // MAINWINDOW_H
