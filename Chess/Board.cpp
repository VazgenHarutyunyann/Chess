#include <iostream>

#include "Board.hpp"
#include "King.hpp"

bool board::inBoard = true;

board::board()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            myboard[i][j] = nullptr;
        }
    }
}
board::~board() 
{
    for (int i = 0; i < 8; ++i) 
    {
        for (int j = 0; j < 8; ++j) 
        {
            delete myboard[i][j];
        }
    }
}
void board::placepiece(const std::string& pos, figure* piece)
{
    int row = pos[1] - '1';
    int col = pos[0] - 'A';
    if (row < 0 || row >= 8 || col < 0 || col >= 8) 
    {
        std::cout << "Is not in board: " << std::endl;
        board::inBoard = false;
        return;
    }

    delete myboard[row][col];
    myboard[row][col] = piece; 
}
bool board::checkmate_after_one_move() {
    std::string kingPosition;
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            figure* piece = myboard[row][col];
            if (piece != nullptr && piece->getSymbol() == 'K' && piece->getColor() == "Black")
            {
                kingPosition = std::string(1, col + 'A') + std::to_string(row + 1);
                break;
            }
        }
    }
    
    if (mateAnalyse(kingPosition) && !take(kingPosition)) 
    {
        std::cout << "Checkmate: " << std::endl;
        return true;
    }

    for (int row = 0; row < 8; ++row) 
    {
        for (int col = 0; col < 8; ++col) 
        {
            figure* piece = myboard[row][col];
            if (piece != nullptr && piece->getSymbol() != 'K') 
            {
                for (int newRow = 0; newRow < 8; ++newRow) 
                {
                    for (int newCol = 0; newCol < 8; ++newCol) 
                    {
                        std::string targetPosition = std::string(1, newCol + 'A') + std::to_string(newRow + 1);
                        if (piece->underAttack(targetPosition, myboard) && (myboard[newRow][newCol] == nullptr)) 
                        {
                            int originalRow = piece->getRow();
                            int originalCol = piece->getCol();
                            figure* targetPiece = myboard[newRow][newCol];

                            piece->move(targetPosition);
                            myboard[originalRow][originalCol] = nullptr;
                            myboard[newRow][newCol] = piece;
                            if (mateAnalyse(kingPosition) && !take(kingPosition)) 
                            {   
                                print();
                                std::cout << "After " << piece->getSymbol() << " to " << targetPosition << " is mate: " << std::endl;
                                return true; 
                            }

                            piece->move(std::string(1, originalCol + 'A') + std::to_string(originalRow + 1));
                            myboard[originalRow][originalCol] = piece;
                            myboard[newRow][newCol] = targetPiece;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool board::checkAnalyse(const std::string& kingPosition)
{
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            figure* piece = myboard[row][col];
            if (piece != nullptr && piece->getColor() != "Black") 
            {
                if (piece->underAttack(kingPosition, myboard)) 
                {
                    
                    if (piece->getSymbol() == 'P')
                    {
                        int startCol = piece->getCol();
                        int kingCol = kingPosition[0] - 'A';
                        if (startCol == kingCol)
                        {
                            return false;
                        }
                    }
                    return true;
                }
            }
        }
    }
    return false;
}


bool board::mateAnalyse(const std::string& kingPosition) 
{
    if (!checkAnalyse(kingPosition)) 
    {
        return false; 
    }

    int rowOffsets[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int colOffsets[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    int kingRow = kingPosition[1] - '1';
    int kingCol = kingPosition[0] - 'A';

    for (int i = 0; i < 8; ++i) {
        int newRow = kingRow + rowOffsets[i];
        int newCol = kingCol + colOffsets[i];

        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) 
        {
            std::string newKingPosition = std::string(1, newCol + 'A') + std::to_string(newRow + 1);
            if (!checkAnalyse(newKingPosition)) 
            {
                return false; 
            }
        }
    }
    return true; 
}

void board::print()
{
    std::cout << "  A B C D E F G H" << std::endl;

    for (int row = 7; row >= 0; row--) 
    {
        std::cout << row + 1 << " ";
        for (int col = 0; col < 8; col++) 
        {
            if (myboard[row][col] == nullptr) 
            {
                std::cout << "- ";
            } 
            else 
            {
                std::cout << myboard[row][col]->getSymbol() << " ";
            }
        }
        std::cout << row + 1 << " " << std::endl;
    }
    std::cout << "  A B C D E F G H" << std::endl;
}

bool board::getBoard()
{
    return inBoard;
}

bool board::take(const std::string& kingPosition) 
{
    int kingRow = kingPosition[1] - '1';
    int kingCol = kingPosition[0] - 'A';

    int rowOffsets[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int colOffsets[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; ++i) 
    {
        int newRow = kingRow + rowOffsets[i];
        int newCol = kingCol + colOffsets[i];

        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) 
        {
            std::string newKingPosition = std::string(1, newCol + 'A') + std::to_string(newRow + 1);
            figure* targetPiece = myboard[newRow][newCol];

            if (targetPiece != nullptr && targetPiece->getColor() != "Black") 
            {
                figure* originalPiece = myboard[kingRow][kingCol];

                myboard[kingRow][kingCol] = nullptr;
                myboard[newRow][newCol] = originalPiece;
                originalPiece->move(newKingPosition);

                bool inCheck = checkAnalyse(newKingPosition);

                myboard[newRow][newCol] = targetPiece;
                myboard[kingRow][kingCol] = originalPiece;
                originalPiece->move(kingPosition);

                if (!inCheck) 
                {
                    return true;
                }
            }
        }
    }

    return false;
}