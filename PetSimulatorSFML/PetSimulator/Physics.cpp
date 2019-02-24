#include "Physics.h"


float Physics::Absolute(float x)
{
	return (x > 0 ? x : -x);
}

bool Physics::isColliding(Creature & orc, Consumables & item)
{
	return (Absolute(orc.getCreature().getPosition().x - item.getXReleased() < 30) && (Absolute(orc.getCreature().getPosition().y - item.getYReleased() < 30)));
}
