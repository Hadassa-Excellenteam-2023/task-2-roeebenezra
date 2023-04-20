#pragma once
#include "Piese.h"

class King : public Piece
{
public:
	King(const bool &color) : Piece(color) {}

	bool isValidMove(const Pos& src, const Pos& dst) override {
		return (abs(dst.x - src.x) <= 1 || abs(dst.y - src.y) <= 1);
	}

private:
	static bool m_registerItWhite;
	static bool m_registerItBlack;
};
