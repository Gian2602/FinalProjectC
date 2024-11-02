//Bino Matteo

#include "PlayGameState.h"
#include "GameState.h" //come in GameState
#include "Game.h"

PlayGameState::PlayGameState(Game* game)
	: GameState(game)
{
}

void PlayGameState::onEnter()
{
	std::cout << "----- INIZIO PARTITA -----" << std::endl;
}

void PlayGameState::update()
{
	/*schema del turno :
		- se si entra in questa funzione significa che alla fine del turno precedente nessuno ha vinto
		- si chiede l'input
		- si elabora in modo da capire la nave sorgente
		- si chiama l'azione della nave sorgente o il comando speciale:
		---AA AA: attraverso ControlAttack si eliminano le Y, non consuma il turno
		---BB BB: attraverso ControlAttack si eliminano le X, non consuma il turno
		---CC CC: attraverso ControlAttack si eliminano le O, non consuma il turno
		---XX XX: vengono stampate le mappe di difesa e di attacco, non consuma il turno
		---se è un supporto:
				si controlla che la nave possa andare a destinazione usando ControlDefence,
					-se l'esito è positivo si modificano le navi colpite in un raggio di 1,
					si modifica la mappa di difesa del giocatore corrente attraverso ControlDefence
					-se è negativo si chiede di nuovo l'input
		---un sottomarino: 
				si controlla che la nave possa andare a destinazione usando ControlDefence
					-se l'esito è positivo si richiedono le caselle in un raggio di 2
					si modifica la mappa di attacco del giocatore corrente attraverso ControlAttack
					-se è negativo si chiede di nuovo l'input
		---se è una corazzata:
				si spara, si vede se si colpisce una nave controllando le posizioni delle navi nemiche,
				si aggiorna lo stato delle navi nemiche,
				si aggiorna la mappa di difesa avversaria attraverso ControlDefence del nemico,
				si aggiorna la mappa di attacco del giocatore corrente attraverso ControlAttack
	*/

	try {

		std::cout << *game->getCurrentSheet()->getPlayer() << " inserisci azione: ";


		std::string input = game->getCurrentSheet()->getPlayerPlayInput();
		bool validTurn = false;

		//si vede se è un comando speciale
		if (input == "AA AA") {
			game->getCurrentSheet()->ctrlatk->deleteY();
		}
		else if (input == "BB BB") {
			game->getCurrentSheet()->ctrlatk->deleteX();
		}
		else if (input == "CC CC") {
			game->getCurrentSheet()->ctrlatk->deleteO();
		}
		else if (input == "XX XX") {
			printCurrentMaps();
		}
		else {
			std::vector<std::string> divInput = HUtils::divideString(input);
			Pos p1 = divInput[0];	//sono sicuro che divInput sia di dimensione 2 perchè il controllo viene fatto in getPlayerInput()
			Pos p2 = divInput[1];

			//si trova la nave che esegue l'azione
			Ship* actor = game->getCurrentSheet()->selectShipByCenter(p1);

			if (actor != nullptr) { //se è stata scelta correttamente, si fa eseguire l'azione

				if (actor->shipLenght() == 5) ((Cruiser*)actor)->mainAction(p2, game->getCurrentSheet(), game->getOpponentSheet());
				else if (actor->shipLenght() == 3) ((Cruiser*)actor)->mainAction(p2, game->getCurrentSheet(), game->getOpponentSheet());
				else if (actor->shipLenght() == 1) ((Cruiser*)actor)->mainAction(p2, game->getCurrentSheet(), game->getOpponentSheet());

				//actor->mainAction(p2, game->getCurrentSheet(), game->getOpponentSheet());
				validTurn = true;
			}
			else {
				//l'input non è al centro della nave che esegue l'azione
				throw std::exception("selezionare il centro di una nave.");
			}
		}

		if (validTurn) {
			//logga l'input
			game->getLog().insertString(input);

			//al termine del turno si incrementa il contatore dei turni
			game->addElapsedTurn();
			if (!game->isMatchFinished())
				game->switchTurn();
			else {
				game->setIsRunning(false);
			}
		}
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}	
}

void PlayGameState::draw()
{
	
}

void PlayGameState::onExit()
{
	std::cout << "----- PARTITA TERMINATA ------\n";

}

void PlayGameState::printCurrentMaps() const
{
	std::cout << *this->game->getCurrentSheet()->ctrldef << std::endl << std::endl;
	std::cout << *this->game->getCurrentSheet()->ctrlatk << std::endl << std::endl;
}
