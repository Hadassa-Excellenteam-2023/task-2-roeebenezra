#pragma once
#include <map>
#include "Pieces/Piese.h"

using std::map;

class Piece;

template<typename T>
class Factory {
public:
	using pFnc = unique_ptr<T>(*)();

	static bool registerit(const char& name, pFnc);
	
	static unique_ptr<T> create(const char& name);

private:
	static auto& getMap() {
		static map<char, pFnc> map;
		return map;
	}
};


template<typename T>
bool Factory<T>::registerit(const char& name, pFnc f) {
	Factory::getMap().emplace(name, f);
	return true;
}


template<typename T>
unique_ptr<T> Factory<T>::create(const char& name) {
	auto it = Factory::getMap().find(name);
	if (it == Factory::getMap().end())
		return nullptr;

	return it->second();
}