#pragma once
#include <SFML/Graphics.hpp>
#include "EnemyShip.h"

class Pulser : public EnemyShip
{
public:
	Pulser();
	Pulser(sf::Vector2f spawnPosition, sf::Vector2f moveDirection);
	~Pulser();

	sf::Vector2f direction;
	bool move = true;
	sf::Clock moveClock;
	float moveTime;
	float stayTime;

	void Update(float dt, std::vector<Projectile>& projectileList, sf::Vector2f target, float maxX, float maxY, SFMLSoundProvider &soundProvider);
};