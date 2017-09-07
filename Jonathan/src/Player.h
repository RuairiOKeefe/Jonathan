#pragma once
#include <SFML/Graphics.hpp>
#include "Ship.h"

class Player : public Ship
{
public:


	void Update(float dt, std::vector<GameObject>& projectileList);
};