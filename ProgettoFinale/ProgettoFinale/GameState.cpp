//Bino Matteo

#include "GameState.h"
#include "Game.h" //per evitare errori in compilazione del tipo "classe base non definita" in quanto venivano definite prima le classi derivate "PlacementGameState" 

GameState::GameState(Game* game)
	: game{ game }
{
}