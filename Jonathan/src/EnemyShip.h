#pragma once
#include <SFML/Graphics.hpp>
#include "Ship.h"

class EnemyShip : public Ship
{
public:
	EnemyShip();
	~EnemyShip();
	bool active;
	float value;

	float TurnTo(sf::Vector2f position);
	virtual void Update(float dt, std::vector<Projectile> &projectileList, sf::Vector2f target, float maxX, float maxY) { throw std::invalid_argument("Error: Inherited method has no Update method"); };
};