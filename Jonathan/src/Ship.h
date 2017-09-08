#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Projectile.h"

class Ship : public GameObject
{
public:
	Ship();
	~Ship();

	float fireRate;
	sf::Clock fireCD;
	Projectile shot;
	sf::Vector2f shotOrigin;
	float speed;
	float health;
	bool despawn = false;

	void TakeDamage(float damage);
	void Shoot(std::vector<Projectile>& projectileList, Projectile shot, sf::Vector2f shotOrigin, float inAngle);
	virtual void Update(float dt, std::vector<Projectile>& projectileList) { throw std::invalid_argument("Error: Inherited method has no Update method"); };
};