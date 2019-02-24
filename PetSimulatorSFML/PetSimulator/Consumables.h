#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Consumables
{
public:
	Consumables();
	void loadConsumables(sf::Texture all[2]);
	sf::Texture getTexture(int whichone);
private:
	sf::Texture all[10];
};