#include "Ship.h"

void Ship::Shoot(std::vector<Projectile>& projectileList, Projectile shot, sf::Vector2f shotOrigin, float inAngle)
{
	Projectile* newShot = new Projectile();
	newShot->sprite = shot.sprite;
	newShot->SetPosition(shotOrigin);
	newShot->sprite.setRotation(inAngle);
	newShot->angle = inAngle;
	projectileList.push_back(*newShot);
}
