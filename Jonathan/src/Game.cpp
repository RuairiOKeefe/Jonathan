#include "Game.h"

float Game::GetMagnitude(sf::Vector2f input)
{
	return sqrt((input.x*input.x) + (input.y*input.y));
}

void Game::Load(float posX, float posY)
{
	//float xScale = 2;
	player.SetPosition(sf::Vector2f(posX, posY));
	for (int i = 0; i < 10; i++)
	{
		Strafer* strafer = new Strafer(sf::Vector2f(0.0f - (i * 40), 100 - (i * 8)), sf::Vector2f(1, 0.2f));
		hostileVec.push_back(strafer);
	}

	for (int i = -5; i < 5; i++)
	{
		Charger* charger = new Charger(sf::Vector2f(posX + (i * 64), -64));
		hostileVec.push_back(charger);
	}

	//for (int i = -5; i < 5; i++)
	//{
	//	PowerUp* powerUp = new PowerUp(sf::Vector2f(posX + (i * 64), 128));
	//	powerUpVec.push_back(powerUp);
	//}

	if (!scoreFont.loadFromFile("res/fonts/ebrimabd.ttf"))
	{
		throw std::invalid_argument("Error Loading Font");
	}
	scoreText.setFont(scoreFont);
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setPosition(sf::Vector2f(posX / 100, 0.0f));
}

void Game::Update(float maxX, float maxY)
{
	static sf::Clock clock;
	float dt = clock.restart().asSeconds();
	//player.sprite.rotate(dt*10.0f);
	std::vector<Projectile>::iterator shot = projectileVec.begin();//may need at least one hostile to have shots register
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
		(*ships)->Update(dt, projectileVec, player.sprite.getPosition(), maxX, maxY);
		ships++;
	}

	for (std::vector<EnemyShip*>::size_type n = 0; n < hostileVec.size();)
	{
		if (hostileVec[n]->despawn)
		{
			score += hostileVec[n]->value;
			hostileVec[n]->~EnemyShip();
			hostileVec.erase(hostileVec.begin() + n);
			if (hostileVec[n]->value != 0)
			{
				PowerUp* powerUp = new PowerUp(hostileVec[n]->sprite.getPosition());
				powerUpVec.push_back(powerUp);
			}
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

	player.Update(dt, projectileVec, maxX, maxY);

	scoreText.setString("Score: " + std::to_string(score));
}

void Game::Render(sf::RenderWindow &window)
{
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
	window.draw(scoreText);
}