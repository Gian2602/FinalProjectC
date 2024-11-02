//Gianluca Caregnato
#ifndef DefenceMap_h
#define DefenceMap_h

#include "ControlDefence.fwd.h"
#include "ControlDefence.h"
#include "Ship.fwd.h"
#include "Ship.h"

class DefenceMap : public Map {

private:

	bool writeArea(Ship*); //Funzione che scrive nella mappa

public:

	DefenceMap() : Map() {};

	ControlDefence* CreateController();
	
	bool insertBoat(Ship*); //funzione per inserire una barca all'inizio del gioco
	bool moveBoat(Ship*); //funzione per spostare una barca

	bool repairShip(Ship*); //funzione per riparare la barca
	bool deleteShip(Ship*); //funzione per eliminare la barca dalla mappa quando viene distrutta
	bool handleHit(Pos, Ship*); //funzione chiamata quando una barca viene colpita per aggiornare lo stato
};


#endif