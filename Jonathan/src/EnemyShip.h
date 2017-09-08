#pragma once
#include <SFML/Graphics.hpp>
#include "Ship.h"

class EnemyShip : public Ship
{
public:

	void Update(float dt, std::vector<Projectile>& projectileList);
};