#include "Menu.h"

void Menu::renderStartMenu(sf::RenderWindow &window)
{
	font.loadFromFile("Assets/Lato-bold.ttf");
	PlayGame.setFont(font);
	PlayGame.setString("Play Game");
	PlayGame.setCharacterSize(100);
	PlayGame.setFillColor(sf::Color::Red);
	PlayGame.setPosition(150, 200);

	GameOver.setFont(font);
	GameOver.setString("Game Over");
	GameOver.setCharacterSize(100);
	GameOver.setFillColor(sf::Color::Red);
	GameOver.setPosition(150, 200);
}

void Menu::DisplayStartMenu(sf::RenderWindow &window)
{
	window.draw(PlayGame);
}

void Menu::DisplayGameOver(sf::RenderWindow &window)
{
	window.draw(GameOver);
}

