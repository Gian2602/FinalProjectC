//Bino Matteo

#ifndef Player_H
#define Player_H

#include <string>
#include <vector>
#include "Ship.h"

class Player
{
private:
	std::string name;
public:
	Player(std::string name);
	virtual std::string getPositioningInput(const int length = 1) = 0; //chiede l'input per il piazzamento delle navi
	virtual std::string getPlayInput(std::vector<Ship*>* ships = nullptr) = 0; //chiede l'input per la fase di gioco
	std::string getName() const { return name; } //ritorna il nome del giocatore
};

std::ostream& operator<<(std::ostream& os, const Player& player);

#endif