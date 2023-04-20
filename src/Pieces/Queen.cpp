#include "../include/Pieces/Queen.h"


bool Queen::m_registerItWhite = Factory<Piece>::registerit('Q', []() -> std::unique_ptr<Piece> {
    return make_unique<Queen>(true);
    });


bool Queen::m_registerItBlack = Factory<Piece>::registerit('q', []() -> std::unique_ptr<Piece> {
    return make_unique<Queen>(false);
    });



bool Queen::isValidMove(const Pos& src, const Pos& dst, board_vec_const_ref board) {
    // Check if the move is horizontal, vertical, or diagonal
    int deltaRow = abs(dst.x - src.x);
    int deltaCol = abs(dst.y - src.y);

    if (deltaRow != 0 && deltaCol != 0 && deltaRow != deltaCol) {
        return false;
    }

    // Check if there are any pieces blocking the path to the destination
    int deltaRowSign = (dst.x > src.x) ? 1 : -1;
    int deltaColSign = (dst.y > src.y) ? 1 : -1;

    int currRow = src.x + deltaRowSign;
    int currCol = src.y + deltaColSign;

    while (currRow != dst.x || currCol != dst.y) {
        if (board[currRow][currCol] != nullptr) {
            return false;
        }

        currRow += deltaRowSign;
        currCol += deltaColSign;
    }

    return true;
}