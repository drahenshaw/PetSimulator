#include "Background.h"

Background::Background()
{
}

void Background::renderBackground(sf::RenderWindow & window, sf::Sprite &Hamburger, sf::Sprite &Water, 
	sf::Sprite &grass, sf::Sprite &toolBar)
{
	renderGrass(grass);
	renderToolBar(toolBar);
	renderConstantConsumables(Hamburger, Water);
}

void Background::drawBackground(sf::RenderWindow &window, sf::Sprite &Hamburger, sf::Sprite &Water,
	sf::Sprite &grass, sf::Sprite &toolBar)
{
	//drawing out the grass
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			grass.setPosition(i * 100, j * 100);
			window.draw(grass);
		}
	}
	grass.setPosition(0, 0);
	//drawing toolbar
	toolBar.setPosition(100, 500);
	window.draw(toolBar);
	//draw hamburger
	Hamburger.setPosition(500, 550);
	window.draw(Hamburger);
	//draw water
	Water.setPosition(300, 550);
	window.draw(Water);
}

void Background::renderGrass(sf::Sprite &grass)
{
	grassTexture.loadFromFile("Assets/grass block.jpg");
	grass.setTexture(grassTexture);
	grass.setTextureRect({ 20, 20, 100, 100 });
}

void Background::renderToolBar(sf::Sprite &toolBar)
{
	toolBarTexture.loadFromFile("Assets/userInterface.png");
	toolBar.setTexture(toolBarTexture);
	toolBar.setScale(0.417246, 0.071633);
}

void Background::renderConstantConsumables(sf::Sprite &Hamburger, sf::Sprite &Water)
{
	//load textures
	HamburgerTexture.loadFromFile("Assets/burger.png");
	WaterTexture.loadFromFile("Assets/Water2.png");
	//make sprites init with textures
	Hamburger.setTexture(HamburgerTexture);
	Water.setTexture(WaterTexture);
	//set scale of sprites
	Hamburger.setScale(0.05, 0.05);
	Water.setScale(0.05, 0.05);
}

void Background::drawGrassOnly(sf::RenderWindow &window, sf::Sprite &grass)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			grass.setPosition(i * 100, j * 100);
			window.draw(grass);
		}
	}
	grass.setPosition(0, 0);
}



