#pragma once
#include "Utilities.h"
#include "Factory.h"


class Piece {
public:
    Piece(const bool& color) : m_is_white(color) {}
    
    virtual ~Piece() = default;

    virtual bool isValidMove(const Pos&, const Pos&, const board_vec_t& board) = 0;

    bool getColor() const { return m_is_white; }

protected:
    bool m_is_white;
};
