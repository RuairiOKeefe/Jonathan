#include "stdafx.h"

#include "Game.h"

float Game::GetMagnitude(sf::Vector2f input)
{
	return sqrt((input.x*input.x) + (input.y*input.y));
}

void Game::Load(float posX, float posY)
{
	if (!bgTexture.loadFromFile("../res/img/Space.png"))
	{
		throw std::invalid_argument("Error Loading Texture");
	}
	bgSprite1.setTexture(bgTexture);
	bgSprite2.setTexture(bgTexture);
	bgSprite1.setPosition(sf::Vector2f(0, posY));
	bgSprite2.setPosition(sf::Vector2f(0, -posY));
	player.SetPosition(sf::Vector2f(posX, posY));

	spawnClock.restart();
	powerUpSpawn = 5 * (wavesSpawned + 1);//Enemies till next spawn

	if (!font.loadFromFile("../res/fonts/ebrimabd.ttf"))
	{
		throw std::invalid_argument("Error Loading Font");
	}

	highscoreText.setFont(font);
	highscoreText.setString("Highscore: ");
	highscoreText.setPosition(sf::Vector2f(10.0f, 10.0f));
	scoreText.setFont(font);
	scoreText.setString("Score: ");
	scoreText.setPosition(sf::Vector2f(10.0f, 40.0f));
	healthText.setFont(font);
	healthText.setString("Health: ");
	healthText.setPosition(sf::Vector2f(posX, 10.0f));
}

void Game::Reset()
{
	hostileVec.clear();
	projectileVec.clear();
	powerUpVec.clear();
	player.health = player.maxHealth;
	player.level = 0;
	player.linearWeapon = Linear(1, 16, "../res/img/Shot1.png", 1000, 5, true, 0.25);
	player.angularWeapon = Angular(0, 90, "../res/img/Shot1.png", 500, 5, true, 0.5);
	deathCount = 0;
	wavesSpawned = 0;
	if (score > highscore)
		highscore = score;
	score = 0;
}

bool Game::Update(float maxX, float maxY, SFMLSoundProvider &soundProvider)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || sf::Joystick::isButtonPressed(0, 6))
	{
		return false;
	}
	static sf::Clock clock;
	float dt = clock.restart().asSeconds();
	std::vector<Projectile>::iterator shot = projectileVec.begin();
	while (shot != projectileVec.end())
	{
		shot->Update(dt, maxX, maxY);
		std::vector<EnemyShip*>::iterator ships = hostileVec.begin();
		while (ships != hostileVec.end())
		{
			if ((*ships)->active && (shot->playerShot && (GetMagnitude(shot->sprite.getPosition() - (*ships)->sprite.getPosition()) <= (shot->radius + (*ships)->radius))))
				(*ships)->TakeDamage(shot->CheckHit((*ships)->sprite));
			else
				if (!shot->playerShot && GetMagnitude(shot->sprite.getPosition() - player.sprite.getPosition()) <= (shot->radius + player.radius))
					player.TakeDamage(shot->CheckHit(player.sprite));
			ships++;
		}

		shot++;
	}

	for (std::vector<Projectile*>::size_type n = 0; n < projectileVec.size();)
	{
		if (projectileVec[n].despawn)
		{
			projectileVec[n].~Projectile();
			projectileVec.erase(projectileVec.begin() + n);
		}
		else
			n++;
	}
	projectileVec.shrink_to_fit();

	std::vector<EnemyShip*>::iterator ships = hostileVec.begin();
	while (ships != hostileVec.end())
	{
		(*ships)->Update(dt, projectileVec, player.sprite.getPosition(), maxX, maxY, soundProvider);
		ships++;
	}

	for (std::vector<EnemyShip*>::size_type n = 0; n < hostileVec.size();)
	{
		if (hostileVec[n]->despawn)
		{
			if (hostileVec[n]->value != 0)
			{
				soundProvider.PlaySound("../res/Audio/Paaaw.ogg");
				deathCount++;
				if (deathCount >= powerUpSpawn)
				{
					PowerUp* powerUp = new PowerUp(hostileVec[n]->sprite.getPosition());
					powerUpVec.push_back(powerUp);
					deathCount = 0;
					powerUpSpawn = 5 * (wavesSpawned + 1);
				}
			}
			score += hostileVec[n]->value;
			hostileVec[n]->~EnemyShip();
			hostileVec.erase(hostileVec.begin() + n);
		}
		else
			n++;
	}
	hostileVec.shrink_to_fit();

	std::vector<PowerUp*>::iterator powerUp = powerUpVec.begin();
	while (powerUp != powerUpVec.end())
	{
		(*powerUp)->Update();
		if (GetMagnitude((*powerUp)->sprite.getPosition() - player.sprite.getPosition()) <= ((*powerUp)->radius + player.radius))
		{
			if ((*powerUp)->CheckPickup(player.sprite))
			{
				player.Upgrade();
			}
		}
		powerUp++;
	}

	for (std::vector<PowerUp*>::size_type n = 0; n < powerUpVec.size();)
	{
		if (powerUpVec[n]->despawn)
		{
			powerUpVec[n]->~PowerUp();
			powerUpVec.erase(powerUpVec.begin() + n);
		}
		else
			n++;
	}
	powerUpVec.shrink_to_fit();

	player.Update(dt, projectileVec, maxX, maxY, soundProvider);

	if (spawnClock.getElapsedTime().asSeconds() >= 10.0f)
	{
		for (int i = 0; i < 2 * (wavesSpawned + 1); i++)
		{
			Strafer* strafer = new Strafer(sf::Vector2f(0.0f - (i * 40), 100 - (i * 8)), sf::Vector2f(1, 0.2f));
			hostileVec.push_back(strafer);
		}

		if (wavesSpawned > 0)
		{
			for (int i = -2 * wavesSpawned; i < 2 * wavesSpawned; i++)
			{
				Charger* charger = new Charger(sf::Vector2f((maxX / 2) + (i * 64), -64));
				hostileVec.push_back(charger);
			}
		}
		if (wavesSpawned > 1)
		{
			for (int i = 0; i < 2 * (wavesSpawned + 1); i++)
			{
				Strafer* strafer = new Strafer(sf::Vector2f(maxX + (i * 40), 100 - (i * 8)), sf::Vector2f(-1, 0.2f));
				hostileVec.push_back(strafer);
			}
		}

		if (wavesSpawned > 4)
		{
			for (int i = 0; i < (wavesSpawned - 4); i++)
			{
				float ranX = 16 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (maxX-32)));
				Pulser* pulser = new Pulser(sf::Vector2f((ranX), -64), sf::Vector2f(0, 1));
				hostileVec.push_back(pulser);
			}
		}

		spawnClock.restart();
		wavesSpawned++;
	}

	bgSprite1.move(sf::Vector2f(0, 1)*200.f*dt);
	bgSprite2.move(sf::Vector2f(0, 1)*200.f*dt);
	if (bgSprite1.getPosition().y >= maxY)
		bgSprite1.move(sf::Vector2f(0, -maxY * 2));
	if (bgSprite2.getPosition().y >= maxY)
		bgSprite2.move(sf::Vector2f(0, -maxY * 2));
	highscoreText.setString("Highscore: " + std::to_string(highscore));
	scoreText.setString("Score: " + std::to_string(score));
	healthText.setString("Health: " + std::to_string((int)player.health));

	if (player.health <= 0)
		return false;

	return true;
}

void Game::Render(sf::RenderWindow &window)
{
	window.draw(bgSprite1);
	window.draw(bgSprite2);
	std::vector<Projectile>::iterator shot = projectileVec.begin();
	while (shot != projectileVec.end())
	{
		window.draw(shot->sprite);
		shot++;
	}
	std::vector<PowerUp*>::iterator powerUp = powerUpVec.begin();
	while (powerUp != powerUpVec.end())
	{
		window.draw((*powerUp)->sprite);
		powerUp++;
	}
	window.draw(player.sprite);
	std::vector<EnemyShip*>::iterator ships = hostileVec.begin();
	while (ships != hostileVec.end())
	{
		window.draw((*ships)->sprite);
		ships++;
	}
	window.draw(highscoreText);
	window.draw(scoreText);
	window.draw(healthText);
}