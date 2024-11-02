#include "Pos.h"

Pos::Pos(std::string str) {

	std::transform(str.begin(), str.end(), str.begin(), ::toupper);

	if(str[0] == 'J' || str[0] == 'K')
		throw PosException("Carattere non valido.");

	row = PUtil::charToInt(str[0]);
	col = atoi(str.substr(1).c_str()) - 1;
}

Pos::Pos(int i, int j) {

	row = i;
	col = j;
}

std::string Pos::getPos()const {

	return PUtil::intToChar(row) + std::to_string(col + 1);
}

bool Pos::operator==(const Pos& obj) {

	if (row == obj.getRow() && col == obj.getCol())
		return true;

	return false;
}

int PUtil::distance(Pos p1, Pos p2) {

	int d1 = p1.getCol() - p2.getCol();
	int d2 = p1.getRow() - p2.getRow();

	if (d1 < 0) 
		d1=d1* (-1);
	if (d2 < 0) 
		d2=d2* (-1);

	return ((int)sqrt((d1 * d1) + (d2 * d2)) + 1);
}

int PUtil::charToInt(char p) {
	if (p >= 'A' && p <= 'Z') {
		int r = 0;
		if (p < 'J') r = (int)((p - 'A'));
		else r = (int)((p - 'A' - 2));
		return r;
	}
	throw PosException("Carattere non valido.");
}

char PUtil::intToChar(int i) {

	if (i >= 0 && i <= 25) {
		if (i < 9)
			return (char)('A' + i);
		else
			return (char('A' + i + 2));
	}

	throw PosException("Intero non valido");
}