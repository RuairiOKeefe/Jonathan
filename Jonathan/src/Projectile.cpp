#include "Projectile.h"

Projectile::Projectile()
{
}

Projectile::~Projectile()
{
}

void Projectile::MoveShot(float dt)
{
	sf::Vector2f vecAngle = sf::Vector2f(sin(angle * M_PI / 180), -cos(angle * M_PI / 180));
	sf::Vector2f move = sqrtf((vecAngle.x * vecAngle.x) + (vecAngle.y * vecAngle.y)) * vecAngle;
	Move(move * 100.0f * dt);
}

float Projectile::DealDamage()
{
	return 0.0f;
}

void Projectile::Update(float dt)
{
	MoveShot(dt);
}
