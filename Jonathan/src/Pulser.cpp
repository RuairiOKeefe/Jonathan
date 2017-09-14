#include "stdafx.h"

#include "Pulser.h"

Pulser::Pulser()
{
	SetTexture("../res/img/Pulser.png");
	speed = 200.0f;
	direction = sf::Vector2f(0, 1);
	fireRate = 0.5f;
	maxHealth = 100;
	health = maxHealth;
	active = false;
	value = 100;
	angularWeapon = Angular(8, 360, "../res/img/Shot3.png", 300, 15, false, 3.0);
}

Pulser::Pulser(sf::Vector2f spawnPosition, sf::Vector2f moveDirection)
{
	SetTexture("../res/img/Pulser.png");
	sprite.setPosition(spawnPosition);
	direction = sqrtf((moveDirection.x * moveDirection.x) + (moveDirection.y * moveDirection.y)) * moveDirection;
	moveTime = 2.0f;
	stayTime = 3.0f;
	speed = 100.0f;
	fireRate = 0.5f;
	health = 100;
	active = false;
	value = 200;
	angularWeapon = Angular(8, 360, "../res/img/Shot3.png", 300, 15, false, 3.0);
}

Pulser::~Pulser()
{
}

void Pulser::Update(float dt, std::vector<Projectile>& projectileList, sf::Vector2f target, float maxX, float maxY, SFMLSoundProvider &soundProvider)
{
	if (active)
	{
		linearWeapon.Update(dt, this->sprite.getRotation(), sprite.getPosition(), projectileList, soundProvider);
		angularWeapon.Update(dt, this->sprite.getRotation(), sprite.getPosition(), projectileList, soundProvider);
	}
	if (move)
		Move(direction*speed*dt);
	if (move && moveClock.getElapsedTime().asSeconds() >= moveTime)
	{
		move = false;
		moveClock.restart();
	}
	if (!move && moveClock.getElapsedTime().asSeconds() >= stayTime)
	{
		move = true;
		moveClock.restart();
	}

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