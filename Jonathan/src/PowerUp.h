#pragma once
#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include <math.h>

class PowerUp : public GameObject
{
public:
	PowerUp();
	PowerUp(sf::Vector2f position);
	~PowerUp();

	sf::Clock despawnClock;
	float despawnTime;
	bool despawn = false;

	bool CheckPickup(sf::Sprite other);
	void Update();
};