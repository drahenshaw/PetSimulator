#ifndef PETSIMULATOR_PHYSICS
#define PETSIMULATOR_PHYSICS

#include "Consumables.h"
#include "Creature.h"

class Physics
{
public:
	float Absolute(float x);
	bool isColliding(Creature & orc, Consumables & item);
};





#endif // !PETSIMULATOR_PHYSICS

