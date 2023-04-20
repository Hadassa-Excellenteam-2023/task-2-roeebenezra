#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <map>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::unique_ptr;
using std::vector;
using std::make_unique;
using std::move;


const int BOARD_SIZE = 8;

struct Pos
{
	int x;
	int y;

	bool operator!=(const Pos& other) const {
		return !(*this == other);
	}

	bool operator==(const Pos& other) const {
		return x == other.x && y == other.y;
	}
};

enum ErrorCode
{
	InvalidSourceEmpty = 11,
	InvalidSourceOccupiedByOpponent = 12,
	InvalidDestinationOccupiedBySameColor = 13,
	InvalidMove = 21,
	InvalidMoveCausesCheck = 31,
	OpponentInCheck = 41,
	ValidMove = 42
};