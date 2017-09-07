#include "Projectile.h"

Projectile::Projectile()
{
}

Projectile::~Projectile()
{
}

void Projectile::MoveShot(float dt)
{
	sf::Vector2f move = sf::Vector2f(0.0f, -1.0f);
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
