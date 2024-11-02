//Rocchegiani Fabrizio

#ifndef Support_h
#define Support_h

#include "Ship.h"

class Support : public Ship
{
	private:
		int heal;
	public:
		static const int DEFAULT_HEAL = 1;
		static const int SUPPORT_LENGHT = 3;
		static const int DEFAULT_RANGE = 1;
		static const char SUPPORT_CHAR = 's';

		//costruttori:
		Support(int x1, int y1, int x2, int y2, int lenght = SUPPORT_LENGHT, int range = DEFAULT_RANGE, char shipChar = SUPPORT_CHAR, int heal = DEFAULT_HEAL);
		Support(Pos coordinates1 = Pos(), Pos coordinates2 = Pos(), int lenght = SUPPORT_LENGHT, int range = DEFAULT_RANGE, char shipChar = SUPPORT_CHAR, int heal = DEFAULT_HEAL);

		int mainAction(Pos target, Sheet* mySheet, Sheet* opSheet);
		int healShip(Ship* s);
};

#endif // !Support_h