#include "stdafx.h"

#include "GameObject.h"


GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::SetTexture(std::string location)
{
	if (!texture.loadFromFile(location))
	{
		throw std::invalid_argument("Error Loading Texture");
	}
	else
	{
		sprite.setTexture(texture);
	}
	sprite.setOrigin(sf::Vector2f(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f));
	radius = texture.getSize().x / 2.0f;
	if(radius < (texture.getSize().y / 2.0f))
		radius = texture.getSize().y / 2.0f;
}

void GameObject::ChangeScale(float scale)//Decide what the fuck we're doing with this at some point
{
	sprite.setScale(sf::Vector2f(scale, scale));
}

void GameObject::SetPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}

void GameObject::Move(sf::Vector2f move)
{
	sprite.move(move);
}