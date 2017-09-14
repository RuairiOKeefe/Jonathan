#include "stdafx.h"

#include "Linear.h"

Linear::Linear() : Weapon()
{
}

Linear::Linear(float shotNumber, float spacing, std::string shotSprite, float speed, float damage, bool playerShot, float fireRate) : Weapon()
{
	this->shotNumber = shotNumber;
	this->spacing = spacing;
	shot = new Projectile(shotSprite, speed, damage, playerShot);
	this->fireRate = fireRate;
}

Linear::~Linear()
{
}

void Linear::Update(float dt, float angle, sf::Vector2f shotOrigin, std::vector<Projectile>& projectileList, SFMLSoundProvider &soundProvider)
{
	float radAngle = angle / 180 * M_PI;
	sf::Vector2f angleVector = sf::Vector2f(cosf(radAngle), -sinf(radAngle));
	angleVector = sf::Vector2f(angleVector.x, -angleVector.y);
	angleVector = angleVector / sqrtf((angleVector.x * angleVector.x) + (angleVector.y * angleVector.y));
	if (fireCD.getElapsedTime().asSeconds() >= fireRate)
	{
		for (int i = 0; i < shotNumber; i++)
		{
			Shoot(projectileList, *shot, shotOrigin + (angleVector * spacing * (float)i) - (angleVector *(spacing * (shotNumber-1) / 2)), angle, soundProvider);
		}
		fireCD.restart();
	}
}