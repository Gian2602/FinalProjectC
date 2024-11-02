//Rocchegiani Fabrizio

#include "Submarine.h"
#include "Sheet.h"

Submarine::Submarine(Pos coordinates1, Pos coordinates2, int lenght, int range, char shipChar)
{
	this->Ship::Ship(coordinates1, coordinates2, lenght, range, shipChar);
}

Submarine::Submarine(int x1, int y1, int x2, int y2, int lenght, int range, char shipChar) {
	this->Submarine::Submarine(Pos(x1, y1), Pos(x2, y2), lenght, range, shipChar);
}

int Submarine::mainAction(Pos target, Sheet* mySheet, Sheet* opSheet) {
	Ship* shipToSpot;
	//utilizzo la funzione per il movimento auto-orientato nella versione attuale:
	getCenter().setCoordinates(target);
	for (int i = getCenter().getCoordinates().getRow() - getRange(); i < getCenter().getCoordinates().getRow() + getRange(); i++)
		for (int j = getCenter().getCoordinates().getCol() - getRange(); j < getCenter().getCoordinates().getCol() + getRange(); j++)
			if (isInRange(Pos(j, i)) && (!isThisShip(Pos(j, i)))) {
				shipToSpot = opSheet->getShipByPos(Pos(j,i));
				if (shipToSpot != nullptr)
					mySheet->ctrlatk->subY(Pos(j,i));
			}
	return 1;
}