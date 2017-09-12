#include "Charger.h"

Charger::Charger()
{
	SetTexture("res/img/Charger.png");
	speed = 200.0f;
	fireRate = 0.5f;
	health = 5;
	active = false;
	value = 100;
	Linear basicWeapon = Linear(1, 1, "res/img/BasicShot.png", 300, 5, false , 0.5);
	linearVec.push_back(basicWeapon);
}

Charger::Charger(sf::Vector2f spawnPosition)
{
	SetTexture("res/img/Charger.png");
	sprite.setPosition(spawnPosition);
	speed = 200.0f;
	fireRate = 0.5f;
	health = 5;
	active = false;
	value = 100;
	Linear basicWeapon = Linear(1, 1, "res/img/BasicShot.png", 300, 5, false, 0.5);
	linearVec.push_back(basicWeapon);
}

Charger::~Charger()
{
}

void Charger::Update(float dt, std::vector<Projectile>& projectileList, sf::Vector2f target, float maxX, float maxY)
{
	sf::Vector2f targetVec = target - sprite.getPosition();
	targetVec = targetVec / sqrtf((targetVec.x * targetVec.x) + (targetVec.y * targetVec.y));
	float targetAngle = (atan2(targetVec.x, -targetVec.y) * 180 / M_PI);
	sprite.rotate(targetAngle - sprite.getRotation());
	if (active)
	{
		std::vector<Linear>::iterator l = linearVec.begin();
		while (l != linearVec.end())
		{
			l->Update(dt, this->sprite.getRotation(), sprite.getPosition(), projectileList);//Projectile returned is out of scope?
			l++;
		}
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