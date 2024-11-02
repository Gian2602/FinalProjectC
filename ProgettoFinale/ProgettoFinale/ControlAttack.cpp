//Gianluca Caregnato
#include "ControlAttack.h"

ControlAttack::ControlAttack(AttackMap* obj) : map{ obj } {

	//mi salvo il numero di righe e di colonne della mappa
	row = obj->getRow(); 
	col = obj->getCol();
}



bool ControlAttack::subY(Pos p) {

	if (checkBorder(p)) {

		//nel caso la posizione sia dentro alla mappa vado a stampare la Y
		return map->subY(p);
	}
	
	return false;
}

bool ControlAttack::deleteX() {
	
	return  map->deleteX();
}

bool ControlAttack::deleteO() {

	return map->deleteO();
}

bool ControlAttack::deleteY() {

	return map->deleteY();
}

bool ControlAttack::hit(Pos p, bool b) {
	
	if (checkBorder(p)) {

		//nel caso la posizione sia dentro alla mappa passo il comando a AttackMap
		return map->hit(p, b);
	}
	return false;
}

std::ostream& operator<<(std::ostream& os, const ControlAttack& obj) {

	os << *obj.getMap();
	return os;

}