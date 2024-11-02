//Bino Matteo

#ifndef Sheet_H
#define Sheet_H
#pragma message("Top in: " __FILE__)
#include "DefenceMap.h"
#include "AttackMap.h"

#include "Player.fwd.h"
#include "Player.h"
#pragma message("Before class in: " __FILE__)
class Sheet
{
private:
	Player* player; 

	AttackMap atkmap; //mappa di attacco del giocatore
	DefenceMap defmap; //mappa di difesa del giocatore

	std::vector<Ship*> ships; //vettore di navi del giocatore
public:
	const unsigned int MaxShips = 8;
	ControlAttack* ctrlatk; //gestore della mappa di attacco sviluppato con il pattern Iterator
	ControlDefence* ctrldef; //gestore della mappa di difesa sviluppato con il pattern Iterator

	Sheet(Player* player = nullptr);
	~Sheet();

	void setPlayer(Player* player);
	Player* getPlayer() { return player; };
	void addShip(Ship* ship);
	std::vector<Ship*>* getShips();
	Ship* getShipByPos(Pos pos); //ritorna la nave se c'è un suo componente nella posizione passata
	Ship* selectShipByCenter(Pos pos); //ritorna la nave se la posizione passata è il suo centro
	bool removeSunkShip(); //elimina una nave affondata
	unsigned int placedShips(); //ritorna la dimensione del vettore di navi
	std::string getPlayerPositioningInput(const int length); //chiede l'input di piazzamento all'utente (umano o robot)
	std::string getPlayerPlayInput(); //chiede l'input di gioco all'utente (umano o robot)
};

#endif