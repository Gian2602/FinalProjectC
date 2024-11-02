//Gianluca Caregnato
#ifndef Computer_H
#define Computer_H

#include "Player.h"
#include "Ship.h"
#include "Map.h"
#include <time.h>
#include <random>

class Computer :
    public Player
{
private:
    unsigned int placedShips;

public:
    Computer(std::string name, unsigned int placedShips = 0);

    std::string getPositioningInput(const int length); //Funzione che posiziona una nave casualmente
    std::string getPlayInput(std::vector<Ship*>* ships = nullptr); //funzione che sceglie una nave e ne esegue l'azione
};

#endif
