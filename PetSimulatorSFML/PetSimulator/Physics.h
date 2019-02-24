#ifndef PETSIMULATOR_PHYSICS
#define PETSIMULATOR_PHYSICS

#include "Consumables.h"
#include "Creature.h"

class Physics
{
public:
	static float Absolute(float x);
	static bool isColliding(Creature & orc, Consumables & item);
};





#endif // !PETSIMULATOR_PHYSICS

