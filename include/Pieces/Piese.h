#pragma once
#include "../Utilities.h"
#include "../Factory.h"


class Piece {
public:
    Piece(const bool& color) : _is_white(color), m_pos({0,0}) {}
    
    virtual ~Piece() = default;

    virtual bool isValidMove(const Pos&, const Pos&, board_vec_const_ref board) = 0;

    bool getColor() const { return _is_white; }
    
    Pos getPos() const { return m_pos; }

protected:
    Pos m_pos;
    bool _is_white;
};
