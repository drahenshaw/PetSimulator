#ifndef PETSIMULATOR_CREATURE
#define PETSIMULATOR_CREATURE

#include "Animation.h"
#include "Consumables.h"

class Creature
{
public:
	Creature();
	Creature(int health, int energy, int hunger, int thirst, sf::Sprite newCreature);

	double getHealth();
	double getEnergy();
	double getHunger();
	double getThirst();
	sf::Sprite & getCreature();
	sf::Vector2f getvelocity();

	void setHealth(double hp);
	void setEnergy(double energy);
	void setHunger(double hunger);
	void setThirst(double thirst);
	void setCreature(sf::Sprite newCreature);
	void setDirection(sf::Vector2f newDirection);
	void setTick(int count);

	void Render(sf::RenderTarget & target);
	void Update(float dT, Consumables placed);

	

private:
	double health;
	double energy;
	double hunger;
	double thirst;

	int ticks;

	sf::Vector2f position;
	sf::Vector2f velocity;

	sf::Sprite creature;
	Animation animations_[int(Animation::AnimationIndex::COUNT)];
	Animation::AnimationIndex currentAnimation = Animation::AnimationIndex::WALKING_DOWN;
	
	//sf::Vector2f randDir;
};

#endif