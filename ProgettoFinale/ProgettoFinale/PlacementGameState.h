//Bino Matteo

#ifndef PlacementGameState_H
#define PlacementGameState_H

//#pragma message("Top in: " __FILE__)
#include "PlayGameState.h"
#include <iostream>
#include "Cruiser.h"
#include "Support.h"
#include "Submarine.h"
//#pragma message("Before class in: " __FILE__)

//stato di preparazione del campo di gioco
class PlacementGameState :
    public GameState
{
public:
    PlacementGameState(Game* game);
    void onEnter();
    void update();
    void draw();
    void onExit();
};

#endif