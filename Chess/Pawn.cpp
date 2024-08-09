#include <iostream>
#include <cmath>

#include "Pawn.hpp"

pawn::pawn(const std::string& place, const std::string& color) : figure(place, color)
{
    symbol = 'P';
}
pawn::~pawn()
{

}
bool pawn::underAttack(const std::string& p, figure* board[8][8])
{
    int newRow = p[1] - '1';
    int newCol = p[0] - 'A';

    int startRow = place[1] - '1';
    int startCol = place[0] - 'A';

    int direction = (color == "White") ? 1 : -1;
    
    
    if (newCol == startCol) 
    {
        
        if (newRow == startRow + direction && board[newRow][newCol] == nullptr) 
        {
            
            return true;
        }
        if (startRow == (color == "white" ? 1 : 6) && newRow == startRow + 2 * direction && board[startRow + direction][newCol] == nullptr && board[newRow][newCol] == nullptr) 
        {
            return true;
        }
    }
    
    else if (abs(newCol - startCol) == 1 && newRow == startRow + direction) 
    {
        if (board[newRow][newCol] != nullptr) 
        {
            return true;
        }
    }
    return false;
}
void pawn::move(const std::string& newPos)
{
    place = newPos;   
}
void pawn::print()
{
    std::cout << "I am a " << color << " pawn and my place is " << place << std::endl;
}
char pawn::getSymbol() const
{
    return symbol;
}
int pawn::getRow() const
{
    int row = place[1] - '1';
    return row;
}
int pawn::getCol() const
{
    int col = place[0] - 'A';
    return col;
}
std::string pawn::getColor() const
{
    return color;
}