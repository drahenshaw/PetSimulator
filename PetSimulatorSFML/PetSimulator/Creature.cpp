#include "Creature.h"

Creature::Creature()
{
	this->energy;
	this->health;
	this->hunger;
	this->thirst;

	this->creature;
	this->currentAnimation = Animation::AnimationIndex::WALKING_DOWN;

	this->creature.setPosition(sf::Vector2f(400, 300));

	this->position.x = 368;
	this->position.y = 268;

	//this->randDir.x = 1;
	//this->randDir.y = 1;
}
Creature::Creature(int health, int energy, int hunger, int thirst, sf::Sprite newCreature)
{
	this->health = health;
	this->energy = energy;
	this->hunger = hunger;
	this->thirst = thirst;

	this->creature = newCreature;

	this->creature.setTextureRect({ 0, 0, 64, 64 });

	animations_[int(Animation::AnimationIndex::WALKING_UP)]    = Animation(64, 525, 64, 64, "Assets/Creature 1.png", -1);
	animations_[int(Animation::AnimationIndex::WALKING_DOWN)]  = Animation(64, 650, 64, 64, "Assets/Creature 1.png", -1);
	animations_[int(Animation::AnimationIndex::WALKING_LEFT)]  = Animation(64, 590, 64, 64, "Assets/Creature 1.png", -1);
	animations_[int(Animation::AnimationIndex::WALKING_RIGHT)] = Animation(64, 720, 64, 64, "Assets/Creature 1.png", -1);
	
	animations_[int(currentAnimation)].ApplyToSprite(this->creature);

}

int Creature::getHealth()
{
	return this->health;
}
int Creature::getEnergy()
{
	return this->energy;
}
int Creature::getHunger()
{
	return this->hunger;
}
int Creature::getThirst()
{
	return this->thirst;
}
sf::Sprite & Creature::getCreature()
{
	return this->creature;
}

void Creature::setHealth(int hp)
{
	this->health = hp;
}
void Creature::setEnergy(int energy)
{
	this->energy = energy;
}
void Creature::setHunger(int hunger)
{
	this->hunger = hunger;
}
void Creature::setThirst(int thirst)
{
	this->thirst = thirst;
}
void Creature::setCreature(sf::Sprite newCreature)
{
	this->creature = newCreature;
}
void Creature::setTick(int count)
{
	this->ticks = count;
}


void Creature::Render(sf::RenderTarget & target)
{
	target.draw(this->getCreature());
}

void Creature::Update(float dT)
{
	
	if (this->ticks == 100)
	{
		sf::Vector2f randDir;
		randDir.x = rand() % 50;
		randDir.y = rand() % 50;
		setDirection(randDir);
	}
	//else
		//setDirection(velocity);
	
	position = velocity * dT;
	animations_[int(currentAnimation)].Update(dT, 0);
	animations_[int(currentAnimation)].ApplyToSprite(creature);
	this->creature.setPosition(position);
}

void Creature::setDirection(sf::Vector2f newDirection)
{
	this->velocity = newDirection * 100.f;
}