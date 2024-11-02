//Gianluca Caregnato
#include "ControlMap.h"



bool ControlMap::checkBorder(Pos pos)const { //funzione che controlla che la posizione data sia dentro ai bordi

	if (pos.getCol() >= 0 && pos.getCol() < col)
		if (pos.getRow() >= 0 && pos.getRow() < row)
			return true;


	throw std::exception("Le coordinate sono fuori dalla mappa");
	
}

