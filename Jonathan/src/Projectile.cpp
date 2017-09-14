#include "stdafx.h"

#include "Projectile.h"

Projectile::Projectile()
{
}

Projectile::Projectile(std::string location, float speed, float damage)
{
	SetTexture(location);
	this->speed = speed;
	this->damage = damage;
	this->playerShot = false;
}

Projectile::Projectile(std::string location, float speed, float damage, bool playerShot)
{
	SetTexture(location);
	this->speed = speed;
	this->damage = damage;
	this->playerShot = playerShot;
}

Projectile::~Projectile()
{
}

void Projectile::MoveShot(float dt)
{
	sf::Vector2f vecAngle = sf::Vector2f(sin(angle * M_PI / 180), -cos(angle * M_PI / 180));
	sf::Vector2f move = sqrtf((vecAngle.x * vecAngle.x) + (vecAngle.y * vecAngle.y)) * vecAngle;
	Move(move * 500.0f * dt);
}

float Projectile::CheckHit(sf::Sprite other)
{
	if (sprite.getGlobalBounds().intersects(other.getGlobalBounds()))
	{
		despawn = true;
		return damage;
	}
	return 0;
}

void Projectile::Update(float dt, float maxX, float maxY)
{
	MoveShot(dt);
	if (sprite.getPosition().x < -radius || sprite.getPosition().y < -radius || sprite.getPosition().x > maxX + radius || sprite.getPosition().y > maxX + radius)
		despawn = true;
}