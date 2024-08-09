#ifndef __FIGURE__HPP__
#define __FIGURE__HPP__

#include <string>

class figure
{
protected:
    std::string place;
    std::string color;
    char symbol;
public:
    figure(const std::string&, const std::string&);
    virtual ~figure();

    virtual bool underAttack(const std::string&, figure* board[8][8]) = 0;
    virtual void move(const std::string&) = 0;
    virtual void print() = 0;
    virtual char getSymbol() const = 0;
    virtual int getRow() const = 0;
    virtual int getCol() const = 0;
    virtual std::string getColor() const = 0;
};

#endif //__FIGURE__HPP__