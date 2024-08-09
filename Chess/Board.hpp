#ifndef __CHESSBOARD__HPP__
#define __CHESSBOARD__HPP__

#include "Figure.hpp"

class chessboard
{
private:
    figure* board[8][8];
    static bool inBoard;
public:
    chessboard();
    void placepiece(const std::string&, figure*);
    bool checkmate_after_one_move();
    bool mateAnalyse(const std::string&);
    bool checkAnalyse(const std::string&);
    void print();
    static bool getBoard();
    bool take(const std::string&);
    ~chessboard();
};

#endif //__CHESSBOARD__HPP__