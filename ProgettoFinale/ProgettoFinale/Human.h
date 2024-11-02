//Bino Matteo

#ifndef Human_H
#define Human_H

#include "Player.h"
#include "Pos.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>

class Human :
    public Player
{
public:
    Human(std::string name);
    std::string getPositioningInput(const int length);
    std::string getPlayInput(std::vector<Ship*>* ships = nullptr);
    std::string getInput();
};

namespace HUtils {
    std::vector<std::string> divideString(std::string input, char separator = ' ');
}

#endif