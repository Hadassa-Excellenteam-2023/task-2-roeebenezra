#pragma once
#include "Piese.h"


class Bishop : public Piece
{
public:
    Bishop(const bool& color) : Piece(color) {}

    bool isValidMove(const Pos& src, const Pos& dst, board_vec_const_ref board) override;

private:
    static bool m_registerItWhite;
    static bool m_registerItBlack;
};
