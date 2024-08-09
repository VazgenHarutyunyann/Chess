#include <iostream>

#include "board.hpp"
#include "King.hpp"

bool chessboard::inBoard = true;

chessboard::chessboard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = nullptr;
        }
    }
}
chessboard::~chessboard() 
{
    for (int i = 0; i < 8; ++i) 
    {
        for (int j = 0; j < 8; ++j) 
        {
            delete board[i][j];
        }
    }
}
void chessboard::placepiece(const std::string& pos, figure* piece)
{
    int row = pos[1] - '1';
    int col = pos[0] - 'A';
    if (row < 0 || row >= 8 || col < 0 || col >= 8) 
    {
        std::cout << "Is not in board: " << std::endl;
        chessboard::inBoard = false;
        return;
    }

    delete board[row][col];
    board[row][col] = piece; 
}
bool chessboard::checkmate_after_one_move() {
    std::string kingPosition;
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            figure* piece = board[row][col];
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
            figure* piece = board[row][col];
            if (piece != nullptr && piece->getSymbol() != 'K') 
            {
                for (int newRow = 0; newRow < 8; ++newRow) 
                {
                    for (int newCol = 0; newCol < 8; ++newCol) 
                    {
                        std::string targetPosition = std::string(1, newCol + 'A') + std::to_string(newRow + 1);
                        if (piece->underAttack(targetPosition, board) && (board[newRow][newCol] == nullptr)) 
                        {
                            int originalRow = piece->getRow();
                            int originalCol = piece->getCol();
                            figure* targetPiece = board[newRow][newCol];

                            piece->move(targetPosition);
                            board[originalRow][originalCol] = nullptr;
                            board[newRow][newCol] = piece;
                            if (mateAnalyse(kingPosition) && !take(kingPosition)) 
                            {   
                                print();
                                std::cout << "After " << piece->getSymbol() << " to " << targetPosition << " is mate: " << std::endl;
                                return true; 
                            }

                            piece->move(std::string(1, originalCol + 'A') + std::to_string(originalRow + 1));
                            board[originalRow][originalCol] = piece;
                            board[newRow][newCol] = targetPiece;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool chessboard::checkAnalyse(const std::string& kingPosition)
{
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            figure* piece = board[row][col];
            if (piece != nullptr && piece->getColor() != "Black") 
            {
                if (piece->underAttack(kingPosition, board)) 
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


bool chessboard::mateAnalyse(const std::string& kingPosition) 
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

void chessboard::print()
{
    std::cout << "  A B C D E F G H" << std::endl;

    for (int row = 7; row >= 0; row--) 
    {
        std::cout << row + 1 << " ";
        for (int col = 0; col < 8; col++) 
        {
            if (board[row][col] == nullptr) 
            {
                std::cout << "- ";
            } 
            else 
            {
                std::cout << board[row][col]->getSymbol() << " ";
            }
        }
        std::cout << row + 1 << " " << std::endl;
    }
    std::cout << "  A B C D E F G H" << std::endl;
}

bool chessboard::getBoard()
{
    return inBoard;
}

bool chessboard::take(const std::string& kingPosition) 
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
            figure* targetPiece = board[newRow][newCol];

            if (targetPiece != nullptr && targetPiece->getColor() != "Black") 
            {
                figure* originalPiece = board[kingRow][kingCol];

                board[kingRow][kingCol] = nullptr;
                board[newRow][newCol] = originalPiece;
                originalPiece->move(newKingPosition);

                bool inCheck = checkAnalyse(newKingPosition);

                board[newRow][newCol] = targetPiece;
                board[kingRow][kingCol] = originalPiece;
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