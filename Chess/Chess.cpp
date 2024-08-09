#include <iostream>

#include "Figure.hpp"
#include "Bishop.hpp"
#include "Queen.hpp"
#include "Rook.hpp"
#include "Knight.hpp"
#include "Pawn.hpp"
#include "King.hpp"
#include "Board.hpp"

int main()
{
    board myboard;

    myboard.placepiece("H2", new queen("H2", "White"));
    myboard.placepiece("C1", new king("C1", "White"));
    myboard.placepiece("B2" , new rook("B2", "White"));

    myboard.placepiece("A8", new king("A8", "Black"));

    if (myboard.getBoard())
    {
        myboard.print();
        std::cout << std::endl;

        if (!myboard.checkmate_after_one_move())
        {
            std::cout << "In this position there is not checkmate: ";
        }
    
        std::cout << std::endl;
    }
    
    return 0;
}