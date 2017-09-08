#pragma once
#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <math.h>

class Projectile : public GameObject
{
public:
	Projectile();
	~Projectile();

	float speed;
	float angle;

	void MoveShot(float dt);
	//void CheckHit();
	float DealDamage();
	void Update(float dt);
};