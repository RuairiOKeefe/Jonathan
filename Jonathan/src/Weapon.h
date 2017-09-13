#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Projectile.h"

class Weapon : public GameObject
{
public:
	Weapon();
	~Weapon();

	float fireRate;
	sf::Clock fireCD;
	Projectile shot;
	float speed;
	float damage;
	float angle;
	int shotNumber;
	bool playerShot = false;

	void Shoot(std::vector<Projectile>& projectileList, Projectile shot, sf::Vector2f shotOrigin, float inAngle);
	virtual void Update(float dt, float angle, sf::Vector2f shotOrigin, std::vector<Projectile>& projectileList) = 0;
};