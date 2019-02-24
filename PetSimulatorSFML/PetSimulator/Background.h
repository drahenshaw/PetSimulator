#pragma once
#include <SFML/Graphics.hpp>
constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 600;


class Background
{
public:
	Background();
	void renderBackground(sf::RenderWindow & window, sf::Sprite &Hamburger, sf::Sprite &Water,
		sf::Sprite &grass, sf::Sprite &toolBar);
	void drawBackground(sf::RenderWindow &window, sf::Sprite &Hamburger, sf::Sprite &Water,
		sf::Sprite &grass, sf::Sprite &toolBar);
	void renderGrass(sf::Sprite &grass);
	void renderToolBar(sf::Sprite &toolBar);
	void renderConstantConsumables(sf::Sprite &Hamburger, sf::Sprite &Water);
	void drawGrassOnly(sf::RenderWindow &window, sf::Sprite &grass);

private:
	//private textures
	sf::Texture grassTexture;
	sf::Texture toolBarTexture;
	sf::Texture HamburgerTexture;
	sf::Texture WaterTexture;
	

};