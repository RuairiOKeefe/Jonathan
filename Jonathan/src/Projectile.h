#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Projectile : public GameObject
{
public:
	Projectile();
	~Projectile();

	float speed;

	void MoveShot(float dt);
	//void CheckHit();
	float DealDamage();
	void Update(float dt);
};