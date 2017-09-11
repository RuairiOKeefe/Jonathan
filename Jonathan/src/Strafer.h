#pragma once
#include <SFML/Graphics.hpp>
#include "EnemyShip.h"

class Strafer : public EnemyShip
{
public:
	Strafer();
	Strafer(sf::Vector2f spawnPosition, sf::Vector2f moveDirection);
	~Strafer();

	sf::Vector2f direction;

	void Update(float dt, std::vector<Projectile>& projectileList, sf::Vector2f target, float maxX, float maxY);
};