#include "board.h"
#include <QGridLayout>
#include <QPainter>
Board::Board(QWidget * parent) : QWidget(parent){

}

void Board::paintEvent(QPaintEvent * event){
    QPainter painter(this);

    float squareSize = 50;
    for(int row = 0; row < 8; row ++){
        for(int col = 0; col < 8 ; col++){
            if((row + col) % 2 == 0){
                painter.setPen(Qt::white);
                painter.setBrush(Qt::white);
            }
            else{
                painter.setPen(Qt::black);
                painter.setBrush(Qt::black);
            }
            painter.drawRect(this->x() + (row + 1) * squareSize, this->y() + (col + 1) * squareSize, squareSize, squareSize);
            painter.fillRect(this->x() + (row + 1) * squareSize, this->y() + (col + 1) * squareSize, squareSize, squareSize, painter.brush());
        }
    }
}
