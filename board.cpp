#include "board.h"
#include <QGridLayout>
#include <QPainter>
#include <QRect>
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
        if(selectedSquare == QPoint(col, row)){
            selectedSquare =QPoint(-1, -1);
            update();
        }
        else{
        selectedSquare = QPoint(col, row);
        qDebug() << "Selected square:" << selectedSquare;
        update();
        }
    }
}

void Board::paintEvent(QPaintEvent * event){
    QPainter painter(this);

    float squareSize = qMin(this->width(), this->height()) / 8.0f;

    QFont font = painter.font();
    font.setPointSize(squareSize * 0.1f); // Adjust font size to square size
    painter.setFont(font);
    QRect square;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            square = QRect(col * squareSize, row * squareSize, squareSize, squareSize);
            QColor labelColor;
            if ((row + col) % 2 == 0) {
                painter.setBrush(Qt::white);
                labelColor = Qt::black;
            } else {
                painter.setBrush(Qt::black);
                labelColor = Qt::white;
            }
            if (selectedSquare == QPoint(col, row)) {
                painter.setBrush(Qt::yellow);
            }

            painter.drawRect(square);

            if (col == 0) {
                painter.setPen(labelColor);
                QRect textRect(square.x(), square.y(), squareSize * 0.25, squareSize * 0.25);
                painter.drawText(textRect, Qt::AlignLeft, " " + QString::number(row + 1));
            }
            if (row == 7) {
                painter.setPen(labelColor);
                char label = col + 97;
                QRect textRect(square.right() - squareSize * 0.25, square.bottom() - squareSize * 0.25, squareSize * 0.25, squareSize * 0.25);
                painter.drawText(textRect, Qt::AlignRight | Qt::AlignBottom, QString(label) + " ");
            }
            painter.setPen(Qt::black);
        }
    }
}
