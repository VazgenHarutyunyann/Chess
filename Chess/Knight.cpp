#include <iostream>
#include <cmath>

#include "Knight.hpp"

knight::knight(const std::string& place, const std::string& color) : figure(place, color)
{
    symbol = 'N';
}
knight::~knight()
{

}
bool knight::underAttack(const std::string& p, figure* myboard[8][8])
{
    int currX = place[0] - 'A' + 1;
    int currY = place[1] - '1' + 1;

    int targetX = p[0] - 'A' + 1;
    int targetY = p[1] - '1' + 1;

    int dx = std::abs(targetX - currX);
    int dy = std::abs(targetY - currY);

    if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2))
    {
        return true;
    }

    return false;
}
void knight::move(const std::string& newPos)
{
    place = newPos;
}
void knight::print()
{
    std::cout << "I am a " << color << " knight and my place is " << place << std::endl;
}
char knight::getSymbol() const
{
    return symbol;
}
int knight::getRow() const
{
    int row = place[1] - '1';
    return row;
}
int knight::getCol() const
{
    int col = place[0] - 'A';
    return col;
}
std::string knight::getColor() const
{
    return color;
}