#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include <QWidget>

class ChessPiece
{
private:
    std::pair<int, int> *position;
    std::vector<int> pattern;
    bool color; // false == black | true == white
    enum Type { Pawn, Knight, Bishop, Rook, Queen, King };
public:
    ChessPiece(Type);
    Type type;
    std::pair<int, int> getPosition();

    bool getColor();



};

#endif // CHESSPIECE_H
