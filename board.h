#ifndef BOARD_H
#define BOARD_H
#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
class Board : public QWidget {

    Q_OBJECT

private :
    QPoint selectedSquare;

public:
    explicit Board(QWidget * parent = nullptr);

protected:
    void paintEvent(QPaintEvent * event) override ;
    void mousePressEvent(QMouseEvent * event) override;
    QSize sizeHint() const override;
};

#endif // BOARD_H
