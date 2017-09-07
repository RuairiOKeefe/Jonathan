#include "Ship.h"

void Ship::Shoot(std::vector<GameObject>& projectileList, GameObject shot, sf::Vector2f shotOrigin)
{
	shot.SetPosition(shotOrigin);
	projectileList.push_back(shot);
}
