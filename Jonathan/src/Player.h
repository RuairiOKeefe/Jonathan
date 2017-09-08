#pragma once
#include <SFML/Graphics.hpp>
#include "Ship.h"

class Player : public Ship
{
public:
	Player();
	~Player();

	Projectile shot = Projectile("res/img/BasicShot.png", 300, 5, true);

	void Update(float dt, std::vector<Projectile>& projectileList);
};