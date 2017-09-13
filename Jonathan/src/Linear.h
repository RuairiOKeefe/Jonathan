#pragma once
#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include "Weapon.h"
#include "Projectile.h"
#include <math.h>

class Linear : public Weapon
{
public:
	Linear();
	Linear(float shotNumber, float spacing, std::string shotSprite, float speed, float damage, bool playerShot, float fireRate);
	~Linear();

	Projectile* shot = new Projectile();
	float spacing;

	void Update(float dt, float angle, sf::Vector2f shotOrigin, std::vector<Projectile>& projectileList);
};