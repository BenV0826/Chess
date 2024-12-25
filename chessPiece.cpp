#include "ChessPiece.h"

//TODO Change chesspiece from a QWidget. Should not be concerned at all with the view.

ChessPiece::ChessPiece(Type typeInit) : type(typeInit){
    switch(type) {
    case (ChessPiece::Type::Pawn) :
        pattern = {-1, -1, 0};
        break;
    case (ChessPiece::Type::Knight) :
        pattern =  {2, 1, 0};
        break;
    case (ChessPiece::Type::Bishop) :
        pattern = {0, 1, 1};
        break;
    case (ChessPiece::Type::Rook) :
        pattern = {1, 0, 1};
        break;
    case (ChessPiece::Type::Queen) :
        pattern = {1, 1, 1};
        break;
    case (ChessPiece::Type::King) :
        pattern =  {1, 1, 0};
        break;
    default:
        break;
    }
    return;
}


// Getter for position
std::pair<int, int> ChessPiece::getPosition()
{
    return *position;
}

// Getter for color
bool ChessPiece::getColor()
{
    return color;
}
