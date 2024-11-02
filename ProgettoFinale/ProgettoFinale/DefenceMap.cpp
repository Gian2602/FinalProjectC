//Gianluca Caregnato
#include "DefenceMap.h"

bool DefenceMap::insertBoat(Ship* s) {

	return writeArea(s);
}

bool DefenceMap::moveBoat(Ship* s) {
	
	return writeArea(s);
}

bool DefenceMap::repairShip(Ship* s) {

	return writeArea(s);

}

bool DefenceMap::deleteShip(Ship* s) {

	//Prendo due le Pos di poppa e prua e faccio lo swap
	Pos a = Pos(s->getStern().getCoordinates());
	Pos b = Pos(s->getBow().getCoordinates());
	swapIfGreater(a, b);

	//ciclo che aggiorna la mappa sovrascrivendo i char della barca con degli ' '
	for (int i = 0; i < s->shipLenght(); i++) {
		if (SUtil::shipOrientation(a, b) == 0) {
			map[a.getRow()][a.getCol() + i] = ' ';
		}
		else {
			map[a.getRow() + i][a.getCol()] = ' ';
		}
	}
	return true;
}

bool DefenceMap::handleHit(Pos p, Ship* s) {

	map[p.getRow()][p.getCol()] = s->getShipChar(p); //aggiorna lo stato della barca
	return true;
}

bool DefenceMap::writeArea(Ship* s) {

	//Prendo due le Pos di poppa e prua e faccio lo swap
	Pos a = Pos(s->getStern().getCoordinates());
	Pos b = Pos(s->getBow().getCoordinates());
	swapIfGreater(a, b);

	//Vado ad aggiornare la mappa scrivendo i char della barca restituiti da getShipChar()
	for (int i = 0; i < s->shipLenght(); i++) {
		if (SUtil::shipOrientation(a, b) == 0) {
			map[a.getRow()][a.getCol() + i] = s->getShipChar(Pos(a.getRow(), a.getCol() + i));
		}
		else {
			map[a.getRow() + i][a.getCol()] = s->getShipChar(Pos(a.getRow() + i, a.getCol()));
		}
	}
	return true;


}

ControlDefence* DefenceMap::CreateController() {

	ControlDefence* ctrl = new ControlDefence(this);

	return ctrl;
}

