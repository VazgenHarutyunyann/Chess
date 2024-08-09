#ifndef __QUEEN__HPP__
#define __QUEEN__HPP__

#include "Figure.hpp"

class queen : public figure
{
public:
    queen(const std::string&, const std::string&);
    ~queen();
    
    virtual bool underAttack(const std::string&, figure* board[8][8]);
    virtual void move(const std::string&);
    void print() override;
    char getSymbol() const override;
    int getRow() const override;
    int getCol() const override;
    std::string getColor() const override;
};

#endif //__QUEEN__HPP__