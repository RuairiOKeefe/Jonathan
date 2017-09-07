#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Projectile.h"

class Ship : public GameObject
{
public:
	Projectile shot;
	sf::Vector2f shotOrigin;

	void Shoot(std::vector<Projectile>& projectileList, Projectile shot, sf::Vector2f shotOrigin);
	virtual void Update(float dt, std::vector<Projectile>& projectileList) { throw std::invalid_argument("Error: Inherited method has no Update method"); };
};