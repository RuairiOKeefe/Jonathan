#pragma once
#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <math.h>

class Projectile : public GameObject
{
public:
	Projectile();
	Projectile(std::string location, float speed, float damage);
	Projectile(std::string location, float speed, float damage, bool playerShot);
	~Projectile();

	float speed;
	float damage;
	float angle;
	bool playerShot = false;
	bool despawn = false;

	void MoveShot(float dt);
	float CheckHit(sf::Sprite other);
	void Update(float dt);
};