#include "ChessPiece.h"

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
