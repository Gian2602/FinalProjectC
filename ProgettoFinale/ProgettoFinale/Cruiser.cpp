//Rocchegiani Fabrizio

#include "Cruiser.h"
#include "Sheet.h"

Cruiser::Cruiser(Pos coordinates1, Pos coordinates2, int lenght, int range, char shipChar, int dmg)
{
	this->Ship::Ship(coordinates1,coordinates2,lenght,range,shipChar);
	this->dmg = dmg;
}

Cruiser::Cruiser(int x1, int y1, int x2, int y2, int lenght, int range, char shipChar, int dmg) {
	this->Cruiser::Cruiser(Pos(x1,y1),Pos(x2,y2),lenght,range,shipChar,dmg);
}

int Cruiser::mainAction(Pos target, Sheet* mySheet, Sheet* opSheet) {
	Ship* shipToAttack = opSheet->getShipByPos(target);
	if (shipToAttack != nullptr) {
		shipToAttack->getCmpsAt(target).setActHealth(shipToAttack->getCmpsAt(target).getActHealth() - this->dmg);
		mySheet->ctrlatk->hit(target,true);
		opSheet->ctrldef->handleHit(target,shipToAttack);
		return 1;
	}
	mySheet->ctrlatk->hit(target, false);
	return 0;
}