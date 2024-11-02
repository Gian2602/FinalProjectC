//Bino Matteo

#include "ReplayGameState.h"
#include "Game.h"

ReplayGameState::ReplayGameState(Game* game, std::string filename, char vis)
	: GameState(game), filename{ filename }, vis{ vis }, state{ 0 }, row{ 1 }
{
	logger = LogManipulator(filename);
	output = LogManipulator();
}

void ReplayGameState::onEnter()
{
	std::cout << "----- REPLAY -----\n";
}

void ReplayGameState::update()
{
	try {
		std::string input = logger.getStringAt(row); //legge una riga del file
		row++;
		if (input != "") { //se non è una riga vuota

			std::vector<std::string> div = HUtils::divideString(input);
			Pos p1 = div[0], p2 = div[1];
			Ship* currShip = nullptr;

			if (state == 0) {
				//piazzamento
				std::cout << game->getCurrentSheet()->getShips()->size() << "\n";
				int nShips = game->getCurrentSheet()->placedShips();

				if (nShips < 3) {
					currShip = new Cruiser(p1, p2);
				}
				else if (nShips < 6) {
					currShip = new Support(p1, p2);
				}
				else if (nShips < 8) {
					currShip = new Submarine(p1, p2);
				}

				this->game->getCurrentSheet()->ctrldef->insertBoat(currShip);
				this->game->getCurrentSheet()->addShip(currShip);

				if (this->game->getCurrentSheet()->placedShips() == this->game->getCurrentSheet()->MaxShips) { //se un giocatore ha finito di posizionare le navi

					if (this->game->getOpponentSheet()->placedShips() == this->game->getOpponentSheet()->MaxShips) { //se anche l'altro ha finito
						game->switchTurn();
						state = 1;
						return;
					}
					else { //in entrambi i casi si fa il cambio turno, ma per renderla un'operazione comune andrebbe messa prima dell'if, quindi dovrei modificare la condizione dell'if che risulterebbe meno chiara
						game->switchTurn();
					}
				}

			}
			else if (state == 1) {
				//fase di gioco
				currShip = game->getCurrentSheet()->selectShipByCenter(p1);

				currShip->mainAction(p2, game->getCurrentSheet(), game->getOpponentSheet());

				game->switchTurn();
			}
		}
		else {
			//input ternimato, finisce il gioco
			game->setIsRunning(false);
		}
	}
	catch (const LogException& e) {
		std::cout << e.what();
	}
	catch (const PosException& e) {
		std::cout << e.what();
	}
	catch (const ShipException& e) {
		std::cout << e.what();
	}
	catch (const std::exception& e) {
		std::cout << e.what();
	}
}

void ReplayGameState::draw()
{
	if (vis == 'v') {
		//stampa a video
		std::cout << *game->getCurrentSheet()->ctrldef << std::endl;
		std::cout << *game->getCurrentSheet()->ctrlatk << std::endl;
	}
	else if (vis == 'f') {
		//stampa su file
		output.insertString(game->getCurrentSheet()->getPlayer()->getName() + "\n");
		output.insertString(game->getCurrentSheet()->ctrldef->getMap()->mapToString());
		output.insertString(game->getCurrentSheet()->ctrlatk->getMap()->mapToString());
	}

}

void ReplayGameState::onExit()
{
	std::cout << "----- FINE REPLAY -----\n";
}
