#pragma once
#include <SFML/Graphics.hpp>
#include "EnemyShip.h"

class Strafer : public EnemyShip
{
public:
	Strafer();
	~Strafer();

	void Update(float dt, std::vector<Projectile>& projectileList);
};