#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <QWidget>


class ChessPiece : public QWidget{
public:
    ChessPiece(QWidget * parent = nullptr);
    ChessPiece(int row, int column, QWidget * parent =nullptr);
    enum Type{Pawn, Knight, Bishop, Rook, Queen, King};
    std::pair<int, int> getPosition();
    bool getColor();
private:
    std::pair<int, int> * position;
    bool color; // false == black | true == white
};



#endif // CHESSPIECE_H
