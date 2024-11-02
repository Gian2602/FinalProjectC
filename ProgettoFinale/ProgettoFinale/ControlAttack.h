//Gianluca Caregnato
#ifndef ControlAttack_h
#define ControlAttack_h

#include "AttackMap.fwd.h"
#include "AttackMap.h"
#include "ControlMap.h"


class ControlAttack: public ControlMap {

private:

	AttackMap* map;

public:

	bool subY(Pos); //funzione che scrive le Y del sottomarino

	ControlAttack(AttackMap* obj);

	AttackMap* getMap()const { return map; };
	
	bool deleteX(); //elimina le X dalla mappa
	bool deleteO(); //elimina i O dalla mappa
	bool deleteY(); //elimina le Y dalla mappa

	bool hit(Pos, bool); //funzione chiamata quando una corazzata spara
};

std::ostream& operator<<(std::ostream&, const ControlAttack&); //overload dell'operatore di stampa


#endif