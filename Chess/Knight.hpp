#ifndef __KNIGHT__HPP__
#define __KNIGHT__HPP__

#include "Figure.hpp"

class knight : public figure
{
public:
    knight(const std::string&, const std::string&);
    ~knight();
    
    virtual bool underAttack(const std::string&, figure* board[8][8]);
    virtual void move(const std::string&);
    void print() override;
    char getSymbol() const override;
    int getRow() const override;
    int getCol() const override;
    std::string getColor() const override;
};

#endif //__KNIGHT__HPP__