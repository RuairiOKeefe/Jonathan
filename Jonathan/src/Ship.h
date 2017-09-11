#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Projectile.h"
#include "Weapon.h"
#include "Linear.h"

class Ship : public GameObject
{
public:
	Ship();
	~Ship();

	float fireRate;
	sf::Clock fireCD;
	std::vector<Weapon*> weaponVec;
	sf::Vector2f shotOrigin;
	float speed;
	float health;
	bool despawn = false;

	void TakeDamage(float damage);
	virtual void Update(float dt, std::vector<Projectile>& projectileList) { throw std::invalid_argument("Error: Inherited method has no Update method"); };
};