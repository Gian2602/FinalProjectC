//Rocchegiani Fabrizio

#ifndef Cruiser_h
#define Cruiser_h

#include "Ship.h"

class Cruiser : public Ship
{
	private:
		int dmg;
	public:
		static const int DEFAULT_DMG = 1;
		static const int CRUISER_LENGHT = 5;
		static const char CRUISER_CHAR = 'c';
		
		//costruttori:
		Cruiser(int x1, int y1, int x2, int y2, int lenght = CRUISER_LENGHT, int range = DEFAULT_RANGE, char shipChar = CRUISER_CHAR, int dmg=DEFAULT_DMG);
		Cruiser(Pos coordinates1 = Pos(), Pos coordinates2 = Pos(), int lenght = CRUISER_LENGHT, int range = DEFAULT_RANGE, char shipChar = CRUISER_CHAR, int dmg = DEFAULT_DMG);

		int mainAction(Pos target, Sheet* mySheet, Sheet* opSheet);
};

#endif // !Cruiser_h