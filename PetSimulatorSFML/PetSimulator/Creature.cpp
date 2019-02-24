#include "Creature.h"
#include "Physics.h"
#include <time.h>

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

	

	this->position.x = 368;
	this->position.y = 268;
	this->creature.setPosition(position);
}

double Creature::getHealth()
{
	return this->health;
}
double Creature::getEnergy()
{
	return this->energy;
}
double Creature::getHunger()
{
	return this->hunger;
}
double Creature::getThirst()
{
	return this->thirst;
}
sf::Sprite & Creature::getCreature()
{
	return this->creature;
}

void Creature::setHealth(double hp)
{
	this->health = hp;
}
void Creature::setEnergy(double energy)
{
	this->energy = energy;
}
void Creature::setHunger(double hunger)
{
	this->hunger = hunger;
}
void Creature::setThirst(double thirst)
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
	srand(time(0));
	if (this->ticks == 120)
	{
		sf::Vector2f randDir;
		randDir.x = rand() % 1200;
		if (rand() % 2 == 0)
			randDir.x = -randDir.x;
		randDir.y = rand() % 800;
		if (rand() % 2 == 0)
			randDir.y = -randDir.y;
		setDirection(randDir);
	}
	//else
		//position += velocity * dT;
	
	
	animations_[int(currentAnimation)].Update(dT, 0);
	animations_[int(currentAnimation)].ApplyToSprite(creature);

	if (this->getCreature().getPosition().x <= -10){// || (this->getCreature().getPosition().x >= 800 /*|| this->getCreature().getPosition().x >= 725*/)) {
		this->velocity = -this->velocity;
		this->position.x = -this->position.x;
		
		//setDirection(this->getCreature().getPosition());
		//this->creature.setPosition(position / 60.f);
	}
	if (this->getCreature().getPosition().x >= 750) {
		//this->velocity = -this->velocity;
		//this->position.x = -this->position.x;
		sf::Vector2f randDir;
		randDir.x = rand() % 1200;
		//if (rand() % 2 == 0)
			randDir.x = -randDir.x;
		randDir.y = rand() % 800;
		if (rand() % 2 == 0)
			randDir.y = -randDir.y;
		setDirection(randDir);
	}
		
	 if (this->getCreature().getPosition().y <= -10){// || (this->getCreature().getPosition().y >= 600/* || this->getCreature().getPosition().y >= 425*/)) {
		 this->velocity = -this->velocity;
		 this->position.y = -this->position.y;
		 //setDirection(this->getCreature().getPosition());
		//this->creature.setPosition(position / 60.f);
	}
	 if (this->getCreature().getPosition().y >= 450) {
		 this->velocity = -this->velocity;
		// this->position.y = -this->position.y;
		 sf::Vector2f randDir;
		 randDir.x = rand() % 1200;
		 if (rand() % 2 == 0)
			 randDir.x = -randDir.x;
		 randDir.y = rand() % 800;
		 //if (rand() % 2 == 0)
			 randDir.y = -randDir.y;
		 setDirection(randDir);
	 }
	//else
	 position += velocity * dT;

	 if (this->velocity.x < 0)
		 this->currentAnimation = Animation::AnimationIndex::WALKING_LEFT;
	 if (this->velocity.x > 0)
		 this->currentAnimation = Animation::AnimationIndex::WALKING_RIGHT;
	 if (this->velocity.y > 0 && Physics::Absolute(this->velocity.x) < (Physics::Absolute(this->velocity.y)))
		 this->currentAnimation = Animation::AnimationIndex::WALKING_DOWN;
	 if (this->velocity.y < 0 && Physics::Absolute(this->velocity.x) < (Physics::Absolute(this->velocity.y)))
		 this->currentAnimation = Animation::AnimationIndex::WALKING_UP;
	
	 
	this->creature.setPosition(position/100.f);
}

void Creature::setDirection(sf::Vector2f newDirection)
{
	//if (this->creature.getPosition().x <= 0 || this->creature.getPosition().x >= 550)
	//	this->velocity = newDirection * -50.f;
	//else
		this->velocity = newDirection * 10.f;

	/*if (this->creature.getPosition().y <= 0 || this->creature.getPosition().y >= 650)
		this->velocity = newDirection * -50.f;
	else
		this->velocity = newDirection * 50.f;*/
}

sf::Vector2f Creature::getvelocity()
{
	return this->velocity;
}