//Bino Matteo

#ifndef GameState_H
#define GameState_H
//#pragma message("Top in: " __FILE__)
#include "Game.fwd.h"	//dichiara la classe Game
//#pragma message("Before class in: " __FILE__)
//classe base che rappresenta lo stato del gioco
class GameState
{
protected:
	Game* game;		//puntatore per tenere traccia del gioco di appartenenza, dato che lo stato va a modificare le variabili del gioco
public:
	GameState(Game* game);	//lo stato esiste solo se esiste il gioco
	virtual void onEnter() = 0;	//procedura di ingresso nello stato
	virtual void update() = 0;	//aggiornamento del gioco in base allo stato
	virtual void draw() = 0;	//disegno del gioco in base allo stato
	virtual void onExit() = 0;	//procedura di uscita dallo stato
};

#endif