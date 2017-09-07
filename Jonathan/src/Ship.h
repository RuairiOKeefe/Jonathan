#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Ship : public GameObject
{
public:
	GameObject shot;
	sf::Vector2f shotOrigin;

	void Shoot(std::vector<GameObject>& projectileList, GameObject shot, sf::Vector2f shotOrigin);
	virtual void Update() { throw std::invalid_argument("Error: Inherited method has no Update method"); };
};