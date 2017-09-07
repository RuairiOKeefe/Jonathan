#include "Player.h"

void Player::Update(float dt, std::vector<GameObject>& projectileList)
{
	//This should be a virtual method, currently contains the player update while that is the only gameObject
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
	Move(move*300.0f*dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Shoot(projectileList, shot, this->sprite.getPosition() + shotOrigin);
	}
}
