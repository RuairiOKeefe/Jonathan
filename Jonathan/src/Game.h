#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "SFMLSoundProvider.h"
#include "ServiceLocator.h"
#include "Player.h"
#include "EnemyShip.h"
#include "PowerUp.h"
#include "Strafer.h"
#include "Charger.h"

class Game
{
public:
	Player player;
	std::vector<EnemyShip*> hostileVec;
	std::vector<Projectile> projectileVec;
	std::vector<PowerUp*> powerUpVec;
	int deathCount;
	int powerUpSpawn;
	sf::Font scoreFont;
	sf::Text scoreText;
	int score;

	float GetMagnitude(sf::Vector2f input);
	void Load(float posX, float posY);
	void Update(float maxX, float maxY, SFMLSoundProvider &soundProvider);
	void Render(sf::RenderWindow &window);
private:

};
