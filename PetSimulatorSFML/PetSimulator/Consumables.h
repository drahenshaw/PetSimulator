#ifndef PETSIMULATOR_CONSUMABLES
#define PETSIMULATOR_CONSUMABLES

#include "SFML/Graphics.hpp"
#include "Background.h"

class Consumables : public Background
{
public:
	enum class itemType {FOOD, DRINK, COUNT};
public:
	void drawConsumable(sf::RenderWindow &window, sf::Sprite &Hamburger, sf::Sprite &Water);
	void setValue(int newMousePressed);
	void setXAndY(int newx, int newy);
	void setreleasedXAndY(int newx, int newy);
	
	itemType getType() const;
	int getXReleased() const;
	int getYReleased() const;

	void setType(Consumables::itemType what);

private:
	int mousePressed;
	int x;
	int y;
	int xreleased;
	int yreleased;
	itemType type_;
};

#endif