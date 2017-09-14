#include "stdafx.h"

#include "Player.h"

Player::Player()
{
	SetTexture("res/img/ship.png");
	fireRate = 0.2f;
	speed = 500.0f;
	health = 100.0f;
	linearWeapon = Linear(1, 16, "res/img/Shot1.png", 1000, 5, true, 0.25);
	angularWeapon = Angular(0, 90, "res/img/Shot1.png", 500, 5, true, 0.5);
}

Player::~Player()
{
}

void Player::Upgrade()
{
	level = level++;
	if (level > 10)
		level = 10;
	switch (level)
	{
	case 1:
		linearWeapon = Linear(2, 16, "res/img/Shot1.png", 1000, 5, true, 0.25);
		angularWeapon = Angular(0, 90, "res/img/Shot1.png", 500, 5, true, 0.5);
		break;
	case 2:
		linearWeapon = Linear(2, 16, "res/img/Shot2.png", 1000, 10, true, 0.25);
		angularWeapon = Angular(0, 90, "res/img/Shot1.png", 500, 5, true, 0.5);
		break;
	case 3:
		linearWeapon = Linear(2, 16, "res/img/Shot2.png", 1000, 10, true, 0.25);
		angularWeapon = Angular(2, 90, "res/img/Shot1.png", 500, 5, true, 0.5);
		break;
	case 4:
		linearWeapon = Linear(2, 16, "res/img/Shot2.png", 1000, 10, true, 0.25);
		angularWeapon = Angular(4, 135, "res/img/Shot1.png", 500, 5, true, 0.5);
		break;
	case 5:
		linearWeapon = Linear(2, 16, "res/img/Shot2.png", 1000, 10, true, 0.25);
		angularWeapon = Angular(4, 135, "res/img/Shot2.png", 500, 10, true, 0.5);
		break;
	case 6:
		linearWeapon = Linear(3, 16, "res/img/Shot3.png", 1000, 15, true, 0.25);
		angularWeapon = Angular(4, 135, "res/img/Shot2.png", 500, 10, true, 0.5);
		break;
	case 7:
		linearWeapon = Linear(3, 16, "res/img/Shot3.png", 1000, 15, true, 0.25);
		angularWeapon = Angular(4, 135, "res/img/Shot3.png", 500, 15, true, 0.5);
		break;
	case 8:
		linearWeapon = Linear(3, 16, "res/img/Shot3.png", 1000, 15, true, 0.25);
		angularWeapon = Angular(6, 180, "res/img/Shot3.png", 500, 15, true, 0.5);
		break;
	case 9:
		linearWeapon = Linear(4, 16, "res/img/Shot4.png", 2000, 20, true, 0.25);
		angularWeapon = Angular(6, 180, "res/img/Shot3.png", 500, 15, true, 0.5);
		break;
	case 10:
		linearWeapon = Linear(4, 16, "res/img/Shot4.png", 2000, 20, true, 0.25);
		angularWeapon = Angular(10, 270, "res/img/Shot4.png", 500, 20, true, 0.5);
		break;
	}
}

void Player::Update(float dt, std::vector<Projectile>& projectileList, float maxX, float maxY, SFMLSoundProvider &soundProvider)
{
	sf::Vector2f move;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		move.y--;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		move.y++;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		move.x--;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		move.x++;
	}
	if (sf::Joystick::isConnected(0))
	{
		float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
		if (x > 20 || x < -20)
			move.x += x * 100;
		float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
		if (y > 20 || y < -20)
			move.y = y * 100;
	}

	float moveMagnitude = sqrt((move.x*move.x) + (move.y*move.y));
	if (moveMagnitude > 1.0f)
		move /= moveMagnitude;

	move *= speed*dt;
	move.x = std::max((0.0f + radius) - sprite.getPosition().x, move.x);
	move.x = std::min((maxX - radius) - sprite.getPosition().x, move.x);
	move.y = std::max((0.0f + radius) - sprite.getPosition().y, move.y);
	move.y = std::min((maxY - radius) - sprite.getPosition().y, move.y);
	Move(move);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || (sf::Joystick::isConnected(0) && sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z) < -20))
	{
		linearWeapon.Update(dt, this->sprite.getRotation(), sprite.getPosition(), projectileList, soundProvider);
		angularWeapon.Update(dt, this->sprite.getRotation(), sprite.getPosition(), projectileList, soundProvider);
	}
}