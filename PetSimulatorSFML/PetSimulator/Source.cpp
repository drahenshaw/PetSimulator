#include <iostream>
#include <chrono>

#include "Background.h"
#include "Creature.h"
#include "Health_Bars.h"
#include "Consumables.h"
#include "Physics.h"


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


	auto timePoint = std::chrono::steady_clock::now();

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

		float dt;
		{
			const auto newTimePoint = std::chrono::steady_clock::now();
			dt = std::chrono::duration<float>(newTimePoint - timePoint).count();
			timePoint = newTimePoint;
		}

		Orc->Update(dt);
		if (count % 100 == 0) {
			Orc->setHealth(Orc->getHealth() - 1 * dt);
			bars.setHealth(Orc->getHealth());
			if (Orc->getHealth() < 0)
				bars.setHealth(0);
		}

		if (Physics::isColliding(*Orc, consume))
		{
			Orc->setHealth(150.0);
			consume.setreleasedXAndY(500, 550);
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
		if (count > 120)
			count = 0;
	}

}