//Rocchegiani Fabrizio

#include "Ship.h"
#include "Sheet.h"

Ship::Ship(Pos coordinates1, Pos coordinates2, int lenght, int range, char shipChar) {
	//nella versione corrente, non viene gestito il caso di una nave composta da un numero pari di componenti:
	if (lenght < 1 || lenght % 2 == 0)
		throw ShipException("Dati inseriti non corretti: dimensione barca non valida.");
	if (PUtil::distance(coordinates1, coordinates2) != lenght)
		throw ShipException("Dati inseriti non corretti: dimensioni e punti non combaciano.");
	if (lenght == 1)
		cmps.push_back(coordinates1);
	if (lenght > 1) {
		cmps = std::vector<Component>(lenght);
		orientatedMovement(Pos((coordinates1.getRow() + coordinates2.getRow()) / 2, (coordinates1.getCol() + coordinates2.getCol()) / 2), coordinates1, coordinates2);
	}
	this->range = range;
	this->shipChar = shipChar;
}

Ship::Ship(int x1, int y1, int x2, int y2, int lenght, int range, char shipChar) {
	this->Ship::Ship(Pos(y1, x1), Pos(y2, x2), lenght, range, shipChar);
}

int Ship::mainAction(Pos target, Sheet* mySheet, Sheet* opSheet) {
	//una nave di base non apporta alcuna modifica, risultato dell'azione nullo:
	return 0;
}

char Ship::getShipChar(Pos target) {
	int i = 0;
	while (i < shipLenght()) {
		if (cmps[i].getCoordinates().getCol() == target.getCol() && cmps[i].getCoordinates().getRow() == target.getRow()) {
			if (cmps[i].isDes())
				return shipChar;
			else
				return std::toupper(shipChar);
		}
		i++;
	}
	throw ShipException("Il punto cercato non appartiene a questa nave.");
}

bool Ship::isInRange(Pos target) {
	if ((target.getRow() >= getCenter().getCoordinates().getRow() - range && target.getRow() <= getCenter().getCoordinates().getRow() + range) && (target.getCol() >= getCenter().getCoordinates().getCol() - range && target.getCol() <= getCenter().getCoordinates().getCol() + range))
		return true;
	return false;
}

bool Ship::isSunk() {
	int i = 0;
	while (i < shipLenght()) {
		if (!cmps[i].isDes())
			return false;
		i++;
	}
	return true;
}

bool Ship::isThisShip(Pos target) {
	int i = 0;
	while (i < shipLenght()) {
		if (cmps[i].getCoordinates().getCol()==target.getCol() && cmps[i].getCoordinates().getRow() == target.getRow())
			return true;
		i++;
	}
	return false;
}

int Ship::moveShip(Pos newCenter) {
	if (shipLenght() == 1) {
		this->getCenter().setCoordinates(newCenter);
		return 2;
	}
	if (shipLenght() > 1) {
		//if (isInRange(newCenter))	--> previsto l'utilizzo per futuri aggiornamenti.
			return orientatedMovement(newCenter, this->getStern().getCoordinates(), this->getBow().getCoordinates());
	}
	throw ShipException("Nave posizionata in maniera non corretta, impossibile spostarla.");
}

int Ship::orientatedMovement(Pos newCenter, Pos stern, Pos bow) {
	switch (SUtil::shipOrientation(stern, bow)) {
		//nave orizzontale:
		case 0:
			return moveHorizontal(newCenter,stern.getCol(), bow.getCol());
			//return moveHorizontal(newCenter, stern, bow);
		break;
		//nave verticale:
		case 1:
			return moveVertical(newCenter,stern.getRow(), bow.getRow());
			//return moveVertical(newCenter, stern, bow);
		break;
		default:
			throw ShipException("Posizionamento della nave indecifrabile con le informazioni attuali.");
		break;
	}
}

//nave verticale, varia la riga:
int Ship::moveVertical(Pos newCenter, Pos stern, Pos bow) {
	return moveVertical(newCenter, stern.getRow(), bow.getRow());
}

//nave verticale, varia la riga:
int Ship::moveVertical(Pos newCenter, int stern, int bow) {
	Pos newStern;
	//nave rivolta verso l'alto:
	if (SUtil::shipDirection(stern, bow) == 1) {
		newStern = Pos(newCenter.getRow() + (shipLenght() / 2), newCenter.getCol());
		for (int i = 0; i < shipLenght(); i++)
			cmps[i] = Component(newStern.getRow() - i, newStern.getCol());
		return 1;
	}
	//nave rivolta verso il basso:
	if (SUtil::shipDirection(stern, bow) == 0) {
		newStern = Pos(newCenter.getRow() - (shipLenght() / 2), newCenter.getCol());
		for (int i = 0; i < shipLenght(); i++)
			cmps[i] = Component(newStern.getRow() + i, newStern.getCol());
		return 1;
	}
	return -1;
}

//nave orizzontale, varia la colonna:
int Ship::moveHorizontal(Pos newCenter, Pos stern, Pos bow) {
	return moveHorizontal(newCenter,stern.getCol(),bow.getCol());
}

//nave orizzontale, varia la colonna:
int Ship::moveHorizontal(Pos newCenter, int stern, int bow) {
	Pos newStern;
	//nave rivolta verso sx:
	if (SUtil::shipDirection(stern, bow) == 1) {
		newStern = Pos(newCenter.getRow(), newCenter.getCol() + (shipLenght() / 2));
		for (int i = 0; i < shipLenght(); i++)
			cmps[i] = Component(newStern.getRow(), newStern.getCol() - i);
		return 0;
	}
	//nave rivolta verso dx:
	if (SUtil::shipDirection(stern, bow) == 0) {
		newStern = Pos(newCenter.getRow(), newCenter.getCol() - (shipLenght() / 2));
		for (int i = 0; i < shipLenght(); i++)
			cmps[i] = Component(newStern.getRow(), newStern.getCol() + i);
		return 0;
	}
	return -1;
}

int SUtil::shipOrientation(Pos p1, Pos p2) {
	//nave verticale:
	if (p1.getCol() == p2.getCol())
		return 1;
	//nave orizzontale:
	if (p1.getRow() == p2.getRow())
		return 0;
	//caso in cui si è verificato un errore:
	return -1;
}

int SUtil::shipOrientation(Ship s) {
	//nave verticale:
	if (s.getStern().getCoordinates().getCol() == s.getBow().getCoordinates().getCol())
		return 1;
	//nave orizzontale:
	if (s.getStern().getCoordinates().getRow() == s.getBow().getCoordinates().getRow())
		return 0;
	//caso in cui si è verificato un errore:
	return -1;
}

int SUtil::shipDirection(int d1, int d2) {
	//nave rivolta verso sinistra/basso:
	if (d1>d2)
		return 1;
	//nave rivolta verso destra/alto:
	if (d1<d2)
		return 0;
	//caso in cui si è verificato un errore:
	return -1;
}

std::vector<Component>* Ship::getCmps() {
	return &cmps;
}

Component Ship::getCmpsAt(Pos target) {
	int i = 0;
	if (isThisShip(target)) {
		while (i < shipLenght()) {
			if (cmps[i].getCoordinates().getCol() == target.getCol() && cmps[i].getCoordinates().getRow() == target.getRow())
				return cmps[i];
			i++;
		}
	}
	throw ShipException("Nessuna componente della barca nel punto selezionato.");
}

Component Ship::getStern() {
	return cmps[0];
}

Component Ship::getBow() {
	return cmps[shipLenght() - 1];
}

Component Ship::getCenter() {
	return cmps[shipLenght() / 2];
}

int Ship::shipLenght() {
	return (int)cmps.size();
}

int Ship::getRange() const {
	return range;
}