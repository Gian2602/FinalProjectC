//Gianluca Caregnato
#ifndef ControlMap_h
#define ControlMap_h

#include "Map.fwd.h"
#include "Map.h"
#include "Pos.h"
#include <iostream>


class ControlMap {

protected: 

	//salvo le due variabili row e col
	int row;
	int col;

	bool checkBorder(Pos)const; //Funzione che controlla i bordi della mappa

};

#endif