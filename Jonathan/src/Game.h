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

	float GetMagnitude(sf::Vector2f input);
	void Load();
	void Update();
	void Render(sf::RenderWindow &window);
private:

};
