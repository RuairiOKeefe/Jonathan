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
	sf::Texture bgTexture;
	sf::Sprite bgSprite;
	sf::Clock spawnClock;
	int wavesSpawned;
	int deathCount;
	int powerUpSpawn;
	sf::Font font;
	sf::Text scoreText;
	sf::Text highscoreText;
	sf::Text healthText;
	int score;
	int highscore;

	float GetMagnitude(sf::Vector2f input);
	void Load(float posX, float posY);
	void Reset();
	bool Update(float maxX, float maxY, SFMLSoundProvider &soundProvider);
	void Render(sf::RenderWindow &window);
private:

};
