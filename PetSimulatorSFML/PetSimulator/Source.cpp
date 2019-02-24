#include <iostream>

#include "Background.h"
#include "Creature.h"
#include "Health_Bars.h"
#include "Consumables.h"


int main(void)
{
	sf::Sprite Water, grass, Hamburger, toolBar;
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML works!");
	Background background;
	background.renderBackground(window, Hamburger, Water, grass, toolBar);
	health_bars bars;
	Consumables consume;

	sf::Texture creature;
	creature.loadFromFile("Assets/Creature 1.png");
	sf::Sprite orcSprite(creature);
	Creature * Orc = new Creature(150, 150, 150, 150, orcSprite);


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
		background.drawBackground(window, Hamburger, Water, grass, toolBar);

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