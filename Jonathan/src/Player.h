#pragma once
#include <SFML/Graphics.hpp>
#include "Ship.h"

class Player : public Ship
{
public:
	Player();
	~Player();

	int level = 0;

	void Upgrade();
	void Update(float dt, std::vector<Projectile>& projectileList, float maxX, float maxY, SFMLSoundProvider &soundProvider);
};