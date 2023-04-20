#include "../include/Pieces/King.h"

// White king
bool King::m_registerItWhite = Factory<Piece>::registerit('K', []() -> std::unique_ptr<Piece> {
    return make_unique<King>(true);
    });

// Black king
bool King::m_registerItBlack = Factory<Piece>::registerit('k', []() -> std::unique_ptr<Piece> {
    return make_unique<King>(false);
    });
