//Bino Matteo

#include "ReplayGameState.h"
#include "Game.h"
#include "Human.h"

int main(int argc, char** argv) {


	Game* game = nullptr;
	
	if (argc > 2) {
		std::string filename = HUtils::divideString(argv[2], '.')[0];
		game = new Game();
		if ((argv[1][0] == 'v' || argv[1][0] == 'f')) {

			game->startInState(new ReplayGameState(game, filename, argv[1][0]));
		}
		else game->startInState(new ReplayGameState(game, filename));
	}
	else {
		std::cout << "input da riga di comando errati\n";
	}
	
	//fine del gioco
	delete game;

	return 0;
}