#pragma once
#include "Pieces/Piese.h"
#include "Factory.h"
#include "Pieces/King.h"

class Board
{
public:
	Board(const string&);

	void init(const string&);

	int getResponse(const string&);

	bool isEmpty(const Pos& pos) const { return m_board[pos.x][pos.y] == nullptr; }
	
	bool isOccupiedByOpponent(const Pos& pos) const { return m_board[pos.x][pos.y]->getColor() != m_whith_turn; }
	
	bool isOccupiedBySameColor(const Pos& pos) const;
	
	bool isLegalMove(const Pos&, const Pos&) const;
	
	void executeMove(const Pos&, const Pos&);
	
	bool isCheck(const bool&) const;
	
	void undoMove(const Pos&, const Pos&);

	void setKingPos(Pos pos, const bool& color) { color ? m_w_king_pos = pos : m_b_king_pos = pos; }

private:
	bool m_whith_turn;
	board_vec_t m_board;
	Pos m_w_king_pos;
	Pos m_b_king_pos;
};