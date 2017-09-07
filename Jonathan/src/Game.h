#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Player.h"

class Game
{
public:
	Player player;//Use a collection later ofc
	std::vector<Projectile> projectileList;

	void Load();
	void Update();
	void Render(sf::RenderWindow &window);
private:

};
