#pragma once
#include "Piese.h"

class Queen : public Piece
{
public:
    Queen(const bool& color) : Piece(color) {}

    bool isValidMove(const Pos& src, const Pos& dst, const board_vec_t& board) override;

private:
    static bool m_registerItWhite;
    static bool m_registerItBlack;
};

