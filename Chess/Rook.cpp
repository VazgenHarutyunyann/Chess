#include <iostream>
#include <cmath>

#include "Rook.hpp"

rook::rook(const std::string& place, const std::string& color) : figure(place, color)
{
    symbol = 'R';
}
rook::~rook()
{

}
bool rook::underAttack(const std::string& p, figure* board[8][8])
{
    int newRow = p[1] - '1';
    int newCol = p[0] - 'A';

    if (p[0] != place[0] && p[1] != place[1]) 
    {
        return false;
    }

    int start, end;
    if (p[0] == place[0]) 
    {
        start = (newCol < (place[1]-'1')) ? newCol : (place[1] - '1');
        end = (newCol > (place[1]-'1')) ? newCol : (place[1] - '1');
    } 
    else 
    {
        start = (newRow < (place[0]-'A')) ? newRow : (place[0] - 'A');
        end = (newRow > (place[0]-'A')) ? newRow : (place[0] - 'A');
    }

    for (int i = start + 1; i < end; ++i) 
    {
        if ((board[place[1] - '1'][i] != nullptr) ||
            (board[i][place[0] - 'A'] != nullptr)) 
        {
            return false; 
        }
    }
    return true;
}
void rook::move(const std::string& newPos)
{
    place = newPos;
}
void rook::print()
{
    std::cout << "I am a " << color << " rook and my place is " << place << std::endl;
}
char rook::getSymbol() const
{
    return symbol;
}
int rook::getRow() const
{
    int row = place[1] - '1';
    return row;
}
int rook::getCol() const
{
    int col = place[0] - 'A';
    return col;
}
std::string rook::getColor() const
{
    return color;
}