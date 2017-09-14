#include "stdafx.h"

#include "Weapon.h"

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
}

void Weapon::Shoot(std::vector<Projectile>& projectileList, Projectile shot, sf::Vector2f shotOrigin, float inAngle, SFMLSoundProvider &soundProvider)
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
	soundProvider.PlaySound("res/Audio/Buchew.ogg");
}