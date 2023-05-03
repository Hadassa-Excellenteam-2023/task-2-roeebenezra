#pragma once
#include <map>
#include "Pieces/Piese.h"

using std::map;

class Piece;

template<typename T>
class Factory {
public:
    using creationFunc = unique_ptr<T>(*)();

    static bool registerit(const char& name, creationFunc f) {
        getMap().emplace(name, f);
        return true;
    }

    static unique_ptr<T> create(const char& name) {
        auto map = getMap();
        auto it = map.find(name);
        if (it == map.end())
            return nullptr;

        return it->second();
    }

private:
    static auto& getMap() {
        static map<char, creationFunc> map;
        return map;
    }
};
