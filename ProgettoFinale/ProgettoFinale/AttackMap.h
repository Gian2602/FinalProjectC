//Gianluca Caregnato
#ifndef AttackMap_h
#define AttackMap_h

#include "ControlAttack.fwd.h"
#include "ControlAttack.h"
#include "Map.h"

class AttackMap: public Map {

private:

	bool replace(char);

public:

	AttackMap() : Map() {};

	ControlAttack* CreateController();

	bool subY(Pos); //funzione per scrivere le Y

	//funzioni per eliminare X O e Y
	bool deleteX() { return replace('X'); };
	bool deleteO() { return replace('O'); };
	bool deleteY() { return replace('Y'); };

	bool hit(Pos, bool); //funzione chiamata quando una corazzata spara per segnare X e O 
};

#endif
