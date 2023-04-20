#include "../include/Pieces/Pawn.h"


bool Pawn::m_registerItWhite = Factory<Piece>::registerit('P', []() -> std::unique_ptr<Piece> {
    return make_unique<Pawn>(true);
    });


bool Pawn::m_registerItBlack = Factory<Piece>::registerit('p', []() -> std::unique_ptr<Piece> {
    return make_unique<Pawn>(false);
    });



bool Pawn::isValidMove(const Pos& src, const Pos& dst, board_vec_const_ref board) {
    // Check if the move is one or two steps forward
    int deltaRow = this->getColor() ? (dst.x - src.x) : (src.x - dst.x);
    int deltaCol = abs(dst.y - src.y);

    if (deltaCol != 0) {
        // Pawns cannot move horizontally unless capturing an opponent's piece
        if (deltaCol != 1 || board[dst.x][dst.y]->getColor() != !this->getColor()) {
            return false;
        }

        // Check if the move is a valid capture
        if (deltaRow != 1) {
            return false;
        }
    }
    else {
        // Check if the move is a valid non-capture
        if (deltaRow == 1) {
            // Pawns can only move one step forward unless it is their first move
            if (_has_moved) {
                return false;
            }
        }
        else if (deltaRow == 2) {
            // Pawns can move two steps forward on their first move only
            if (_has_moved || board[dst.x][dst.y] != nullptr) {
                return false;
            }

            // Check if the path to the destination is clear
            int deltaRow1 = this->getColor() ? 1 : -1;
            int currRow = src.x + deltaRow1;

            if (board[currRow][dst.y] != nullptr) {
                return false;
            }
        }
        else {
            return false;
        }
    }
    
    _has_moved = true;  // Update the pawn's status

    return true;
}