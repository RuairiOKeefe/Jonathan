#include "Strafer.h"

Strafer::Strafer()
{
	SetTexture("res/img/Strafer.png");
	speed = 200.0f;
	fireRate = 0.5f;
	health = 5;
	active = false;
	value = 100;
	Linear basicWeapon = Linear(1, 1, "res/img/BasicShot.png", 300, 5, false, 0.5);
	linearVec.push_back(basicWeapon);
}

Strafer::Strafer(sf::Vector2f spawnPosition, sf::Vector2f moveDirection)
{
	SetTexture("res/img/Strafer.png");
	sprite.setPosition(spawnPosition);
	direction = sqrtf((moveDirection.x * moveDirection.x) + (moveDirection.y * moveDirection.y)) * moveDirection;
	speed = 200.0f;
	fireRate = 0.5f;
	health = 5;
	active = false;
	value = 100;
	Linear basicWeapon = Linear(1, 1, "res/img/BasicShot.png", 300, 5, false, 0.5);
	linearVec.push_back(basicWeapon);
}

Strafer::~Strafer()
{
}

void Strafer::Update(float dt, std::vector<Projectile>& projectileList, sf::Vector2f target, float maxX, float maxY)
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
			std::vector<Linear>::iterator l = linearVec.begin();
			while (l != linearVec.end())
			{
				l->Update(dt, this->sprite.getRotation(), sprite.getPosition(), projectileList);//Projectile returned is out of scope?
				l++;
			}
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
