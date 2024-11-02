//Bino Matteo

#include "Sheet.h"

Sheet::Sheet(Player* player)
{
	this->player = player;

	this->atkmap = AttackMap(); //crea le mappe di attacco e difesa
	this->defmap = DefenceMap();
	this->ctrlatk = atkmap.CreateController(); //crea i gestori associati alle due mappe
	this->ctrldef = defmap.CreateController();

	this->ships = std::vector<Ship*>(); //crea il vettore di navi
}

Sheet::~Sheet()
{
	ships.clear();	//svuota il vettore di navi
	delete ctrlatk; //elimina i controllori (sono in mem dinamica)
	delete ctrldef;
	//delete atkmap; //elimina le mappe (sono in mem dinamica)
	//delete defmap;
	delete player; //elimina il giocatore (è in mem dinamica)

}

void Sheet::setPlayer(Player* player)
{
	this->player = player;
}

void Sheet::addShip(Ship* ship)
{
	ships.push_back(ship);
}

std::vector<Ship*>* Sheet::getShips()
{
	return &this->ships;
}

Ship* Sheet::getShipByPos(Pos pos)
{
	for (int i = 0; i < this->ships.size(); i++) { //ispeziona ogni nave (se non ne trova nessuna)
		if (ships[i]->isThisShip(pos)) return ships[i];
	}

	return nullptr;
}

Ship* Sheet::selectShipByCenter(Pos pos)
{
	for (int i = 0; i < ships.size(); i++) { //ispeziona ogni nave (se non ne trova nessuna)
		if (ships[i]->getCenter().getCoordinates() == pos) return ships[i];
	}

	return nullptr;
}

bool Sheet::removeSunkShip()
{
	//elimina una sola nave (se affondata)
	//in questo caso va bene eliminarne una sola perchè in un turno può esserne eliminata al massimo una
	bool found = false;
	for (int i = 0; !found && i < ships.size(); i++) {
		if (ships[i]->isSunk()) {
			found = true;
			ships.erase(ships.begin()+i);
		}
	}

	return found;
}

unsigned int Sheet::placedShips()
{
	return this->ships.size();
}

std::string Sheet::getPlayerPositioningInput(const int length)
{
	return this->player->getPositioningInput(length); //richiede l'input di piazzamento del player
}

std::string Sheet::getPlayerPlayInput()
{
	return this->player->getPlayInput(&this->ships); //richiede l'input di gioco al player
}
