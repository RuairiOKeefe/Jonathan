#include "Ship.h"

void Ship::Shoot(std::vector<Projectile>& projectileList, Projectile shot, sf::Vector2f shotOrigin)
{
	Projectile* newShot = new Projectile();
	newShot->sprite = shot.sprite;
	newShot->SetPosition(shotOrigin);
	projectileList.push_back(*newShot);
}
