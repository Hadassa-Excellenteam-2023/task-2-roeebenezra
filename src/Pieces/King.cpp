#include "Pieces/King.h"


// White king
bool King::m_registerItWhite = Factory<Piece>::registerit('K', []() -> unique_ptr<Piece> {
    return make_unique<King>(true);
    });


// Black king
bool King::m_registerItBlack = Factory<Piece>::registerit('k', []() -> unique_ptr<Piece> {
    return make_unique<King>(false);
    });


// Check if the move is valid
bool King::isValidMove(const Pos& src, const Pos& dst, const board_vec_t& board) {
    // Check if the destination is adjacent to the source position
    if (abs(dst.x - src.x) > 1 || abs(dst.y - src.y) > 1) {
        return false;
    }

    // Check if the destination is empty or occupied by an opponent's piece
    if (board[dst.x][dst.y] != nullptr) {
        if (board[dst.x][dst.y]->getColor() == this->getColor()) 
            return false;
    }

    return true;
}