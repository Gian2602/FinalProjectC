//Bino Matteo

#include "PlacementGameState.h"
#include "Game.h" //stessa cosa in GameState.cpp

PlacementGameState::PlacementGameState(Game* game)
	: GameState(game)
{
}

void PlacementGameState::onEnter()
{
	std::cout << "----- PIAZZAMENTO NAVI -----" << std::endl;

}

void PlacementGameState::update()
{
	const unsigned int nShips = this->game->getCurrentSheet()->placedShips();
	int length = 0;
	bool inserted = false;

	while (!inserted && nShips < this->game->getCurrentSheet()->MaxShips) {

		std::cout << *game->getCurrentSheet()->getPlayer() << " ";

		if (nShips < 3) //inserire una corazzata
		{
			std::cout << "piazza la corazzata:" << std::endl;
			length = Cruiser::CRUISER_LENGHT;
		}
		else if (nShips < 6) //inserire una nave di supporto
		{
			std::cout << "piazza la nave di supporto:" << std::endl;
			length = Support::SUPPORT_LENGHT;
		}
		else if (nShips < 8) //inserire un sottomarino
		{
			std::cout << "piazza il sottomarino:" << std::endl;
			length = Submarine::SUBMARINE_LENGHT;
		}

		try {
			Ship* newShip = nullptr;

			//prende l'input dell'utente (umano o computer)
			std::string input = game->getCurrentSheet()->getPlayerPositioningInput(length);
			std::string sstern, sbow; //poppa e prua inserite dall'utente
			
			//dividere l'input in due substringhe
			std::vector<std::string> inputs = HUtils::divideString(input, ' ');

			Pos stern, bow; //poppa e prua
			stern = Pos(inputs[0]);
			bow = Pos(inputs[1]);

			if (nShips < 3) //inserire una corazzata
			{
				newShip = new Cruiser(stern, bow);
			}
			else if (nShips < 6) //inserire una nave di supporto
			{
				newShip = new Support(stern, bow);
			}
			else if (nShips < 8) //inserire un sottomarino
			{
				newShip = new Submarine(stern, bow);
			}
			
			if (this->game->getCurrentSheet()->ctrldef->insertBoat(newShip)){ //se l'inserimento va a buon fine
				inserted = true;
				game->getCurrentSheet()->addShip(newShip); //viene aggiunta la nave al vettore
				//logga l'input
				game->getLog().insertString(input);
			}
		}
		catch (const PosException& e) {
			std::cout << e.what() << std::endl;
		}
		catch (const ShipException& e) {
			std::cout << e.what() << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	if (nShips == this->game->getCurrentSheet()->MaxShips) { //se un giocatore ha finito di posizionare le navi

		if (this->game->getOpponentSheet()->placedShips() == this->game->getOpponentSheet()->MaxShips) { //se anche l'altro ha finito
			game->switchTurn();
			game->updateState(new PlayGameState(game));
			return;
		}
		else { //in entrambi i casi si fa il cambio turno, ma per renderla un'operazione comune andrebbe messa prima dell'if, quindi dovrei modificare la condizione dell'if che risulterebbe meno chiara
			game->switchTurn();
		}
	}
}

void PlacementGameState::draw()
{
	std::cout << "\n" <<  *this->game->getCurrentSheet()->ctrldef << "\n"; //stampa della mappa di difesa del giocatore corrente

}

void PlacementGameState::onExit()
{
	std::cout << "----- FINE PIAZZAMENTO -----" << std::endl;
}