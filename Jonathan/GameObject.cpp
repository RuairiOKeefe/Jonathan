#include "GameObject.h"


GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::SetTexture(std::string location, float xScale)
	{
		if (!texture.loadFromFile(location))
		{
			throw std::invalid_argument("Error Loading Texture");
		}
		else
		{
			sprite.setTexture(texture);
			ChangeResolution(xScale);
		}
	}

	void GameObject::ChangeResolution(float xScale)
	{
		float yScale = xScale * (texture.getSize().y / texture.getSize().x);
		sprite.setScale(sf::Vector2f(xScale, yScale));
	}

	void GameObject::SetPosition(sf::Vector2f position)
	{
		sprite.setPosition(position);
	}

	void GameObject::Move(sf::Vector2f move)
	{
		sprite.move(move);
	}

	void GameObject::Update(float dt)
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
	}
