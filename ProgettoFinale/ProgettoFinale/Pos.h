#ifndef Pos_h
#define Pos_h

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

class Pos {

private:
    int row;
    int col;
public:
    Pos(std::string);                            // costruttore della classe, va a dividere e salvare le due coordinate
    Pos(int = 1, int = 1);

    int getRow()const { return row; };
    int getCol()const { return col; };

	std::string getPos()const;

	bool operator==(const Pos&);

};

namespace PUtil {
	int charToInt(char p);
	char intToChar(int i);
	int distance(Pos p1, Pos p2);
}

class PosException : std::exception {

private:
	const char* msg;
public:
	PosException(const char* msg) : msg(msg) {}
	const char* what() const { return msg; }
};

#endif