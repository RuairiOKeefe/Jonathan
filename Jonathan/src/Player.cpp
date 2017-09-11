#include "Player.h"

Player::Player()
{
	SetTexture("res/img/ship.png");
	fireRate = 0.2f;
	speed = 500.0f;
	health = 100.0f;
	Linear* basicWeapon = new Linear(1, 1, "res/img/BasicShot.png", 300, 5, true, 0.5);
	weaponVec.push_back(basicWeapon);
}

Player::~Player()
{
}

void Player::Update(float dt, std::vector<Projectile>& projectileList, float maxX, float maxY)
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
	move *= speed*dt;
	move.x = std::max((0.0f + radius) - sprite.getPosition().x, move.x);
	move.x = std::min((maxX - radius) - sprite.getPosition().x, move.x);
	move.y = std::max((0.0f + radius) - sprite.getPosition().y, move.y);
	move.y = std::min((maxY - radius) - sprite.getPosition().y, move.y);
	Move(move);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		std::vector<Weapon*>::iterator w = weaponVec.begin();
		while (w != weaponVec.end())
		{
			(*w)->Update(dt, this->sprite.getRotation(), sprite.getPosition(), projectileList);//Projectile returned is out of scope?
			w++;
		}
	}
}
