#include "Game.h"

int main(int argc, char** argv) {
	
	//test di Game
	Game* game = nullptr;
	/*
	if (argc > 1) {
		if ((argv[1][0] == 'p' || argv[1][0] == 'c') && (argv[1][1] == 'p' || argv[1][1] == 'c')) {
			std::cout << "argomenti da terminale: " << argv[1][0] << argv[1][1]<< std::endl;
			game = new Game(argv[1][0], argv[1][1]);
		}
	}
	else {
		std::cout << "nessun argomento" << std::endl;
		game = new Game(); //parte in automatico con due giocatori di tipo computer
	}
	*/
	std::fflush(stdin);
	game = new Game('p', 'c'); //MOMENTANEO
	game->start();


	//fine del gioco
	delete game;
}