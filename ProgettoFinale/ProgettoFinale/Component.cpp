//Rocchegiani Fabrizio

#include "Component.h"

Component::Component(int x, int y, int maxHealth)
{
	this->Component::Component(Pos(x, y), maxHealth);
}

Component::Component(Pos coordinates, int maxHealth)
{
	this->coordinates = coordinates;
	this->maxHealth = maxHealth;
	this->actHealth = maxHealth;
}

/*
Component::Component(Pos coordinates, int maxHealth, int actHealth)
{
	this->coordinates = coordinates;
	this->maxHealth = maxHealth;
	this->actHealth = actHealth;
}
*/

bool Component::isDes() {
	if (actHealth > 0)
		return false;
	return true;
}

int Component::getMaxHealth() const {
	return maxHealth;
}

int Component::getActHealth() const {
	return actHealth;
}

Pos Component::getCoordinates() const {
	return coordinates;
}

void Component::setMaxHealth(int maxHealth) {
	this->maxHealth = maxHealth;
}

void Component::setActHealth(int actHealth) {
	this->actHealth = actHealth;
	if (actHealth > maxHealth)
		this->actHealth = maxHealth;
	if (actHealth < 0)
		this->actHealth = 0;
}

void Component::setCoordinates(Pos coordinates) {
	this->coordinates = coordinates;
}

void Component::operator=(Component c) {
	this->setMaxHealth(c.getMaxHealth());
	this->setActHealth(c.getActHealth());
	this->setCoordinates(Pos(c.getCoordinates().getRow(), c.getCoordinates().getCol()));
}

Component* Component::operator-(int dmg) {
	if(actHealth>0)
		this->actHealth -= dmg;
	if (actHealth < 0)
		this->actHealth = 0;
	return this;
}

Component* Component::operator--() {
	return operator-(1);
}

Component* Component::operator+(int heal) {
	if(actHealth<maxHealth)
		this->actHealth += heal;
	if (actHealth > maxHealth)
		this->actHealth = maxHealth;
	return this;
}

Component* Component::operator++() {
	return operator+(1);
}