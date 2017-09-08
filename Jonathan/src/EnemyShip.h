#pragma once
#include <SFML/Graphics.hpp>
#include "Ship.h"

class EnemyShip : public Ship
{
public:
	EnemyShip();
	~EnemyShip();

	float TurnTo(sf::Vector2f position);
	virtual void Update(float dt, std::vector<Projectile>& projectileList, sf::Vector2f target) { throw std::invalid_argument("Error: Inherited method has no Update method"); };
};