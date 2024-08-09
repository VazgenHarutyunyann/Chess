#ifndef __KING__HPP__
#define __KING__HPP__

#include "Figure.hpp"

class king : public figure
{
public:
    king(const std::string&, const std::string&);
    ~king();
    
    virtual bool underAttack(const std::string&, figure* board[8][8]);
    virtual void move(const std::string&);
    void print() override;
    char getSymbol() const override;
    int getRow() const override;
    int getCol() const override;
    std::string getColor() const override;
};

#endif //__KING__HPP__