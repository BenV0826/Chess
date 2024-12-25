#include "ChessPiece.h"

std::vector<int> ChessPiece::getPattern() const{
    switch(type) {
    case (ChessPiece::Type::Pawn) :
        return {-1, -1, 0};
        break;
    case (ChessPiece::Type::Knight) :
        return {2, 1, 0};
        break;
    case (ChessPiece::Type::Bishop) :
        return {0, 1, 1};
        break;
    case (ChessPiece::Type::Rook) :
        return {1, 0, 1};
        break;
    case (ChessPiece::Type::Queen) :
        return {1, 1, 1};
        break;
    case (ChessPiece::Type::King) :
        return {1, 1, 0};
        break;
    default:
        break;
    }
    return{0, 0, 0};
}


// Constructor
ChessPiece::ChessPiece(QWidget *parent)
    : QWidget(parent)
    , position(new std::pair<int, int>{0, 0})
    , color(true)
{}
ChessPiece::ChessPiece(int row, int col, QWidget *parent)
    : QWidget(parent)
    , position(new std::pair<int, int>{row, col})
{}



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
