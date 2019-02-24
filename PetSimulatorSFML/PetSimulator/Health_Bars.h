#ifndef PETSIMULATOR_HEAlTHBARS
#define PETSIMULATOR_HEALTHBARS

#include "SFML/Graphics.hpp"

class health_bars
{
public:
	health_bars();
	//health_bars(int value, sf::RectangleShape newBar);

	//int getValue();
	//sf::RectangleShape & getBar();

	sf::RectangleShape getHealth();
	sf::RectangleShape getEnergy();
	sf::RectangleShape getHunger();
	sf::RectangleShape getThirst();
	sf::RectangleShape getOutline(int i);

	void setHealth(double creatureHealth);
	void setEnergy(double creatureHealth);
	void setHunger(double creatureHealth);
	void setThirst(double creatureHealth);

private:
	sf::RectangleShape health;
	sf::RectangleShape energy;
	sf::RectangleShape hunger;
	sf::RectangleShape thirst;

	sf::RectangleShape outline[4];
};

#endif