#include "Board.h"


Board::Board(const string& start)
{
	init(start);
}


void Board::init(const string& start)
{
	for (int i = 0; i < BOARD_SIZE; ++i) {
		vector<unique_ptr<Piece>> row;
		for (int j = 0; j < BOARD_SIZE; ++j) {
			int ind = i * BOARD_SIZE + j;
			auto piece = Factory<Piece>::create(start[ind]);
			row.push_back(move(piece));
		}
		m_board.push_back(move(row));
	}	

	_whith_turn = true;
	_w_king_pos = { 0, 4 };
	_b_king_pos = { 7, 4 };
}


int Board::getResponse(const std::string& input) {

	// parse the input string
	Pos src = { input[0] - 'a', input[1] - '1' };
	Pos dst = { input[2] - 'a', input[3] - '1' };

	// check if the source is empty
	if (isEmpty(src)) {
		return ErrorCode::InvalidSourceEmpty;
	}

	// check if the source is occupied by the opponent
	if (isOccupiedByOpponent(src)) {
		return ErrorCode::InvalidSourceOccupiedByOpponent;
	}

	// check if the destination is occupied by the same color of the current player
	if (isOccupiedBySameColor(dst)) {
		return ErrorCode::InvalidDestinationOccupiedBySameColor;
	}

	// check if the player move is legal
	if (!isLegalMove(src, dst)) {
		return ErrorCode::InvalidMove;
	}

	// execute the move
	executeMove(src, dst);

	// check if the player caused himself check
	if (isCheck(_whith_turn)) {
		undoMove(src, dst);
		return ErrorCode::InvalidMoveCausesCheck;
	}
	
	_whith_turn = !_whith_turn; // change the player

	// check if the opponent is in check
	if (isCheck(_whith_turn)) {
		return OpponentInCheck;
	}

	// Update king position if the king was moved
	if (typeid(*m_board[dst.x][dst.y]) == typeid(King))
		setKingPos({ dst.x, dst.y }, m_board[dst.x][dst.y]->getColor());


	return ValidMove;
}


bool Board::isOccupiedBySameColor(const Pos& pos) const
{
	if (isEmpty(pos))
		return false;
	return m_board[pos.x][pos.y]->getColor() == _whith_turn; 
}


// TODO : finish implementation
bool Board::isLegalMove(const Pos& src, const Pos& dst) const
{
	return m_board[src.x][src.y]->isValidMove(src, dst);
}


void Board::executeMove(const Pos& src, const Pos& dst)
{
	//unique_ptr<Piece> destPtr = move(m_board[dst.x][dst.y]);
	
	// move the piece
	m_board[dst.x][dst.y] = move(m_board[src.x][src.y]);
	m_board[src.x][src.y] = nullptr;
}


bool Board::isCheck(const bool&) const
{
	// TODO : finish implementation
	return false;
}


void Board::undoMove(const Pos& src, const Pos& dst)
{
	m_board[src.x][src.y] = move(m_board[dst.x][dst.y]);
	m_board[dst.x][dst.y] = nullptr;
}