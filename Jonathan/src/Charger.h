#pragma once
#include <SFML/Graphics.hpp>
#include "EnemyShip.h"

class Charger : public EnemyShip
{
public:
	Charger();
	Charger(sf::Vector2f spawnPosition);
	~Charger();

	bool close;
	bool inMelee;
	void Update(float dt, std::vector<Projectile>& projectileList, sf::Vector2f target, float maxX, float maxY, SFMLSoundProvider &soundProvider);
};