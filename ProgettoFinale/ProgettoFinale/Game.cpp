//Bino Matteo

#include "Game.h"

Game::Game(char p1, char p2)
	: state{ nullptr }, isRunning{ false }, currentSheet{ nullptr }, opponentSheet{ nullptr }, elapsedTurns{0}
{
	//in base agli argomenti passati costruisce i due giocatori
	if (p1 == 'p')
		s1 = new Sheet{ new Human("giocatore1")};
	else {
		s1 = new Sheet{ new Computer("computer1") };
	}

	if (p2 == 'p')
		s2 = new Sheet{ new Human("giocatore2")};
	else {
		s2 = new Sheet{ new Computer("computer2") };
	}
	this->log = LogManipulator();

}

Game::~Game()
{
	delete this->state;	//quando il gioco viene distrutto lo stato non ha più senso di esistere
	this->currentSheet = nullptr;	//posso settare a nullptr perchè restano puntati da s1 e s2 rispettivamente
	this->opponentSheet = nullptr;
	delete this->s1; //distrugge i due fogli di info dei giocatori
	delete this->s2;

}

void Game::start()
{
	//sceglie casualmente il giocatore che inizia
	int choice = std::rand() % 2;

	if (choice == 1) {
		this->currentSheet = s1;
		this->opponentSheet = s2;
	}
	else {
		this->currentSheet = s2;
		this->opponentSheet = s1;
	}
	//fa partire il gioco in modalità piazzamento
	this->startInState(new PlacementGameState(this));
}

void Game::startInState(GameState* newState) {
	this->updateState(newState);	//aggiorna lo stato del gioco da nullptr a "newState"
	setIsRunning(true);			//così può iniziare il loop del gioco

	this->draw();

	this->loop();	
}

void Game::loop()
{
	while (this->isRunning) {
		
		this->update();			//aggiorna in base allo stato corrente
		this->draw();			//disegna in base allo stato corrente
	}

	this->end();
}

void Game::update()
{
	this->state->update(); //aggiorna lo stato corrente (ogni stato fa operazioni diverse
}

void Game::draw()
{
	this->state->draw(); //disegna lo stato corrente
}

GameState* Game::updateState(GameState* newState)
{
	if (newState != nullptr) {		//se viene fornito uno stato
		if (this->state != nullptr) this->state->onExit();		//fa partire la procedura di uscita dallo stato corrente (se esiste)

		delete this->state;							//elimina lo stato corrente per evitare memory leak

		this->state = newState;						//sposta la freccia del puntatore sul nuovo stato

		this->state->onEnter();						//fa partire la procedura di ingresso del nuovo stato
	}

	return this->state;								//ritorna il nuovo stato
}

Sheet* Game::getCurrentSheet()
{
	return this->currentSheet;
}

Sheet* Game::getOpponentSheet()
{
	return this->opponentSheet;
}

void Game::switchTurn()
{
	//scambia le frecce dei puntatori
	Sheet* temp = this->currentSheet;
	this->currentSheet = this->opponentSheet;
	this->opponentSheet = temp;
}

LogManipulator& Game::getLog()
{
	return log;
}

bool Game::setIsRunning(bool newState)
{
	bool wasRunning = isRunning;
	isRunning = newState;

	return wasRunning;
}

void Game::addElapsedTurn()
{
	this->elapsedTurns++;
}

bool Game::isMatchFinished()
{
	//controlla se il gioco è finito: turni max, navi abbattute
	if (elapsedTurns >= max_turns) return true;
	if (currentSheet->getShips()->empty()) return true;
	if (opponentSheet->getShips()->empty()) return true;

	return false;
}

void Game::end()
{
	std::string phrase = "Congratulazioni, ha vinto ";

	if (currentSheet->getShips()->empty()) phrase += opponentSheet->getPlayer()->getName() + " !";
	else if (opponentSheet->getShips()->empty()) phrase = currentSheet->getPlayer()->getName();
	else if (elapsedTurns >= max_turns) phrase = "Pareggio, la prossima volta impegnatevi di più!";

	std::cout << std::endl << std::endl<< phrase << std::endl;
}
