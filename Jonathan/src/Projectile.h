#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Projectile : public GameObject
{
public:
	float speed;

	void Move();
	void Update();
};