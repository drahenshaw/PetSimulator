#include <iostream>
#include <chrono>

#include "Background.h"
#include "Creature.h"
#include "Health_Bars.h"
#include "Consumables.h"
#include "Physics.h"
#include "Menu.h"

int main(void)
{
	sf::Sprite Water, grass, Hamburger, toolBar;
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML works!");
	Background background;
	background.renderBackground(window, Hamburger, Water, grass, toolBar);
	health_bars bars;
	Consumables consume;
	Menu menu;
	int choice = 0;
	menu.renderStartMenu(window);
	sf::Texture creature;
	creature.loadFromFile("Assets/Creature 1.png");
	sf::Sprite orcSprite(creature);
	Creature * Orc = new Creature(150.0, 150.0, 150.0, 150.0, orcSprite);

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
				choice = 1;
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

		Orc->Update(dt, consume);
		if (count % 100 == 0) {
			if(Orc->getHunger() < 50)
				Orc->setHealth(Orc->getHealth() - 1);
			if (Orc->getThirst() < 40)
				Orc->setHealth(Orc->getHealth() - 1);

			Orc->setEnergy(Orc->getEnergy() - .25);
			Orc->setHunger(Orc->getHunger() - .5);
			Orc->setThirst(Orc->getThirst() - 1);
			Orc->setHealth(Orc->getHealth() - 1 * dt);
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

		//window.clear();

	    if (choice == 0)
		{

			Orc->setHealth(150.0);
			consume.setreleasedXAndY(500, 550);			
			Orc->setHunger(150.0);			
			Orc->setThirst(150.0);
			Orc->setEnergy(150.0);			

			//background.drawBackground(window, Hamburger, Water, grass, toolBar);
		    background.drawGrassOnly(window, grass);
			menu.DisplayStartMenu(window);


		}
		else if(choice == 1)
		{

			Orc->setTick(count);

			Orc->Update(dt);
			if (count % 100 == 0) {
				Orc->setHealth(Orc->getHealth() - 1);
				bars.setHealth(Orc->getHealth());
				if (Orc->getHealth() < 0)
					bars.setHealth(0);
			}

			if (Physics::isColliding(*Orc, consume))
			{
				Orc->setHealth(150.0);
				consume.setreleasedXAndY(500, 550);

			if (consume.getType() == Consumables::itemType::FOOD)
			{
				Orc->setHunger(150.0);
			}
			else
			{
				Orc->setThirst(150.0);
			}
			consume.setIs_placed(false);
		}
	

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
			count++;
			if (count > 120)
				count = 0;

			count++;
			if (count > 120) {
				count = 0;
				//system("cls");
				std::cout << "Velocity: " << Orc->getvelocity().x << ", " << Orc->getvelocity().y << std::endl;
				//std::cout << "Position: " << Orc->getCreature().getPosition().x << ", " << Orc->getCreature().getPosition().y << std::endl;
			}
			//////Check if creature Died///////////
			if (Orc->getHealth() < 0)
			{
				choice = 2;
			}
			if (Orc->getEnergy() == 0)
			{
				choice = 3;
			}
			//////////////////////////////////////
		}
		else if (choice == 2)
		{
			background.drawGrassOnly(window, grass);
			menu.DisplayGameOver(window);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				choice = 0;				
			}
		}
		else
		{
			background.drawGrassOnly(window, grass);
			menu.DisplayWin(window);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				choice = 0;
			}
		}

		window.display();
	}

}