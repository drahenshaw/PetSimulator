#include "Health_Bars.h"

health_bars::health_bars()
{
	this->energy;
	this->health;
	this->hunger;
	this->thirst;

	this->outline;

	//initializing size
	this->energy.setFillColor(sf::Color::Yellow);
	this->health.setFillColor(sf::Color::Red);
	this->hunger.setFillColor(sf::Color::Green);
	this->thirst.setFillColor(sf::Color::Blue);

	this->energy.setPosition(sf::Vector2f(10, 10));
	this->health.setPosition(sf::Vector2f(170, 10));
	this->hunger.setPosition(sf::Vector2f(330, 10));
	this->thirst.setPosition(sf::Vector2f(490, 10));

	this->energy.setSize(sf::Vector2f(150, 10));
	this->health.setSize(sf::Vector2f(150, 10));
	this->hunger.setSize(sf::Vector2f(150, 10));
	this->thirst.setSize(sf::Vector2f(150, 10));

	for (int i = 0, j = 10; i < 4; i++, j += 160)
	{
		outline[i].setOutlineThickness(1);
		outline[i].setOutlineColor(sf::Color::Black);
		outline[i].setSize(sf::Vector2f(150, 10));
		outline[i].setPosition(sf::Vector2f(j, 10));
		outline[i].setFillColor(sf::Color::Transparent);
	}
}

sf::RectangleShape health_bars::getHealth()
{
	return this->health;
}
sf::RectangleShape health_bars::getEnergy()
{
	return this->energy;
}
sf::RectangleShape health_bars::getHunger()
{
	return this->hunger;
}
sf::RectangleShape health_bars::getThirst()
{
	return this->thirst;
}
sf::RectangleShape health_bars::getOutline(int i)
{
	return this->outline[i];
}

void health_bars::setHealth(int creatureHealth)
{
	this->health.setSize(sf::Vector2f(creatureHealth*150/150.0, 10));
}
void health_bars::setEnergy(int creatureHealth)
{
	this->energy.setSize(sf::Vector2f(creatureHealth / 150, 10));
}
void health_bars::setHunger(int creatureHealth)
{
	this->hunger.setSize(sf::Vector2f(creatureHealth / 150, 10));
}
void health_bars::setThirst(int creatureHealth)
{
	this->thirst.setSize(sf::Vector2f(creatureHealth / 150, 10));
}