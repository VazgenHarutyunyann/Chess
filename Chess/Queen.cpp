#include <iostream>
#include <cmath>

#include "Queen.hpp"

queen::queen(const std::string& place, const std::string& color) : figure(place, color)
{
    symbol = 'Q';
}
queen::~queen()
{}

bool queen::underAttack(const std::string& p, figure* myboard[8][8])
{
    int newRow = p[1] - '1';
    int newCol = p[0] - 'A';

    if (newRow != place[1] - '1' && newCol != place[0] - 'A' && abs(newRow - (place[1] - '1')) != abs(newCol - (place[0] - 'A'))) 
    {
        return false;
    }
    
    int startRow = place[1] - '1';
    int startCol = place[0] - 'A';

    int rowStep = (newRow > startRow) ? 1 : (newRow < startRow) ? -1 : 0;
    int colStep = (newCol > startCol) ? 1 : (newCol < startCol) ? -1 : 0;

    for (int row = startRow + rowStep, col = startCol + colStep; row != newRow || col != newCol; row += rowStep, col += colStep) 
    {
        if (myboard[row][col] != nullptr && myboard[row][col]->getSymbol() != 'K') 
        {
            return false; 
        }
    }

    return true;
}

void queen::move(const std::string& newPos)
{
    place = newPos;
}
void queen::print()
{
    std::cout << "I am a " << color << " queen and my place is " << place << std::endl;
}
char queen::getSymbol() const
{
    return symbol;
}
int queen::getRow() const
{
    int row = place[1] - '1';
    return row;
}
int queen::getCol() const
{
    int col = place[0] - 'A';
    return col;
}
std::string queen::getColor() const
{
    return color;
}