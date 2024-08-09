#include <iostream>
#include <cmath>

#include "King.hpp"

king::king(const std::string& place, const std::string& color) : figure(place, color)
{
    symbol = 'K';       
}
king::~king()
{

}
bool king::underAttack(const std::string& p, figure* myboard[8][8])
{
    int newRow = p[1] - '1';
    int newCol = p[0] - 'A';

    int startRow = place[1] - '1';
    int startCol = place[0] - 'A';

    int rowDiff = abs(newRow - startRow);
    int colDiff = abs(newCol - startCol);
    if ((rowDiff > 1 || colDiff > 1)) 
    {
        return false;
    }

    return true; 
}
void king::move(const std::string& newPos)
{
    
    place = newPos;
}

void king::print()
{
    std::cout << "I am a " << color << " bishop and my place is " << place << std::endl;
}
char king::getSymbol() const
{
    return symbol;
}
int king::getRow() const
{
    int row = place[1] - '1';
    return row;
}
int king::getCol() const
{
    int col = place[0] - 'A';
    return col;
}
std::string king::getColor() const
{
    return color;
}