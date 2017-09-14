#include "stdafx.h"

#include "PowerUp.h"

PowerUp::PowerUp()
{
}

PowerUp::PowerUp(sf::Vector2f position)
{
	SetTexture("../res/img/PowerUp.png");
	this->SetPosition(position);
	this->despawnTime = 10.0f;
}

PowerUp::~PowerUp()
{
}

bool PowerUp::CheckPickup(sf::Sprite other)
{
	if (sprite.getGlobalBounds().intersects(other.getGlobalBounds()))
	{
		despawn = true;
		return true;
	}
	return false;
}

void PowerUp::Update()
{
	if (despawnClock.getElapsedTime().asSeconds() >= despawnTime)
		despawn = true;
}