#include "Menu.h"

void Menu::renderStartMenu(sf::RenderWindow &window)
{
	font.loadFromFile("Lato-bold.ttf");
	PlayGame.setFont(font);
	PlayGame.setString("Play Game");
	PlayGame.setCharacterSize(24);
	PlayGame.setFillColor(sf::Color::Red);
	//PlayGame.setPosition(100, 100);
}

void Menu::DisplayStartMenu(sf::RenderWindow &window)
{
	window.draw(PlayGame);
}
