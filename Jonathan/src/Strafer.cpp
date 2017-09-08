#include "Strafer.h"

Strafer::Strafer()
{
	SetTexture("res/img/Strafer.png");
	speed = 300.0f;
	fireRate = 0.5f;
	health = 5;
}

Strafer::Strafer(sf::Vector2f spawnPosition, sf::Vector2f moveDirection)
{
	SetTexture("res/img/Strafer.png");
	sprite.setPosition(spawnPosition);
	direction = sqrtf((moveDirection.x * moveDirection.x) + (moveDirection.y * moveDirection.y)) * moveDirection;
	speed =  100.0f;
	fireRate = 0.5f;
	health = 5;
}

Strafer::~Strafer()
{
}

void Strafer::Update(float dt, std::vector<Projectile>& projectileList, sf::Vector2f target)
{
	float turnAngle = TurnTo(target);
	if(turnAngle > 0.1f || turnAngle < -0.1f)
		sprite.rotate(turnAngle * 2.0f * dt);
	else
		sprite.rotate(turnAngle);
	if (fireCD.getElapsedTime().asSeconds() >= fireRate)
	{
		Shoot(projectileList, shot, sprite.getPosition() + shotOrigin, this->sprite.getRotation());
		fireCD.restart();
	}
	Move(speed * direction * dt);
}
