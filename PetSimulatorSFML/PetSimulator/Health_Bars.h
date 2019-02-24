#pragma once
#include <SFML\Graphics.hpp>
#include "Creature.h"

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

	void setHealth(int creatureHealth);
	void setEnergy(int creatureHealth);
	void setHunger(int creatureHealth);
	void setThirst(int creatureHealth);

private:
	sf::RectangleShape health;
	sf::RectangleShape energy;
	sf::RectangleShape hunger;
	sf::RectangleShape thirst;

	sf::RectangleShape outline[4];
};