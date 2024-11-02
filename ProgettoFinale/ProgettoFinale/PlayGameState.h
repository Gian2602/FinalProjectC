//Bino Matteo

#ifndef PlayGameState_H
#define PlayGameState_H

//#pragma message("Top in: " __FILE__)
#include "Game.fwd.h"
#include "GameState.h"
#include "Sheet.h"
#include <iostream>
//#pragma message("Before class in: " __FILE__)

class PlayGameState : public GameState
{
public:
    PlayGameState(Game* game);
    void onEnter();
    void update();
    void draw();
    void onExit();

    void printCurrentMaps() const;
};

#endif