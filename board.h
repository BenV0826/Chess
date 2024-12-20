#ifndef BOARD_H
#define BOARD_H
#include <QWidget>
#include <QPaintEvent>
class Board : public QWidget {

    Q_OBJECT

public:
    explicit Board(QWidget * parent = nullptr);
    void setBoard(QColor, QColor);

protected:
    void paintEvent(QPaintEvent * event) override ;
};

#endif // BOARD_H
