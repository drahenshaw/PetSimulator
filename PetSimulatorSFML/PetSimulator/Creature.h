#ifndef PETSIMULATOR_CREATURE
#define PETSIMULATOR_CREATURE

#include "Animation.h"

class Creature
{
public:
	Creature();
	Creature(int health, int energy, int hunger, int thirst, sf::Sprite newCreature);

	int getHealth();
	int getEnergy();
	int getHunger();
	int getThirst();
	sf::Sprite & getCreature();

	void setHealth(int hp);
	void setEnergy(int energy);
	void setHunger(int hunger);
	void setThirst(int thirst);
	void setCreature(sf::Sprite newCreature);
	void setDirection(sf::Vector2f newDirection);
	void setTick(int count);

	void Render(sf::RenderTarget & target);
	void Update(float dT);

private:
	int health;
	int energy;
	int hunger;
	int thirst;

	int ticks;

	sf::Vector2f position;
	sf::Vector2f velocity;

	sf::Sprite creature;
	Animation animations_[int(Animation::AnimationIndex::COUNT)];
	Animation::AnimationIndex currentAnimation = Animation::AnimationIndex::WALKING_DOWN;
	
	//sf::Vector2f randDir;
};

#endif