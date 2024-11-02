#include "Player.h"

Player::Player(std::string name)
	: name{name}
{
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
	os << player.getName();
	return os;
}
