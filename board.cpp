#include "board.h"
#include <QGridLayout>
#include <QPainter>
Board::Board(QWidget * parent) : QWidget(parent), selectedSquare(-1, -1){

}

void Board::mousePressEvent(QMouseEvent * event){
    qDebug() << "Mouse clicked at:" << event->pos()
    << "Button:" << event->button();
    QPainter painter(this);
    float squareSize = qMin(this->width(), this->height()) / 8.0f;
    int col = event->pos().x() / squareSize;
    int row = event->pos().y() / squareSize;


    if (col >= 0 && col < 8 && row >= 0 && row < 8) {
        selectedSquare = QPoint(col, row);
        qDebug() << "Selected square:" << selectedSquare;
        update();
    }
}

void Board::paintEvent(QPaintEvent * event){
    QPainter painter(this);
    float squareSize = qMin(this->width(), this->height()) / 8.0f;

    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if ((row + col) % 2 == 0) {
                painter.setBrush(Qt::white);
            } else {
                painter.setBrush(Qt::black);
            }
            if (selectedSquare == QPoint(col, row)) {
                painter.setBrush(Qt::yellow);
            }

            painter.drawRect(col * squareSize, row * squareSize, squareSize, squareSize);
        }
    }
}
