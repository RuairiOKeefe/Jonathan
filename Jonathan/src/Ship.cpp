#include "stdafx.h"

#include "Ship.h"

Ship::Ship()
{
}

Ship::~Ship()
{
}

void Ship::TakeDamage(float damage)
{
	health -= damage;
	if (health <= 0.0f)
		despawn = true;
}