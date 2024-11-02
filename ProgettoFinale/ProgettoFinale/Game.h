// Bino Matteo

#ifndef Game_H
#define Game_H
//#pragma message("Top in: " __FILE__)
#include "PlacementGameState.h"
#include "Sheet.h"
#include "Human.h"
#include "Computer.h"
#include "LogManipulator.h"
//#pragma message("Before class in: " __FILE__)

//gestisce il funzionamento del gioco attraverso vari stati e funzioni di aggiornamento
class Game
{
private:

	GameState* state;	//stato corrente della partita
	bool isRunning;		//variabile che mantiene attivo il while loop
	unsigned int elapsedTurns;	//conta i turni trascorsi
	const unsigned int max_turns = 30;	//turni massimi

	Sheet *s1, *s2;	//informazioni di ogni giocatore
	Sheet* currentSheet;
	Sheet* opponentSheet;

	LogManipulator log;

	void update();		//aggiorna il gioco in baso allo stato in cui si trova
	void draw();		//disegna la partita in base allo stato in cui si trova
public:
	Game(char p1 = 'c', char p2 = 'c'); //di default si ha una partita fra due computer
	~Game();
	void start(); //fa partire il gioco con lo stato PlacementGameState
	void startInState(GameState* newState);	//fa partire il gioco in uno stato arbitrario
	void loop();					//loop classico del gioco
	GameState* updateState(GameState* newState = nullptr);	//aggiorna lo stato del gioco

	bool setIsRunning(bool newState); //ritorna il vecchio stato di isRunning
	void addElapsedTurn();	//aggiunge un turno ai turni trascorsi
	bool isMatchFinished();	//verifica se la partita è terminata
	void end();	//operazioni di terminazione della partita
	Sheet* getCurrentSheet();
	Sheet* getOpponentSheet();
	void switchTurn();	//cambia giocatore attivo
	LogManipulator& getLog();
};

#endif