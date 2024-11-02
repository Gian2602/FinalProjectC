//Gianluca Caregnato
#include "Map.h"




Map::Map() {

	//riempio la mappa di ' ' (che sarebbe l'acqua)
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			map[i][j] = ' ';
		}
	}

}

std::string Map::mapToString()const {

	std::string temp;

	//riempio una stringa con tutti i caratteri della mappa
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			
			temp =+ map[i][j];
		}
		temp += "\n";
	}

	return temp;
}



std::ostream& operator<<(std::ostream& os, const Map& obj) {

	//stampo la mappa con qualche piccola accortezza grafica
	for (int i = 0; i < obj.getRow(); i++) {
		if (i + 'A' < 'J')
			os << (char)(i + 'A');
		else
			os << (char)(i + 2 + 'A');
		for (int j = 0; j < obj.getCol(); j++) {
			if (j > 9)
				os << " ";
			os << '|';
			os << obj.at(Pos(i,j));
		}
		os << " |";
		os << std::endl;
	}
	os << " ";
	for (int i = 1; i <= obj.getCol(); i++) {
		os << " " << i;
	}
	return os;

}
