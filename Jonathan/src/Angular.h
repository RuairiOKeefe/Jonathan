#pragma once
#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include "Weapon.h"
#include "Projectile.h"
#include <math.h>

class Angular : public Weapon
{
public:
	Angular();
	Angular(float shotNumber, float cone, std::string shotSprite, float speed, float damage, bool playerShot, float fireRate);
	~Angular();

	Projectile* shot = new Projectile();
	float cone;

	void Update(float dt, float angle, sf::Vector2f shotOrigin, std::vector<Projectile>& projectileList, SFMLSoundProvider &soundProvider);
};