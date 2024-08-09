#include <iostream>

#include "Figure.hpp"
#include "Bishop.hpp"
#include "Queen.hpp"
#include "Rook.hpp"
#include "Knight.hpp"
#include "Pawn.hpp"
#include "King.hpp"
#include "board.hpp"

int main()
{
    chessboard board;

    board.placepiece("H2", new queen("H2", "White"));
    board.placepiece("C1", new king("C1", "White"));
    board.placepiece("B2" , new rook("B2", "White"));

    board.placepiece("A8", new king("A8", "Black"));

    if (board.getBoard())
    {
        board.print();
        std::cout << std::endl;

        if (!board.checkmate_after_one_move())
        {
            std::cout << "In this position there is not checkmate: ";
        }
    
        std::cout << std::endl;
    }
    
    return 0;
}