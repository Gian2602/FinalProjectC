//Rocchegiani Fabrizio

#ifndef Component_h
#define Component_h

#include "Pos.h"

class Component
{
	private:
		//statistiche di base del componente:
		int maxHealth;
		int actHealth;
		Pos coordinates;
	public:
		static const int DEFAULT_HEALTH = 1;

		//costruttori:
		Component(int x, int y, int maxHealth = DEFAULT_HEALTH);
		Component(Pos coordinates = Pos(), int maxHealth = DEFAULT_HEALTH);
		//Component(Pos coordinates, int maxHealth, int actHealth);

		//funzione che ritorna se un componente è distrutto:
		bool isDes();
		
		//funzioni getters del componente:
		int getMaxHealth() const;
		int getActHealth() const;
		Pos getCoordinates() const;
		
		//funzioni setters del componente:
		void setMaxHealth(int maxHealth);
		void setActHealth(int actHealth);
		void setCoordinates(Pos coordinates);
		
		//operatori utilizzabili su un componente:
		void operator=(Component c);
		Component* operator-(int dmg);
		Component* operator--();
		Component* operator+(int heal);
		Component* operator++();
		//altri operatori non sono richiesti in questa versione del codice.
};

#endif // !Component_h