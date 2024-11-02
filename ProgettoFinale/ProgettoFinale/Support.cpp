//Rocchegiani Fabrizio

#include "Support.h"
#include "Sheet.h"

Support::Support(Pos coordinates1, Pos coordinates2, int lenght, int range, char shipChar, int heal)
{
	this->Ship::Ship(coordinates1, coordinates2, lenght, range, shipChar);
	this->heal = heal;
}

Support::Support(int x1, int y1, int x2, int y2, int lenght, int range, char shipChar, int heal) {
	this->Support::Support(Pos(x1, y1), Pos(x2, y2), lenght, range, shipChar, heal);
}

int Support::mainAction(Pos target, Sheet* mySheet, Sheet* opSheet) {
	Ship* shipToHeal;
	//utilizzo la funzione per il movimento auto-orientato nella versione attuale:
	orientatedMovement(target,getStern().getCoordinates(), getBow().getCoordinates());
	for (int i = getCenter().getCoordinates().getRow() - getRange(); i < getCenter().getCoordinates().getRow() + getRange(); i++)
		for (int j = getCenter().getCoordinates().getCol() - getRange(); j < getCenter().getCoordinates().getCol() + getRange(); j++)
			if (isInRange(Pos(j, i)) && (!isThisShip(Pos(j, i)))) {
				shipToHeal = mySheet->getShipByPos(Pos(j, i));
				healShip(shipToHeal);
				mySheet->ctrldef->repairShip(shipToHeal);
			}
	return 1;
}

int Support::healShip(Ship* s) {
	if (s != nullptr) {
		for (int i = 0; i < s->shipLenght(); i++)
			s->getCmps()->at(i).setActHealth(s->getCmps()->at(i).getActHealth() + this->heal);
		return 1;
	}
	return 0;
}