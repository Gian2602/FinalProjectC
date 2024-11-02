//Gianluca Caregnato
#ifndef ControlDefence_h
#define ControlDefence_h

#include "ControlMap.h"
#include "DefenceMap.fwd.h"
#include "Ship.fwd.h"
#include "Ship.h"

class ControlDefence : public ControlMap {

private:

	DefenceMap* map;

	bool ScanArea(Ship*)const;

public:

	ControlDefence(DefenceMap* obj) ;

	DefenceMap* getMap()const { return map; };
	
	bool insertBoat(Ship*); //inserimento della barca
	bool moveBoat(Ship*); //sposto la barca

	bool repairShip(Ship*); //ripara la barca
	bool deleteShip(Ship*); //elimina dalla mappa la barca
	bool handleHit(Pos,Ship*); //Nel caso venga colpita una barca va ad aggiornare la sua stampa
};

void swapIfGreater(Pos&, Pos&);//funzione che mi rende la prima coordinata sempre minore della seconda (quindi in alto o a sinistra)

std::ostream& operator<<(std::ostream&, const ControlDefence&); //overload dell'operatore di stampa

#endif