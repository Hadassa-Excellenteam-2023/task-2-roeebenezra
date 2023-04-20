#include "../include/Pieces/Rook.h"


bool Rook::m_registerItWhite = Factory<Piece>::registerit('R', []() -> std::unique_ptr<Piece> {
    return make_unique<Rook>(true);
    });


bool Rook::m_registerItBlack = Factory<Piece>::registerit('r', []() -> std::unique_ptr<Piece> {
    return make_unique<Rook>(false);
    });



bool Rook::isValidMove(const Pos& src, const Pos& dst, board_vec_const_ref board) {
    // Check if the move is horizontal or vertical
    if (src.x != dst.x && src.y != dst.y) {
        return false;
    }

    // Check if there are any pieces blocking the path to the destination
    int deltaRow = (src.x == dst.x) ? 0 : (src.x < dst.x ? 1 : -1);
    int deltaCol = (src.y == dst.y) ? 0 : (src.y < dst.y ? 1 : -1);

    int currRow = src.x + deltaRow;
    int currCol = src.y + deltaCol;

    while (currRow != dst.x || currCol != dst.y) {
        if (board[currRow][currCol] != nullptr) {
            return false;
        }

        currRow += deltaRow;
        currCol += deltaCol;
    }

    return true;
}