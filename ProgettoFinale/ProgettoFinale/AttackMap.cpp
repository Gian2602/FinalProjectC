//Gianluca Caregnato
#include "AttackMap.h"

ControlAttack* AttackMap::CreateController() {

	ControlAttack* ctrl = new ControlAttack(this);

	return ctrl;
}

bool AttackMap::subY(Pos p) {

	write(p, 'Y'); //scrive nella posizione p il char Y
	return true;
}

bool AttackMap::hit(Pos p, bool b) {

	//nel caso la barca venga colpita viene segnato con X nel caso venga mancata O
	if (b)
		write(p, 'X');
	else
		write(p, 'O');

	return true;

}

bool AttackMap::replace(char c) { //funzione utile per cancellare O Y e X

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] == c) 
				map[i][j] = ' ';
		}
	}
	return true;
}

