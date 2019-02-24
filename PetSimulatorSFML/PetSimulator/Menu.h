#include "SFML/Graphics.hpp"

class Menu
{
public:
	void renderStartMenu(sf::RenderWindow &window);
	void DisplayStartMenu(sf::RenderWindow &window);
private:
	sf::Text PlayGame;
	sf::Text InstructionsHeader;
	sf::Text InstructionsLine1;
	sf::Font font;
};