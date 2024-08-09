#ifndef __PAWN__HPP__
#define __PAWN__HPP__

#include "Figure.hpp"

class pawn : public figure
{
public:
    pawn(const std::string&, const std::string&);
    ~pawn();
    
    bool underAttack(const std::string&, figure* myboard[8][8]) override;
    void move(const std::string&) override;
    void print() override;
    char getSymbol() const override;
    int getRow() const override;
    int getCol() const override;
    std::string getColor() const override;
};

#endif //__PAWN__HPP__