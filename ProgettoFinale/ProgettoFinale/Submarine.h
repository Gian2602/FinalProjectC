//Rocchegiani Fabrizio

#ifndef Submarine_h
#define Submarine_h

#include "Ship.h"

class Submarine : public Ship
{
	public:
		static const int SUBMARINE_LENGHT = 1;
		static const int DEFAULT_RANGE = 2;
		static const char SUBMARINE_CHAR = 'e';

		//costruttori:
		Submarine(int x1, int y1, int x2, int y2, int lenght = SUBMARINE_LENGHT, int range = DEFAULT_RANGE, char shipChar = SUBMARINE_CHAR);
		Submarine(Pos coordinates1 = Pos(), Pos coordinates2= Pos(), int lenght = SUBMARINE_LENGHT, int range = DEFAULT_RANGE, char shipChar = SUBMARINE_CHAR);

		int mainAction(Pos target, Sheet* mySheet, Sheet* opSheet);
};

#endif // !Submarine_h