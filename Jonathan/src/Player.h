#pragma once
#include <SFML/Graphics.hpp>
#include "Ship.h"

class Player : public Ship
{
public:
	float fireRate;
	sf::Clock fireCD;

	void Update(float dt, std::vector<Projectile>& projectileList);
};