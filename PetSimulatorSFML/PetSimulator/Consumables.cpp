#include "Consumables.h"
#include <iostream>

void Consumables::drawConsumable(sf::RenderWindow &window, sf::Sprite &Hamburger, sf::Sprite &Water)
{
	if (mousePressed == 1)
	{
		if (x >= 450 && x <= 550 && y <= 700 && y >= 400)
		{
			Hamburger.setPosition(sf::Mouse::getPosition(window).x -12, sf::Mouse::getPosition(window).y - 12);
			window.draw(Hamburger);
		}
		else if (x >= 250 && x <= 350 && y <= 700 && y >= 400)
		{
			Water.setPosition(sf::Mouse::getPosition(window).x - 22, sf::Mouse::getPosition(window).y - 15);
			window.draw(Water);
		}
	}
	else
	{
		if (x >= 450 && x <= 550 && y <= 700 && y >= 400 && yreleased <= 500)
		{
			Hamburger.setPosition(xreleased, yreleased);
			window.draw(Hamburger);
		}
		else if (x >= 250 && x <= 350 && y <= 700 && y >= 400 && yreleased <= 500)
		{
			Water.setPosition(xreleased, yreleased);
			window.draw(Water);
		}
	}
}

void Consumables::setValue(int newMousePressed)
{
	mousePressed = newMousePressed;
}

void Consumables::setXAndY(int newx, int newy)
{
	std::cout << "x: " << newx << " y: " << newy << std::endl;
	x = newx;
	y = newy;
}

void Consumables::setreleasedXAndY(int newx, int newy)
{
	xreleased = newx;
	yreleased = newy;
}

int Consumables::getXReleased() const
{
	return xreleased;
}

int Consumables::getYReleased() const
{
	return yreleased;
}

Consumables::itemType Consumables::getType() const
{
	return this->type_;
}

void Consumables::setType(Consumables::itemType what)
{
	this->type_ = what;
}