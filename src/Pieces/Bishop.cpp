#include "Pieces/Bishop.h"


bool Bishop::m_registerItWhite = Factory<Piece>::registerit('B', []() -> unique_ptr<Piece> {
    return make_unique<Bishop>(true);
    });


bool Bishop::m_registerItBlack = Factory<Piece>::registerit('b', []() -> unique_ptr<Piece> {
    return make_unique<Bishop>(false);
    });


bool Bishop::isValidMove(const Pos& src, const Pos& dst, const board_vec_t& board) {
    // Check if the move is diagonal
    int deltaRow = abs(dst.x - src.x);
    int deltaCol = abs(dst.y - src.y);

    if (deltaRow != deltaCol) {
        return false;
    }

    // Check if there are any pieces blocking the path to the destination
    int deltaRowSign = (dst.x > src.x) ? 1 : -1;
    int deltaColSign = (dst.y > src.y) ? 1 : -1;

    int currRow = src.x + deltaRowSign;
    int currCol = src.y + deltaColSign;

    while (currRow != dst.x && currCol != dst.y) {
        if (board[currRow][currCol] != nullptr) {
            return false;
        }

        currRow += deltaRowSign;
        currCol += deltaColSign;
    }

    return true;
}