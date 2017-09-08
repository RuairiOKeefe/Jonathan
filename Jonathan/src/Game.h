#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Player.h"
#include "EnemyShip.h"
#include "Strafer.h"

class Game
{
public:
	Player player;
	std::vector<EnemyShip*> hostileVec;
	std::vector<Projectile> projectileVec;

	void Load();
	void Update();
	void Render(sf::RenderWindow &window);
private:

};
