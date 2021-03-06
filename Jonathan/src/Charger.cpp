#include "stdafx.h"

#include "Charger.h"

Charger::Charger()
{
	SetTexture("../res/img/Charger.png");
	speed = 200.0f;
	fireRate = 0.5f;
	maxHealth = 10;
	health = maxHealth;
	active = false;
	value = 50;
	linearWeapon = Linear(1, 1, "../res/img/Shot1.png", 300, 5, false, 2.0);
}

Charger::Charger(sf::Vector2f spawnPosition)
{
	SetTexture("../res/img/Charger.png");
	sprite.setPosition(spawnPosition);
	speed = 200.0f;
	fireRate = 0.5f;
	health = 10;
	active = false;
	value = 50;
	linearWeapon = Linear(1, 1, "../res/img/Shot1.png", 300, 5, false, 2.0);
}

Charger::~Charger()
{
}

void Charger::Update(float dt, std::vector<Projectile>& projectileList, sf::Vector2f target, float maxX, float maxY, SFMLSoundProvider &soundProvider)
{
	sf::Vector2f targetVec = target - sprite.getPosition();
	float distance = sqrtf((targetVec.x * targetVec.x) + (targetVec.y * targetVec.y));
	targetVec = targetVec / distance;
	float targetAngle = (atan2(targetVec.x, -targetVec.y) * 180 / M_PI);
	sprite.rotate(targetAngle - sprite.getRotation());
	if (active)
	{
		if (distance < 150)
		{
			close = true;
			speed = 100.0f;
			if (distance < 50)
			{
				speed = -20.0f;
			}
		}
		else
		{
			close = false;
			speed = 200.0f;
		}
		if (close && !inMelee)
		{
			angularWeapon = Angular(12, 360, "../res/img/Shot2.png", 300, 10, false, 2.0);
			inMelee = true;
		}
		if (!close && inMelee)
		{
			angularWeapon = Angular(0, 360, "../res/img/Shot2.png", 300, 10, false, 2.0);
			inMelee = false;
		}
		linearWeapon.Update(dt, this->sprite.getRotation(), sprite.getPosition(), projectileList, soundProvider);
		angularWeapon.Update(dt, this->sprite.getRotation(), sprite.getPosition(), projectileList, soundProvider);
	}
	sf::Vector2f moveDir = target - sprite.getPosition();
	moveDir = moveDir / sqrtf((moveDir.x * moveDir.x) + (moveDir.y * moveDir.y));
	Move(speed * moveDir *dt);
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