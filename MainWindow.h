#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Card.h"
#include "DeckControl.h"
#include "Field.h"
#include "BattleField.h"
#include "Player.h"
#include "QStackedWidget"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QPixmap>
#include "GameControl.h"
#include <QFile>
#include <QDir>
#include <QDataStream>
#include <QDebug>

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
    QGraphicsScene *scene;
    QGraphicsView *view;
    int status;
    DeckControl *deckControl;
    GameControl *gameControl;
    Account *account;
//    MutiModeControl mutiModeControl;
//    MenuControl menuControl;
 //   AIModeControl aIModeControl;
 //   SettingControl settingControl;

signals:
    void exit();

public slots:
    void goToDeck();
    void goToMultiMode();
};

#endif // MAINWINDOW_H
