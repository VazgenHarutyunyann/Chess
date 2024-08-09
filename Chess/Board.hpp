#ifndef __BOARD__HPP__
#define __BOARD__HPP__

#include "Figure.hpp"

class board
{
private:
    figure* myboard[8][8];
    static bool inBoard;
public:
    board();
    void placepiece(const std::string&, figure*);
    bool checkmate_after_one_move();
    bool mateAnalyse(const std::string&);
    bool checkAnalyse(const std::string&);
    void print();
    static bool getBoard();
    bool take(const std::string&);
    ~board();
};

#endif //__BOARD__HPP__