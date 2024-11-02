//Bino Matteo

#include "Game.h"

int main(int argc, char** argv) {
	
	Game* game = nullptr;
	
	if (argc > 1) {
		if ((argv[1][0] == 'p' || argv[1][0] == 'c') && (argv[1][1] == 'p' || argv[1][1] == 'c')) {
			game = new Game(argv[1][0], argv[1][1]);
		}
	}
	else {
		game = new Game(); //parte in automatico con due giocatori di tipo computer
	}
	
	game->start();

	//fine del gioco
	delete game;

	return 0;
}