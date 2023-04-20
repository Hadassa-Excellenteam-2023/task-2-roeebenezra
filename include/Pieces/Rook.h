#pragma once
#include "Piese.h"

class Rook : public Piece
{
public:
    Rook(const bool& color) : Piece(color) {}

    bool isValidMove(const Pos& src, const Pos& dst) override {
        return (src.x == dst.x || src.y == dst.y) && (src != dst);
    }

private:
    static bool m_registerItWhite;
    static bool m_registerItBlack;
};
