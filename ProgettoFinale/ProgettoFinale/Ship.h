//Rocchegiani Fabrizio

#ifndef Ship_h
#define Ship_h

#include "Component.h"
#include "Sheet.fwd.h"
#include <vector>
#include <cctype>

class Ship
{
	private:
		std::vector<Component> cmps;																											//vettore contenente tutti i pezzi della nave.
		/*
		Idee della prima versione, ancora utili per alcuni processi logici:
		Component* cmps;																														//vettore contenente tutti i pezzi della nave.
		Component* stern;																														//puntatore alla poppa della nave.
		Component* bow;																															//puntatore alla prua della nave.
		Component* center;																														//puntatore al centro della nave.
		*/
		int range;																																//raggio d'azione di una nave.
		char shipChar;																															//carattere che identifica la nave sulla griglia (versione attuale).
	public:
		static const int DEFAULT_RANGE = 0;
		static const int DEFAULT_DIM = 1;
		
		//costruttori:
		Ship(int x1, int y1, int x2, int y2, int lenght = DEFAULT_DIM, int range = DEFAULT_RANGE, char shipChar = ' ');
		Ship(Pos coordinates1 = Pos(), Pos coordinates2 = Pos(), int lenght = DEFAULT_DIM, int range = DEFAULT_RANGE, char shipChar = ' ');

		virtual int mainAction(Pos target, Sheet* mySheet, Sheet* opSheet);																		//ogni nave avrà la sua azione principale, in future versioni del codice il contenuto di questa funzione potrebbe essere modificato.

		int moveShip(Pos newCenter);																											//l'equivalente di un setCmps().

		int moveVertical(Pos newCenter, Pos stern, Pos bow);																					//se una barca è verticale, questa viene traslata nel nuovo centro.
		int moveVertical(Pos newCenter, int stern, int bow);																					//sposto una barca verticalmente fornendo la sua direzione, tramite i due valori interi e l'utilizzo della funzione SUtil::ShipDirection.
		int moveHorizontal(Pos newCenter, Pos stern, Pos bow);																					//se una barca è orizzontale, questa viene traslata nel nuovo centro.
		int moveHorizontal(Pos newCenter, int stern, int bow);																					//sposto una barca orizzontalmente fornendo la sua direzione, tramite i due valori interi e l'utilizzo della funzione SUtil::ShipDirection.
		int orientatedMovement(Pos newCenter, Pos stern, Pos bow);

		bool isInRange(Pos target);																												//verifica che l'azione venga fatta all'interno del raggio d'azione della nave.
		bool isSunk();																															//verifica se la nave è affondata.
		bool isThisShip(Pos target);																											//verifica se la nave alla coordinata data è questa.
		int shipLenght() ;																														//ritorna la lunghezza della nave.

		//funzioni getters della nave:
		//Component* getCmps();																													//ritorna il puntatore ai componenti della nave.
		std::vector<Component>* getCmps();																										//ritorna il puntatore ai componenti della nave.
		Component getCmpsAt(Pos target);
		Component getStern();																													//ritorna il puntatore alla poppa (posteriore) della nave.
		Component getBow();																														//ritorna il puntatore alla prua (anteriore) della nave.
		Component getCenter();																													//ritorna il puntatore al centro della nave.
		char getShipChar(Pos target);																											//ritorna il carattere della nave nel dato punto.
		int getRange() const;																													//ritorna il raggio d'azione della nave.
};

//namespace contenente funzioni utili utilizzabili anche all'esterno della classe Ship:
namespace SUtil {
	int shipOrientation(Pos p1, Pos p2);
	int shipOrientation(Ship s);
	int shipDirection(int d1, int d2);
}

//eccezione personalizzata della classe Ship:
class ShipException : std::exception {
	private:
		const char* msg;
	public:
		ShipException(const char* msg) : msg(msg) {}
		const char* what() const { return msg; }
};

#endif // !Ship_h