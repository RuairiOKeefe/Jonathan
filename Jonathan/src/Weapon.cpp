#include "Weapon.h"

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

void Weapon::Shoot(std::vector<Projectile>& projectileList, Projectile shot, sf::Vector2f shotOrigin, float inAngle)
{
	Projectile* newShot = new Projectile();
	newShot->SetTexture("res/img/BasicShot.png");
	newShot->playerShot = shot.playerShot;
	newShot->speed = shot.speed;
	newShot->damage = shot.damage;
	newShot->radius = shot.radius;
	newShot->SetPosition(shotOrigin);
	newShot->sprite.setRotation(inAngle);
	newShot->angle = inAngle;
	projectileList.push_back(*newShot);
}