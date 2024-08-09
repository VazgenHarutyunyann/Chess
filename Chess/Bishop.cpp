#include <iostream>
#include <cmath>

#include "Bishop.hpp"

bishop::bishop(const std::string& place, const std::string& color) : figure(place, color)
{
    symbol = 'B';
}
bishop::~bishop()
{

}
bool bishop::underAttack(const std::string& p, figure* myboard[8][8])
{
    int newRow = p[1] - '1';
    int newCol = p[0] - 'A';

    if (abs(newRow - (place[1] - '1')) != abs(newCol - (place[0] - 'A'))) 
    {   
        
        return false; 
    }

    int rowStep = (newRow > (place[1] - '1')) ? 1 : -1;
    int colStep = (newCol > (place[0] - 'A')) ? 1 : -1;

    int row = place[1] - '1' + rowStep;
    int col = place[0] - 'A' + colStep;
    while (row != newRow && col != newCol) 
    {
        if (myboard[row][col] != nullptr) 
        {
            return false;
        }
        row += rowStep;
        col += colStep;
    }
    return true; 
}
void bishop::move(const std::string& newPos)
{
    place = newPos;
}

void bishop::print()
{
    std::cout << "I am a " << color << " bishop and my place is " << place << std::endl;
}
char bishop::getSymbol() const
{
    return symbol;
}
int bishop::getRow() const
{
    int row = place[1] - '1';
    return row;
}
int bishop::getCol() const
{
    int col = place[0] - 'A';
    return col;
}
std::string bishop::getColor() const
{
    return color;
}