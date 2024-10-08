#ifndef __BISHOP__HPP__
#define __BISHOP__HPP__

#include "Figure.hpp"

class bishop : public figure
{
public:
    bishop(const std::string&, const std::string&);
    ~bishop();
    
    virtual bool underAttack(const std::string&, figure* myboard[8][8]);
    virtual void move(const std::string&);
    void print() override;
    char getSymbol() const override;
    int getRow() const override;
    int getCol() const override;
    std::string getColor() const override;
};

#endif //__BISHOP__HPP__