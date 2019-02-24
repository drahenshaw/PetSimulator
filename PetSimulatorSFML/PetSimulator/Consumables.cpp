#include "Consumables.h"

Consumables::Consumables()
{
	loadConsumables(all);
}


void Consumables::loadConsumables(sf::Texture all[2])
{
	all[0].loadFromFile("Assets/burger.png");
	all[1].loadFromFile("Assets/water2.png");
}

sf::Texture Consumables::getTexture(int whichone)
{
	return all[whichone];
}

