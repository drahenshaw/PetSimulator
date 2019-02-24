#include "SFML/Graphics.hpp"

class Menu
{
public:
	void renderStartMenu(sf::RenderWindow &window);
	void DisplayStartMenu(sf::RenderWindow &window);
	void DisplayGameOver(sf::RenderWindow &window);
private:
	sf::Text PlayGame;
	sf::Text GameOver;
	sf::Font font;
};