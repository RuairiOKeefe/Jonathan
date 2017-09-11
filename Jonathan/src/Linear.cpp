#include "linear.h"

Linear::Linear()
{
}

Linear::Linear(float shotNumber, float spacing, std::string shotSprite, float speed, float damage, bool playerShot, float fireRate)
{
	this->shotNumber = shotNumber;
	this->spacing = spacing;
	shot = new Projectile(shotSprite, speed, damage, playerShot);
	this->fireRate = fireRate;
}

Linear::~Linear()
{
}

void Linear::Shoot(std::vector<Projectile>& projectileList, Projectile shot, sf::Vector2f shotOrigin, float inAngle)
{
	Projectile* newShot = new Projectile();
	newShot->sprite = shot.sprite;
	newShot->playerShot = shot.playerShot;
	newShot->speed = shot.speed;
	newShot->damage = shot.damage;
	newShot->radius = shot.radius;
	newShot->SetPosition(shotOrigin);
	newShot->sprite.setRotation(inAngle);
	newShot->angle = inAngle;
	projectileList.push_back(*newShot);
}

void Linear::Update(float dt, float angle, sf::Vector2f shotOrigin, std::vector<Projectile>& projectileList)
{
	if (fireCD.getElapsedTime().asSeconds() >= fireRate)
	{
		Shoot(projectileList, *shot, shotOrigin, angle);
		fireCD.restart();
	}
}
