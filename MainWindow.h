#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DeckControl.h"
#include "GameControl.h"

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

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    DeckControl *deckControl;
    GameControl *gameControl;
    Account *account;

signals:
    void exit();

public slots:
    void goToDeck();
    void goToGame();
};

#endif // MAINWINDOW_H
