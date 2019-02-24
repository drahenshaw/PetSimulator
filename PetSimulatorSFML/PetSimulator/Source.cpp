#include <iostream>
#include <SFML/Graphics.hpp>

#include "Creature.h"
#include "Animation.h"
#include "Health_Bars.h"
#include "Consumables.h"

int main(void)
{
	//Screen dimensions
	constexpr int SCREEN_WIDTH = 800;
	constexpr int SCREEN_HEIGHT = 600;

	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML works!");
	sf::Texture texture;
	health_bars bars;
	sf::Texture texture2;
	texture.loadFromFile("Assets/grass block.jpg");
	texture2.loadFromFile("Assets/userInterface.png");
	Consumables consume;
	//sf::Texture texture2 = consume.getTexture
	sf::Texture temp = consume.getTexture(0);
	sf::Sprite Hamburger(temp);
	Hamburger.setScale(0.05, 0.05);
	sf::Texture temp2 = consume.getTexture(1);
	sf::Sprite Water(temp2);
	Water.setScale(0.05, 0.05);

	sf::Texture creature;
	creature.loadFromFile("Assets/Creature 1.png");
	sf::Sprite orcSprite(creature);
	Creature * Orc = new Creature(150, 150, 150, 150, orcSprite);

	texture.loadFromFile("Assets/grass block.jpg");
	

	sf::Sprite sprite(texture);
	sf::Sprite sprite2(texture2);
	sprite2.setScale(0.417246, 0.071633);

	sprite.setTextureRect({ 20, 20, 100, 100 });

	// Run windowasdf
	
	sprite.setTextureRect({ 20, 20, 100, 100 });
	// Run window

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		Orc->Update(.001);

		window.clear();

		// SETTING THE BACKGROUND////////////
		//window.draw(background.getSprite());
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				sprite.setPosition(i * 100, j * 100);
				window.draw(sprite);
			}
		}
		sprite.setPosition(0, 0);

		sprite2.setPosition(100, 500);
		window.draw(sprite2);

		Water.setPosition(300, 550);
		Hamburger.setPosition(500, 550);
		window.draw(Water);
		window.draw(Hamburger);

		Orc->Render(window);
		window.draw(bars.getEnergy());
		window.draw(bars.getHealth());
		window.draw(bars.getHunger());
		window.draw(bars.getThirst());

		for (int i = 0; i < 4; i++)
			window.draw(bars.getOutline(i));
		
		window.display();

	}

}