#include "Ship.h"

Ship::Ship()
{
}

Ship::~Ship()
{
}

void Ship::TakeDamage(float damage)
{
	health -= damage;
	if (health <= 0.0f)
		despawn = true;
}

void Ship::Shoot(std::vector<Projectile>& projectileList, Projectile shot, sf::Vector2f shotOrigin, float inAngle)
{
	Projectile* newShot = new Projectile();
	newShot->sprite = shot.sprite;
	newShot->playerShot = shot.playerShot;
	newShot->speed = shot.speed;
	newShot->damage = shot.damage;
	newShot->SetPosition(shotOrigin);
	newShot->sprite.setRotation(inAngle);
	newShot->angle = inAngle;
	projectileList.push_back(*newShot);
}
