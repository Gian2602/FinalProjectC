//Gianluca Caregnato
#include "ControlDefence.h"
#include "DefenceMap.h"
ControlDefence::ControlDefence(DefenceMap* obj) : map{ obj } {

	row = obj->getRow();
	col = obj->getCol();
}

bool ControlDefence::insertBoat(Ship* s) {
	
	//controllo se la barca ci sta nella mappa e che non ci siano altre navi dove voglio andare ad inserire la barca
	if (checkBorder(s->getStern().getCoordinates()) && checkBorder(s->getBow().getCoordinates())  && ScanArea(s)) {

		//Se nella mappa non ci sono navi allora posso far inserire la barca DefenceMap
		return map->insertBoat(s); 
	}
	return false;
}

bool ControlDefence::moveBoat(Ship* s) {

	//Faccio sempre tutti i controlli delle coordinate e per verificare che la nave non si sovrapponga con altre
	if (checkBorder(s->getStern().getCoordinates()) && checkBorder(s->getBow().getCoordinates()) && ScanArea(s)) {
			
		//se tutto va bene lascio a DefenceMap il compito di spostarla
		return map->moveBoat(s);
	}
	return false;
}

bool ControlDefence::ScanArea(Ship* s) const { //restituisce true se dentro alla mappa tra le coordinate non ci sono altre navi
	//prendo le coordinate di poppa e prua della nave
	Pos a = Pos(s->getStern().getCoordinates());
	Pos b = Pos(s->getBow().getCoordinates());

	//per comodità inverto le coordinate in modo da avere che a e' piu` a sinistra/piu` in alto
	swapIfGreater(a, b);
	for (int i = 0; i < s->shipLenght(); i++) {
		//capisco come e` orientata la nave in modo da poter compiere le operazioni corrette
		if (SUtil::shipOrientation(a,b) == 0) {
			if (map->at(a.getRow(), a.getCol() + i ) != ' ') { 
				throw std::exception("Non puoi sovrapporre due navi"); //nel caso in cui ci sia una nave in quella posizione restituisce false
			}
		}
		else {
			if (map->at(a.getRow() + i, a.getCol()) != ' ') {
				throw std::exception("Non puoi sovrapporre due navi"); //nel caso in cui ci sia una nave in quella posizione restituisce false
			}
		}
	}
	return true;

}

bool ControlDefence::repairShip(Ship* s) {

	//non occorre fare ulteriori controlli nel caso in cui si voglia riparare la nave quindi passo il comando a DefenceMap
	return map->repairShip(s);
}

bool ControlDefence::deleteShip(Ship* s) {

	//non occorre fare ulteriori controlli nel caso in cui si voglia eliminare la nave passo quindi il comando a DefenceMap
	return map->deleteShip(s);
}

bool ControlDefence::handleHit(Pos p, Ship* s) {

	//chiamo la funzione di map che mi va a scrivere direttamente dentro alla mappa
	return map->handleHit(p,s);
}


void swapIfGreater(Pos& a, Pos& b) {

	if ((a.getRow() - b.getRow()) == 0) { //la nave è orrizzontale

		if (a.getCol() > b.getCol()) { //nel caso in cui a abbia un valore maggiore di b faccio lo swap
			Pos temp = a;
			a = b;
			b = temp;
		}

	}
	else if ((a.getCol() - b.getCol()) == 0) { //quindi la nave è verticale

		if (a.getRow() > b.getRow()) { //nel caso in cui a abbia un valore maggiore di b faccio lo swap
			Pos temp = a;
			a = b;
			b = temp;
		}
		
	}
}

std::ostream& operator<<(std::ostream& os, const ControlDefence& obj) {

	os << *obj.getMap();
	return os;

}