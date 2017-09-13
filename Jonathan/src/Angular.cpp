#include "Angular.h"

Angular::Angular()
{
}

Angular::Angular(float shotNumber, float cone, std::string shotSprite, float speed, float damage, bool playerShot, float fireRate)
{
	this->shotNumber = shotNumber;
	this->cone = cone;
	shot = new Projectile(shotSprite, speed, damage, playerShot);
	this->fireRate = fireRate;
}

Angular::~Angular()
{
}

void Angular::Update(float dt, float angle, sf::Vector2f shotOrigin, std::vector<Projectile>& projectileList)
{
	if (fireCD.getElapsedTime().asSeconds() >= fireRate)
	{
		for (int i = 0; i < shotNumber; i++)
		{
			Shoot(projectileList, *shot, shotOrigin, angle - (cone / 2) + ((cone / (shotNumber-1)) * i));
		}
		fireCD.restart();
	}
}
