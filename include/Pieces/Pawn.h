#pragma once
#include "Piese.h"


class Pawn : public Piece
{
public:
    Pawn(const bool& color) : Piece(color), _has_moved(false) {}

    bool isValidMove(const Pos& src, const Pos& dst, board_vec_const_ref board) override;

private:
    bool _has_moved;  // Did his first move or not
    static bool m_registerItWhite;
    static bool m_registerItBlack;
};
