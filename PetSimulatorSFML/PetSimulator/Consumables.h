#ifndef PETSIMULATOR_CONSUMABLES
#define PETSIMULATOR_CONSUMABLES

#include "SFML/Graphics.hpp"
#include "Background.h"

class Consumables : public Background
{
public:
	void drawConsumable(sf::RenderWindow &window, sf::Sprite &Hamburger, sf::Sprite &Water);
	void setValue(int newMousePressed);
	void setXAndY(int newx, int newy);
	void setreleasedXAndY(int newx, int newy);
private:
	int mousePressed;
	int x;
	int y;
	int xreleased;
	int yreleased;
};

#endif