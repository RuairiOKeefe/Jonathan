#include "Player.h"

Player::Player()
{
	SetTexture("res/img/ship.png");
	fireRate = 0.2f;
	speed = 500.0f;
	health = 100.0f;
}

Player::~Player()
{
	shot.~Projectile();
}

void Player::Update(float dt, std::vector<Projectile>& projectileList)
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
	Move(move*speed*dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && fireCD.getElapsedTime().asSeconds() >= fireRate)
	{
		Shoot(projectileList, shot, sprite.getPosition() + shotOrigin, this->sprite.getRotation());
		fireCD.restart();
	}
}
