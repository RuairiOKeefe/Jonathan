#include "stdafx.h"

#include "Strafer.h"

Strafer::Strafer()
{
	SetTexture("../res/img/Strafer.png");
	speed = 200.0f;
	fireRate = 0.5f;
	maxHealth = 20;
	health = maxHealth;
	active = false;
	value = 100;
	angularWeapon = Angular(2, 45, "../res/img/Shot2.png", 300, 10, false, 2.0);
}

Strafer::Strafer(sf::Vector2f spawnPosition, sf::Vector2f moveDirection)
{
	SetTexture("../res/img/Strafer.png");
	sprite.setPosition(spawnPosition);
	direction = sqrtf((moveDirection.x * moveDirection.x) + (moveDirection.y * moveDirection.y)) * moveDirection;
	speed = 200.0f;
	fireRate = 0.5f;
	health = 20;
	active = false;
	value = 100;
	angularWeapon = Angular(3, 45, "../res/img/Shot2.png", 300, 10, false, 4.0);
}

Strafer::~Strafer()
{
}

void Strafer::Update(float dt, std::vector<Projectile>& projectileList, sf::Vector2f target, float maxX, float maxY, SFMLSoundProvider &soundProvider)
{
	float turnAngle = TurnTo(target);
	if (turnAngle > 0.5f || turnAngle < -0.5f)
		sprite.rotate(turnAngle * 3.0f * dt);
	else
		sprite.rotate(turnAngle);
	if (active)
	{
		if (active)
		{
			linearWeapon.Update(dt, this->sprite.getRotation(), sprite.getPosition(), projectileList, soundProvider);
			angularWeapon.Update(dt, this->sprite.getRotation(), sprite.getPosition(), projectileList, soundProvider);
		}
	}
	Move(speed * direction * dt);
	if (active)
	{
		if (sprite.getPosition().x < -radius || sprite.getPosition().y < -radius || sprite.getPosition().x > maxX + radius || sprite.getPosition().y > maxX + radius)
		{
			value = 0;
			despawn = true;
		}
	}
	else
	{
		if (sprite.getPosition().x > 0 && sprite.getPosition().y > 0 && sprite.getPosition().x < maxX && sprite.getPosition().y < maxX)
		{
			active = true;
			fireCD.restart();
		}
	}
}
