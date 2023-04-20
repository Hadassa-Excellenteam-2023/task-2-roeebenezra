#pragma once
#include "Pieces/Piese.h"
#include "Factory.h"
#include "Pieces/King.h"

class Board
{
public:
	Board(const string&);

	void init(const string&);

	int getResponse(const std::string&);

	bool isEmpty(const Pos& pos) const { return m_board[pos.x][pos.y] == nullptr; }
	
	bool isOccupiedByOpponent(const Pos& pos) const { return m_board[pos.x][pos.y]->getColor() != _whith_turn; }
	
	bool isOccupiedBySameColor(const Pos& pos) const;
	
	bool isLegalMove(const Pos&, const Pos&) const;
	
	void executeMove(const Pos&, const Pos&);
	
	bool isCheck(const bool&) const;
	
	void undoMove(const Pos&, const Pos&);

	void setKingPos(const Pos& pos, const bool& color) { color ? _w_king_pos = pos : _b_king_pos = pos; }

private:
	bool _whith_turn;
	board_vec m_board;
	Pos _w_king_pos;
	Pos _b_king_pos;
};