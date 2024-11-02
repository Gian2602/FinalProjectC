//Gianluca Caregnato
#include "Computer.h"

Computer::Computer(std::string name, unsigned int placedShips)
    : Player(name), placedShips{ placedShips }
{
    srand(time(NULL));
}

std::string Computer::getPositioningInput(const int lenght)
{
    //genero due coordinate casuali tra 0 e la lunghezza/altezza della mappa
    int x = std::rand() % Map::getRow();
    int y = std::rand() % Map::getCol();

    //inizializzo una variabile form con le coordinate generate automaticamente
    Pos from = Pos(x, y);
    Pos to;

    if (std::rand() % 2 == 0)  //metto la nave in verticale
        to = Pos(x, y + (lenght - 1)); //genero la seconda coordinata alla giusta distanza in verticale

    else //metto la nave in orrizontale
        to = Pos(x + (lenght - 1), y); //genero la seconda coordinata alla giusta distanza in orrizontale

    //ritorno due coordinate per inserire la barca, l'eventualità che la barca sia sopra ad altre o che sia fuori dalla mappa è gestita dalla classe ConrtolDefence
    return from.getPos() + ' ' + to.getPos(); 
}

std::string Computer::getPlayInput(std::vector<Ship*>* ships)
{
    int choice = std::rand() % ships->size(); //prendo una barca a caso

    std::string from = ships->at(choice)->getCenter().getCoordinates().getPos(); //salvo la coordinata del centro della barca

    char y = PUtil::intToChar(std::rand() % Map::getRow()); //genero una coordinata a caso da A a (l'ultima lettera che varia a seconda di quanto è grande la mappa)
    std::string x = std::to_string(std::rand() % Map::getCol() + 1); //genero anche la colonna

    std::string to = y + x;

    return (from + ' ' + to); //ritorno quindi l'azione casuale
}
