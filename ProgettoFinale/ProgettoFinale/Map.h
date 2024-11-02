//Gianluca Caregnato
#ifndef Map_h
#define Map_h

#include <iostream>
#include "Pos.h"
#include "ControlMap.fwd.h"
#include "ControlMap.h"

class Map {

protected:

	static const int row = 12; //numero righe della mappa
	static const int col = 12; //numero colonne della mappa
	char map[row][col]; //migliorabile utilizzando dei parametri direttamente dentro al costruttore!!

	// funzione per scrivere all'interno della matrice
	void write(Pos p, char c) { map[p.getRow()][p.getCol()] = c; };
	
public:

	Map(); //costruttore: riempie la matrice map di ' '

	char at(Pos p)const { return map[p.getRow()][p.getCol()]; }; //ritorna il char nella posizione passata per argomento
	char at(int i, int j)const { return map[i][j]; }; //ritorna il char nella posizione passata per argomento
	static int getRow() { return row; }; //ritorna la dimensione della mappa in particolare il numero di righe
	static int getCol() { return col; }; //ritorna la dimensione della mappa in particolare il numero di colonne
	
	std::string mapToString()const;
};

std::ostream& operator<<(std::ostream&, const Map&); //overload dell'operatore di stampa


#endif