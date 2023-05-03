#include "Pieces/Knight.h"


bool Knight::m_registerItWhite = Factory<Piece>::registerit('N', []() -> unique_ptr<Piece> {
    return make_unique<Knight>(true);
    });


bool Knight::m_registerItBlack = Factory<Piece>::registerit('n', []() -> unique_ptr<Piece> {
    return make_unique<Knight>(false);
    });



bool Knight::isValidMove(const Pos& src, const Pos& dst, const board_vec_t& board) {
    // Check if the move is valid for a knight
    int deltaRow = abs(dst.x - src.x);
    int deltaCol = abs(dst.y - src.y);

    return (deltaRow == 1 && deltaCol == 2) || (deltaRow == 2 && deltaCol == 1);
}