#include "../include/Pieces/Rook.h"


bool Rook::m_registerItWhite = Factory<Piece>::registerit('R', []() -> std::unique_ptr<Piece> {
    return make_unique<Rook>(true);
    });


bool Rook::m_registerItBlack = Factory<Piece>::registerit('r', []() -> std::unique_ptr<Piece> {
    return make_unique<Rook>(false);
    });
