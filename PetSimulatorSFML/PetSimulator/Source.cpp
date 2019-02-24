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

	int count = 0;

	// Run window
	int drag = 0;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				drag = 1;
				consume.setValue(drag);
				consume.setXAndY(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
				break;
			case sf::Event::MouseButtonReleased:
				drag = 0;
				consume.setValue(drag);
				consume.setreleasedXAndY(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
				break;
			}
		}
		Orc->setTick(count);

		Orc->Update(.001);
		if (count % 100 == 0) {
			if(Orc->getHunger() < 50)
				Orc->setHealth(Orc->getHealth() - 1);
			if (Orc->getThirst() < 40)
				Orc->setHealth(Orc->getHealth() - 1);

			Orc->setEnergy(Orc->getEnergy() - .25);
			Orc->setHunger(Orc->getHunger() - .5);
			Orc->setThirst(Orc->getHunger() - 1);
			bars.setHealth(Orc->getHealth());
			bars.setEnergy(Orc->getEnergy());
			bars.setHunger(Orc->getHunger());
			bars.setThirst(Orc->getThirst());
			if (Orc->getHealth() < 0)
				bars.setHealth(0);
			if (Orc->getEnergy() < 0)
				bars.setEnergy(0);
			if (Orc->getHunger() < 0)
				bars.setHunger(0);
			if (Orc->getThirst() < 0)
				bars.setThirst(0);
		}
	

		window.clear();
		//Everything Drawn to screen in here
		//////////////////////////////////////////////////////////////////////////////////////////////
		
		// SETTING THE BACKGROUND////////////
		background.drawBackground(window, Hamburger, Water, grass, toolBar);
		////////////////////////////////////

		
			Orc->Render(window);

		//

		//Health
		window.draw(bars.getEnergy());
		window.draw(bars.getHealth());
		window.draw(bars.getHunger());
		window.draw(bars.getThirst());
		for (int i = 0; i < 4; i++)
			window.draw(bars.getOutline(i));
		//

		//new food and new water
		consume.drawConsumable(window, Hamburger, Water);

		//////////////////////////////////////////////////////////////////////////////////////////////
		window.display();
		count++;
		if (count > 120) {
			count = 0;
			//system("cls");
			std::cout << "Velocity: " << Orc->getvelocity().x << ", " << Orc->getvelocity().y << std::endl;
			//std::cout << "Position: " << Orc->getCreature().getPosition().x << ", " << Orc->getCreature().getPosition().y << std::endl;
		}

	}

}