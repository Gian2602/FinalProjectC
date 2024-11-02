//Bino Matteo

#ifndef ReplayGameState_H
#define ReplayGameState_H

//#include "Game.fwd.h"
#include "GameState.h"
#include "LogManipulator.h"
#include "Human.h"
#include <iostream>
#include <vector>

class ReplayGameState :
    public GameState
{
private:
    std::string filename; //nome del file di input
    char vis; //tiene conto della modalità di stampa
    int state, row; //tiene conto della fase del gioco e della riga del file a cui si è arrivati
    LogManipulator logger, output; //logger di input ed eventuale logger di output
public:
    ReplayGameState(Game* game, std::string filename, char vis = 'v');

    void onEnter();
    void update();
    void draw();
    void onExit();
};

#endif