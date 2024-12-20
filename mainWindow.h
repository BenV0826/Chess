#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QHBoxLayout>
#include <QMainWindow>
#include "board.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QWidget *mainWidget;
    QWidget *boardAndOptionsWidget;
    QWidget *chessBoard;
    void setupBoard(QColor *, QColor *);
protected:
    void resizeEvent(QResizeEvent *) override;
};
#endif // MAINWINDOW_H
